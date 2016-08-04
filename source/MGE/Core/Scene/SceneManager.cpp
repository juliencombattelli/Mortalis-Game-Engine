#include <MGE/Core/Scene/Scene.hpp>
#include <MGE/Core/Scene/SceneManager.hpp>
#include <MGE/Config/SceneConfig.hpp>

namespace mge
{

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{
	cleanup();
}

void SceneManager::init(ResourceManager& resourceManager)
{
	push<InitialScene>(resourceManager);
    //this->pushState(initialState);
}

void SceneManager::cleanup()
{
    while(not m_scenes.empty())
        pop();
}

void SceneManager::pop()
{
	//m_scenes.top()->cleanup();  // deinit state
    //delete mStates.top();      // delete state
	m_scenes.pop();         // erase pointer
}

}
