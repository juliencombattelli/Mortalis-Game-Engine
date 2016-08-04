#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <MGE/Core/Scene/Scene.hpp>
#include <stack>
#include <memory>

namespace mge
{

class ResourceManager;

class SceneManager
{
public:
	SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
    ~SceneManager();

    void init(ResourceManager& resourceManager);

    void cleanup();

    template<class T>
    void push(ResourceManager& resourceManager)
    {
    	m_scenes.push(std::make_unique<T>(resourceManager));   // register pointer state
    	//m_scenes.top()->init();     // initialize state
    }
    void pop();

    bool isEmpty() const { return m_scenes.empty(); }

    Scene& getActiveState() { return *m_scenes.top(); }

private:

    std::stack<std::unique_ptr<Scene>> m_scenes;
};

} // namespace mge

#endif // SCENEMANAGER_HPP_
