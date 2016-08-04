#include <MGE/Input/Keyboard/Keyboard.hpp>
#include <fstream>
#include <utility>

namespace mge
{

const Action2StringBimap Keyboard::action2stringBimap(
{
	{Action::pause		,"pause"					},
	{Action::accept		,"accept"					},
	{Action::refuse		,"refuse"					},
	{Action::moveUp		,"moveUp"					},
	{Action::moveDown	,"moveDown"					},
	{Action::moveLeft	,"moveLeft"					},
	{Action::moveRight	,"moveRight"				}
});

const String2KeyBimap Keyboard::string2keyBimap(
{
    {"A"				,sf::Keyboard::A			},
    {"B"				,sf::Keyboard::B			},
    {"C"				,sf::Keyboard::C			},
    {"D"				,sf::Keyboard::D			},
    {"E"				,sf::Keyboard::E			},
    {"F"				,sf::Keyboard::F			},
    {"G"				,sf::Keyboard::G			},
    {"H"				,sf::Keyboard::H			},
    {"I"				,sf::Keyboard::I			},
    {"J"				,sf::Keyboard::J			},
    {"K"				,sf::Keyboard::K			},
    {"L"				,sf::Keyboard::L			},
    {"M"				,sf::Keyboard::M			},
    {"N"				,sf::Keyboard::N			},
    {"O"				,sf::Keyboard::O			},
    {"P"				,sf::Keyboard::P			},
    {"Q"				,sf::Keyboard::Q			},
    {"R"				,sf::Keyboard::R			},
    {"S"				,sf::Keyboard::S			},
    {"T"				,sf::Keyboard::T			},
    {"U"				,sf::Keyboard::U			},
    {"V"				,sf::Keyboard::V			},
    {"W"				,sf::Keyboard::W			},
    {"X"				,sf::Keyboard::X			},
    {"Y"				,sf::Keyboard::Y			},
    {"Z"				,sf::Keyboard::Z			},
    {"Num0"				,sf::Keyboard::Num0			},
    {"Num1"				,sf::Keyboard::Num1			},
    {"Num2"				,sf::Keyboard::Num2			},
    {"Num3"				,sf::Keyboard::Num3			},
    {"Num4"				,sf::Keyboard::Num4			},
    {"Num5"				,sf::Keyboard::Num5			},
    {"Num6"      		,sf::Keyboard::Num6			},
    {"Num7"     		,sf::Keyboard::Num7			},
    {"Num8"				,sf::Keyboard::Num8			},
    {"Num9"				,sf::Keyboard::Num9			},
    {"Escape"			,sf::Keyboard::Escape		},
    {"LControl"			,sf::Keyboard::LControl		},
    {"LShift"			,sf::Keyboard::LShift		},
    {"LAlt"				,sf::Keyboard::LAlt			},
    {"LSystem"			,sf::Keyboard::LSystem		},
    {"RControl"			,sf::Keyboard::RControl		},
    {"RShift"			,sf::Keyboard::RShift		},
    {"RAlt"				,sf::Keyboard::RAlt			},
    {"RSystem"			,sf::Keyboard::RSystem		},
    {"Menu"				,sf::Keyboard::Menu			},
    {"LBracket"			,sf::Keyboard::LBracket		},
    {"RBracket"			,sf::Keyboard::RBracket		},
    {"SemiColon"		,sf::Keyboard::SemiColon	},
    {"Comma"			,sf::Keyboard::Comma		},
    {"Period"			,sf::Keyboard::Period		},
    {"Quote"			,sf::Keyboard::Quote		},
    {"Slash"			,sf::Keyboard::Slash		},
    {"BackSlash"		,sf::Keyboard::BackSlash	},
    {"Tilde"			,sf::Keyboard::Tilde		},
    {"Equal"			,sf::Keyboard::Equal		},
    {"Dash"				,sf::Keyboard::Dash			},
    {"Space"			,sf::Keyboard::Space		},
    {"Return"			,sf::Keyboard::Return		},
    {"BackSpace"		,sf::Keyboard::BackSpace	},
    {"Tab"				,sf::Keyboard::Tab			},
    {"PageUp"			,sf::Keyboard::PageUp		},
    {"PageDown"			,sf::Keyboard::PageDown		},
    {"Home"				,sf::Keyboard::Home			},
    {"Insert"			,sf::Keyboard::Insert		},
    {"Delete"			,sf::Keyboard::Delete		},
    {"Subtract"			,sf::Keyboard::Subtract		},
    {"Multiply"			,sf::Keyboard::Multiply		},
    {"Divide"			,sf::Keyboard::Divide		},
    {"Left"				,sf::Keyboard::Left			},
    {"Right"			,sf::Keyboard::Right		},
    {"Up"				,sf::Keyboard::Up			},
    {"Down"				,sf::Keyboard::Down			},
    {"Numpad0"			,sf::Keyboard::Numpad0		},
    {"Numpad1"			,sf::Keyboard::Numpad1		},
    {"Numpad2"			,sf::Keyboard::Numpad2		},
    {"Numpad3"			,sf::Keyboard::Numpad3		},
    {"Numpad4"			,sf::Keyboard::Numpad4		},
    {"Numpad5"			,sf::Keyboard::Numpad5		},
    {"Numpad6"			,sf::Keyboard::Numpad6		},
    {"Numpad7"			,sf::Keyboard::Numpad7		},
    {"Numpad8"			,sf::Keyboard::Numpad8		},
    {"Numpad9"			,sf::Keyboard::Numpad9		},
    {"F1"				,sf::Keyboard::F1			},
    {"F2"				,sf::Keyboard::F2			},
    {"F3"				,sf::Keyboard::F3			},
    {"F4"				,sf::Keyboard::F4			},
    {"F5"				,sf::Keyboard::F5			},
    {"F6"				,sf::Keyboard::F6			},
    {"F7"				,sf::Keyboard::F7			},
    {"F8"				,sf::Keyboard::F8			},
    {"F9"				,sf::Keyboard::F9			},
    {"F10"				,sf::Keyboard::F10			},
    {"F11"				,sf::Keyboard::F11			},
    {"F12"				,sf::Keyboard::F12			},
    {"F13"				,sf::Keyboard::F13			},
    {"F14"				,sf::Keyboard::F14			},
    {"F15"				,sf::Keyboard::F15			},
    {"Pause"			,sf::Keyboard::Pause		}
});

const ActionKeyBinding Keyboard::defaultActionKeyBinding(
{
	{Action::pause		,sf::Keyboard::P			},
	{Action::accept		,sf::Keyboard::Return		},
	{Action::refuse		,sf::Keyboard::Escape		},
	{Action::moveUp		,sf::Keyboard::Numpad8		},
	{Action::moveDown	,sf::Keyboard::Numpad5		},
	{Action::moveLeft	,sf::Keyboard::Numpad4		},
	{Action::moveRight	,sf::Keyboard::Numpad6		}
});

Keyboard::Keyboard() :
		m_DPad(directionalActions)
{
	for(auto actionKey : defaultActionKeyBinding)
		m_actionMap[actionKey.first] = KeyManager(*actionKey.second);
}

Keyboard::~Keyboard()
{

}

void Keyboard::changeActionKey(Action action, sf::Keyboard::Key newCode)
{
	// TODO : use find instead of operator[]
	m_actionMap[action].changeKeyCode(newCode);
}

void Keyboard::update()
{
	for(auto& it : m_actionMap)
		it.second.update();

	std::map<Action,bool> mapForUpdate;

	for(auto& action : directionalActions)
		mapForUpdate[action] = isKeyPressed(action);

    m_DPad.update(mapForUpdate);
}

} // namespace mge
