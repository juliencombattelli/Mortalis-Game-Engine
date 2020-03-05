#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <array>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

namespace mul {
namespace sfe {

struct Vector2i {
    int x, y;
};

using MinitileArray = std::array<sf::IntRect, 4>;

class AutotilerVXAce {
public:
    static MinitileArray generateTile(int tileId, const sf::Vector2i& autotileTopLeftCorner = { 0, 0 })
    {
        std::array<sf::IntRect, 4> minitiles {};

        for (int i = 0; i < 4; i++)
            minitiles[i] = sf::IntRect {
                (m_minitilesMaps[tileId][i] % 4) * 16 + autotileTopLeftCorner.x,
                (m_minitilesMaps[tileId][i] / 4) * 16 + autotileTopLeftCorner.y,
                16, 16
            };

        return minitiles;
    }

private:
    static constexpr int m_minitilesMaps[48][4] = {
        { 18, 17, 14, 13 }, // borderNone
        { 8, 11, 20, 23 },  // borderAll
        { 9, 10, 13, 14 },  // borderTop
        { 17, 18, 21, 22 }, // borderBottom
        { 12, 13, 16, 17 }, // borderLeft
        { 14, 15, 18, 19 }, // borderRight
        { 16, 19, 20, 23 }, // borderNoTop
        { 8, 11, 12, 15 },  // borderNoBottom
        { 10, 11, 22, 23 }, // borderNoLeft
        { 8, 9, 20, 21 },   // borderNoRight
        { 10, 9, 22, 21 },  // borderHorizontal
        { 16, 19, 12, 15 }, // borderVertical
        { 8, 9, 12, 13 },   // borderTopLeft
        { 10, 11, 14, 15 }, // borderTopRight
        { 18, 19, 22, 23 }, // borderBottomRigth
        { 16, 17, 20, 21 }, // borderBottomLeft
        { 7, 6, 3, 2 },     // cornerCenter
        { 2, 3, 6, 7 },     // cornerAll
        { 2, 3, 14, 13 },   // cornerTop
        { 18, 17, 6, 7 },   // cornerBottom
        { 2, 17, 6, 13 },   // cornerLeft
        { 18, 3, 14, 7 },   // cornerRight
        { 18, 3, 6, 7 },    // cornerNoTopLeft
        { 2, 3, 6, 13 },    // cornerNoBottomLeft
        { 2, 3, 14, 7 },    // cornerNoTopRight
        { 2, 17, 6, 7 },    // cornerNoBottomRight
        { 2, 17, 14, 7 },   // cornerFirstDiag
        { 18, 3, 6, 13 },   // cornerSecondDiag
        { 2, 17, 14, 13 },  // cornerTopLeft
        { 18, 3, 14, 13 },  // cornerTopRight
        { 18, 17, 14, 7 },  // cornerBottomRigth
        { 18, 17, 6, 13 },  // cornerBottomLeft
        { 2, 19, 22, 23 },  // turnTopLeft
        { 16, 3, 20, 21 },  // turnTopRight
        { 10, 11, 6, 15 },  // turnBottomLeft
        { 8, 9, 12, 7 },    // turnBottomRight
        { 2, 19, 14, 15 },  // borderRightCornerTopLeft
        { 2, 17, 22, 21 },  // borderBottomCornerTopLeft
        { 16, 3, 12, 13 },  // borderLeftCornerTopRight
        { 18, 3, 22, 21 },  // borderBottomCornerTopRight
        { 16, 17, 12, 7 },  // borderLeftCornerBottomRight
        { 10, 9, 14, 7 },   // borderTopCornerBottomRight
        { 18, 19, 6, 15 },  // borderRightCornerBottomLeft
        { 10, 9, 6, 13 },   // borderTopCornerBottomLeft
        { 10, 9, 6, 7 },    // borderTopCornerBottom
        { 2, 3, 22, 1 },    // borderBottomCornerTop
        { 16, 3, 12, 7 },   // borderLeftCornerRight
        { 2, 19, 6, 15 }    // borderRightCornerLeft
    };
};

std::array<sf::Sprite, 4> generateSprites(
    const sf::Texture& texture,
    const MinitileArray& minitiles,
    Vector2i position)
{
    std::array<sf::Sprite, 4> sprites {};
    for (int i = 0; i < 4; i++) {
        sprites[i] = sf::Sprite(texture, minitiles[i]);
        sprites[i].setPosition(position.x + (i % 2) * 16, position.y + (i / 2) * 16);
    }
    return sprites;
}

} // namespace sfe
} // namespace mul

template <sf::PrimitiveType type>
class Drawable {
    static constexpr auto primitiveType = type;
    std::vector<sf::Vertex> vertices;
    int textureid;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "EntityX Example", sf::Style::Fullscreen);

    sf::Texture texture;
    if (not texture.loadFromFile("World_A2.png")) {
        std::cerr << "World_A2.png not found\n";
        return 1;
    }

    sf::Sprite sprite(texture);

    const auto minitiles = mul::sfe::AutotilerVXAce::generateTile(35);
    const auto autosprites = mul::sfe::generateSprites(texture, minitiles, { 32, 32 });

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
            case sf::Event::KeyPressed:
                window.close();
                break;

            default:
                break;
            }
        }

        window.clear();
        sf::Time elapsed = clock.restart();
        for (auto s : autosprites)
            window.draw(s);
        window.display();
    }

    return sizeof(Drawable<sf::Quads>);
}