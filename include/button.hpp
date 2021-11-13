#pragma once

#include "state_element.hpp"

class Button: public StateElement
{
public:
    Button(StateManager* stateManager, float x, float y, float width, float height,
    std::string buttonLabel, Action action);
    ~Button();

    void update();

private:
    sf::Color m_defaultColor;
    sf::Color m_hoverColor;
    sf::Color m_clickedColor;
    Action m_buttonAction;
};