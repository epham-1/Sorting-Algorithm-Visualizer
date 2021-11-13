#include "include/event_manager.hpp"
#include "include/state_manager.hpp"

EventManager::EventManager(StateManager* stateManager)
{
    m_stateManager = stateManager;
    m_lastKey = "";

    m_leftKeyReleased = false;
    m_leftKeyPressed = false;
    m_leftKeyHeld = false;

    m_rightKeyHeld = false;
    m_rightKeyPressed = false;
    m_rightKeyReleased = false;
}

EventManager::~EventManager(){}

void EventManager::update()
{
    float timeSinceLastInput = m_inputClock.getElapsedTime().asSeconds();

    m_lastKey = "";

    m_leftKeyReleased = false;
    m_leftKeyPressed = false;

    m_rightKeyPressed = false;
    m_rightKeyReleased = false;

    sf::Event event;
    while(m_stateManager->getWindowManager()->getRenderWindow()->pollEvent(event))
    {
        if(timeSinceLastInput >= m_inputDelay)
        {
            m_inputClock.restart();

            if(event.type == sf::Event::Closed)
            {
                m_stateManager->getWindowManager()->endWindow();
            }

            //Mouse Button is pressed
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    m_leftKeyPressed = true;
                    m_leftKeyHeld = true;
                }

                if(event.mouseButton.button == sf::Mouse::Right)
                {
                    m_rightKeyPressed = true;
                    m_rightKeyHeld = true;
                }
            }

            //Mouse Button is released

            if(event.type == sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    m_leftKeyReleased = true;
                    m_leftKeyHeld = false;
                }

                if(event.mouseButton.button == sf::Mouse::Right)
                {
                    m_rightKeyReleased = true;
                    m_rightKeyHeld = false;
                }
            }

            //Printable Key
            if(event.type == sf::Event::TextEntered)
            {
                m_lastKey = char(event.text.unicode);
            }
        }
    }
}

sf::Vector2i EventManager::getMousePosition()
{
    return sf::Mouse::getPosition(*(m_stateManager->getWindowManager()->getRenderWindow()));
}
bool EventManager::isLeftKeyPressed()
{
    return m_leftKeyPressed;
}
bool EventManager::isLeftKeyReleased()
{
    return m_leftKeyReleased;
}
bool EventManager::isLeftKeyHeld()
{
    return m_leftKeyHeld;
}
bool EventManager::isRightKeyPressed()
{
    return m_rightKeyPressed;
}
bool EventManager::isRightKeyReleased()
{
    return m_rightKeyReleased;
}
bool EventManager::isRightKeyHeld()
{
    return m_rightKeyHeld;
}
std::string EventManager::getCurrentKey()
{
    return m_lastKey;
}