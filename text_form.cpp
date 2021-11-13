#include "include/text_form.hpp"
#include <sstream>

TextForm::TextForm(StateManager* stateManager, float x, float y, float width, float height, int fontSize, sf::Color color):
StateElement(stateManager, x, y, width, height)
{
    m_text->setString("");
    m_text->setFont(globalFont);
    m_text->setFillColor(sf::Color::Black);
    m_text->setCharacterSize(fontSize);

    m_shape->setFillColor(color);

    m_keyboardInput = "";
}

TextForm::~TextForm(){}

void TextForm::update()
{
    leftAlignOnShape();

    std::string currentText = getTextInput();

    if(currentText == "\b")
    {
        if(m_keyboardInput.size() != 0)
            m_keyboardInput = m_keyboardInput.substr(0,m_keyboardInput.size() - 1);
    }
    else if (currentText == "\r")
    {
        m_keyboardInput += "\n";
    }
    else
    {
        m_keyboardInput += currentText;

        /*
        size_t textSize = m_keyboardInput.size();
        if (textSize % 18 == 0 && m_keyboardInput[textSize - 1] != '\n' and textSize != 0)
            m_keyboardInput += "\n";
        */
    }

    m_text->setString(m_keyboardInput + "_");
}

std::string TextForm::getText()
{
    return m_keyboardInput;
}

std::vector<int> TextForm::extractValues()
{
    std::vector<int> integers;
    std::stringstream textStream;
    std::string streamWord;
    int extractedInteger;

    textStream << this->getText();

    while (!textStream.eof())
    {
        // Load each word into a string
        textStream >> streamWord;
        // Convert to integer and push it to the vector
        if (std::stringstream(streamWord) >> extractedInteger)
            integers.push_back(extractedInteger);
    }
    return integers;
}