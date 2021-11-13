#include "include/window_manager.hpp"
#include <iostream>
WindowManager::WindowManager(){
    setupWindow(DEFAULT_TITLE,DEFAULT_WIDTH,DEFAULT_HEIGHT);
    
}

WindowManager::WindowManager(const std::string& windowTitle, unsigned int windowWidth, unsigned int windowHeight)
{
    setupWindow(windowTitle,windowWidth,windowHeight);
}

WindowManager::~WindowManager(){
    if(m_window.isOpen())
        this->endWindow();
}

bool WindowManager::isRunning()
{
    return m_running;
}

void WindowManager::clearWindow()
{
    m_window.clear(BGCOLOR);
}

void WindowManager::displayWindow()
{
    m_window.display();
}
sf::RenderWindow* WindowManager::getRenderWindow()
{
    return &m_window;
}

void WindowManager::endWindow()
{
    m_running = false;
    m_window.close();
}

void WindowManager::render(const sf::Drawable &drawable)
{
    m_window.draw(drawable);
}

void WindowManager::setupWindow(const std::string& windowTitle, unsigned int windowWidth, unsigned int windowHeight)
{
    m_title = windowTitle;
    m_windowSize = sf::Vector2u(windowWidth,windowHeight);
    m_running = true;
    this->createWindow();
}

void WindowManager::createWindow()
{
    m_window.create(sf::VideoMode(m_windowSize.x,m_windowSize.y,32),m_title);
    m_window.setFramerateLimit(fps);
    m_window.setVerticalSyncEnabled(false);
}