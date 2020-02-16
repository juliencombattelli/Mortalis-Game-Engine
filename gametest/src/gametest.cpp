#include <SFML/Graphics.hpp>

constexpr auto defaultWindowWidth = 200;
constexpr auto defaultWindowHeight = 200;
constexpr auto defaultCircleRadius = 100.F;

int main()
{
    sf::RenderWindow window(sf::VideoMode(defaultWindowWidth, defaultWindowHeight), "SFML works!");
    sf::CircleShape shape(defaultCircleRadius);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event {};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}