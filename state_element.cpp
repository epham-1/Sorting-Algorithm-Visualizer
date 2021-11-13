#include "include/state_element.hpp"

StateElement::StateElement(StateManager* stateManager, float x, float y, float width, float height) 
{
    m_stateManager = stateManager;
    m_shape = new sf::RectangleShape;
    m_text = new sf::Text;

    m_shape->setPosition(sf::Vector2f(x,y));
    m_shape->setSize(sf::Vector2f(width,height));
    m_shape->setFillColor(sf::Color(255,255,255,0));

    m_drawableList.push_back(m_shape);
    m_drawableList.push_back(m_text);
}

StateElement::~StateElement()
{
    for(auto elements: m_drawableList)
        delete elements;
}

std::vector<sf::Drawable*>* StateElement::getDrawableList()
{
    return &m_drawableList;
}

std::vector<sf::Drawable*>* StateElement::getTempDrawableList()
{
    return &m_tempDrawableList;
}

void StateElement::centerTextonShape()
{
    const sf::FloatRect textBounds = m_text->getLocalBounds();
    const sf::Vector2f shapeBounds = m_shape->getSize();
    m_text->setOrigin((textBounds.width - shapeBounds.x)/2 + textBounds.left,
    (textBounds.height - shapeBounds.y)/2 + textBounds.top);

    m_text->setPosition(m_shape->getPosition().x,m_shape->getPosition().y);
}

void StateElement::leftAlignOnShape()
{
    m_text->setPosition(m_shape->getPosition().x + 10,m_shape->getPosition().y + 10);
}

bool StateElement::hovered()
{
    if(m_shape->getGlobalBounds().contains(getMousePosition().x,getMousePosition().y))
        return true;
    else
        return false;
}

bool StateElement::clicked()
{
    if(hovered()  && getLeftKeyPressed())
        return true;
    return false;
}

sf::Vector2i StateElement::getMousePosition()
{
    return m_stateManager->getEventManager()->getMousePosition();
}

bool StateElement::getLeftKeyPressed()
{
    return m_stateManager->getEventManager()->isLeftKeyPressed();
}

bool StateElement::getLeftKeyHeld()
{
    return m_stateManager->getEventManager()->isLeftKeyHeld();
}

bool StateElement::getLeftKeyReleased()
{
    return m_stateManager->getEventManager()->isLeftKeyReleased();
}
//Right Mouse Button Events
bool StateElement::getRightKeyPressed()
{
    return m_stateManager->getEventManager()->isRightKeyPressed();
}

bool StateElement::getRightKeyHeld()
{
    return m_stateManager->getEventManager()->isRightKeyHeld();
}

bool StateElement::getRightKeyReleased()
{
    return m_stateManager->getEventManager()->isRightKeyReleased();
}
//Get Text
std::string StateElement::getTextInput()
{
    return m_stateManager->getEventManager()->getCurrentKey();
}