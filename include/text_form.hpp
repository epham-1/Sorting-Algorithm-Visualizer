#pragma once
#include "state_element.hpp"

class TextForm: public StateElement
{
public:
    TextForm(StateManager* stateManager, float x, float y, float width, float height, int fontSize, sf::Color color);
    ~TextForm();

    void update();
    std::string getText();
    std::vector<int> extractValues();

private:
    std::string m_keyboardInput;
};