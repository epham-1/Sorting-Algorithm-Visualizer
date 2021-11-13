#pragma once

#include <SFML/Graphics.hpp>
#include "state_manager.hpp"

extern sf::Font globalFont;

class StateElement
{
public:
    StateElement(StateManager* stateManager, float x, float y, float width, float height);
    ~StateElement();
    virtual void update() = 0;

    std::vector<sf::Drawable*>* getDrawableList();
    std::vector<sf::Drawable*>* getTempDrawableList();

protected:
    void centerTextonShape();
    void leftAlignOnShape();

    bool hovered();
    bool clicked();

    sf::Vector2i getMousePosition();
    bool getLeftKeyPressed();
    bool getRightKeyPressed();
    bool getLeftKeyHeld();
    bool getRightKeyHeld();
    bool getLeftKeyReleased();
    bool getRightKeyReleased();

    std::string getTextInput();

    StateManager* m_stateManager;
    std::vector<sf::Drawable*> m_drawableList;
    std::vector<sf::Drawable*> m_tempDrawableList;
    sf::Text* m_text;
    sf::RectangleShape* m_shape;
};