#include "include/button.hpp"

Button::Button(StateManager* stateManager, float x, float y, float width, float height,
    std::string buttonLabel, Action action) : StateElement(stateManager,x,y,width,height)
{
    m_buttonAction = action;

    //Choose Colors
    m_defaultColor = sf::Color::Black;
    m_hoverColor = sf::Color(150, 150, 150, 255);
    m_clickedColor = sf::Color(0,0,80,255);

    //Initialize
    m_shape->setFillColor(m_defaultColor);
    m_text->setString(buttonLabel);
    m_text->setFont(globalFont);
    m_text->setFillColor(sf::Color::White);
    m_text->setCharacterSize(30);

    centerTextonShape();
}

Button::~Button(){}

void Button::update()
{
    centerTextonShape();
    if(clicked())
    {
        m_shape->setFillColor(m_clickedColor);
        m_stateManager->perform(m_buttonAction);
    }
    else if(hovered())
    {
        m_shape->setFillColor(m_hoverColor);
    }
    else
    {
        m_shape->setFillColor(m_defaultColor);
    }
}