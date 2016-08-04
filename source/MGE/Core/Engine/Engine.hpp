//============================================================================
// Name        : Engine.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 2 juil. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <MGE/Config/CompilerConfig.hpp>
#include <MGE/Core/Scene/SceneManager.hpp>
#include <MGE/Core/Status/Status.hpp>
#include <MGE/Resource/ResourceManager.hpp>
#include <MGE/Input/KeyboardAPI.hpp>

#include <MUL/Event/Event.hpp>

#include <SFML/Graphics.hpp>

namespace mge
{

class IState;

class Engine : mul::Receiver
{
public:

	Engine();
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
    ~Engine();

    bool isRunning() const { return m_isRunning; }
    void quit(mul::Sender& sender, const mul::Event& event);
    Status run();

    void openErrorWindow(Status status, const std::string& errorMessage);

private:

    void init();
    void handleEvent(Scene& scene);
    void gameLoop();
    void cleanup();

    void quit(Status status);

    ResourceManager m_resourceManager;
    SceneManager m_sceneManager;
    Keyboard m_keyboard;

    bool m_isRunning;
    Status m_exitStatus;
    sf::RenderWindow m_window;
};

} // namespace mge

#endif // ENGINE_HPP_
