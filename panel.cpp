#include "include/panel.hpp"

Panel::Panel(StateManager* stateManager, float x, float y, float width, float height, std::string panelLabel,
    int fontSize, sf::Color color, int panelType): StateElement(stateManager,x,y,width,height)
{
    //Set the text and the shape
    m_text->setString(panelLabel);
    m_text->setFont(globalFont);
    m_text->setFillColor(sf::Color::Black);
    m_text->setCharacterSize(fontSize);
    m_shape->setFillColor(color);

    //Set type
    m_panelType = panelType;

    //Center the text
    if(m_panelType == 0)
        centerTextonShape();
    else if(m_panelType == 1)
        leftAlignOnShape();
}

Panel::~Panel()
{}

void Panel::update()
{
    if(m_panelType == 0)
        centerTextonShape();
    else if(m_panelType == 1)
        leftAlignOnShape();
}

void Panel::setString(std::string string)
{
    m_text->setString(string);
}