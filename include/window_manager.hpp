#pragma once
#include <string>
#include <SFML/Graphics.hpp>

//global Variables for the default window
const std::string DEFAULT_TITLE = "Algorithm Visualizer";
const unsigned int DEFAULT_WIDTH = 1200;
const unsigned int DEFAULT_HEIGHT = 800;
const sf::Color BGCOLOR = sf::Color(221,221,221);
class WindowManager{
public:
    //Default Constructor
    //Creates a Window of 1200 by 800 titled "Window"
    WindowManager();
    //Overloaded Constructor
    //Creates a Window given the title, width, and height
    WindowManager(const std::string& windowTitle, unsigned int windowWidth, unsigned int windowHeight);
    //Destructor
    ~WindowManager();

    bool isRunning();
    void clearWindow();
    void displayWindow();
    sf::RenderWindow* getRenderWindow();
    void endWindow(); 
    void render(const sf::Drawable &drawable);

private:
    void setupWindow(const std::string& windowTitle, unsigned int windowWidth, unsigned int windowHeight);
    void createWindow();

    //private variables
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_title;
    bool m_running;
    const int fps = 10;
};