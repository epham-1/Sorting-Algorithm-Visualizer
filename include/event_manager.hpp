#pragma once
#include <SFML/Graphics.hpp>

//Forward Declaration of StateManager class
class StateManager;

class EventManager
{
public:
    EventManager(StateManager* stateManager);
    ~EventManager();

    void update();

    sf::Vector2i getMousePosition();
    bool isLeftKeyPressed();
    bool isLeftKeyReleased();
    bool isLeftKeyHeld();
    bool isRightKeyPressed();
    bool isRightKeyReleased();
    bool isRightKeyHeld();
    std::string getCurrentKey();
private:
    std::string m_lastKey;
    bool m_leftKeyPressed;
    bool m_leftKeyReleased;
    bool m_leftKeyHeld;
    bool m_rightKeyPressed;
    bool m_rightKeyReleased;
    bool m_rightKeyHeld;

    StateManager *m_stateManager; 
    sf::Clock m_inputClock;

    const float m_inputDelay = 0.01;
};