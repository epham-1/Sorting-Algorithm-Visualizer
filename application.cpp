#include "include/application.hpp"

sf::Font globalFont;

Application::Application() : 
m_windowManager("Algorithm Visualizer",1200,800), m_eventManager(&(m_stateManager)) 
{
    m_stateManager.setEventManager(&(m_eventManager));
    m_stateManager.setWindowManager(&(m_windowManager));
    m_stateManager.Start();

    globalFont.loadFromFile("font/times new roman.ttf");
}

Application::~Application()
{
}

void Application::run()
{
    while(m_windowManager.isRunning())
    {
        update();
        render();
    }
}

void Application::update()
{
    m_eventManager.update();
    m_stateManager.update();
}

void Application::render()
{
    m_windowManager.clearWindow();
    m_stateManager.render();
    m_windowManager.displayWindow();
}