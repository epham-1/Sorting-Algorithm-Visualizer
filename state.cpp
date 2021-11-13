#include "include/state.hpp"
#include "include/state_element.hpp"

State::State(StateManager* stateManager) : m_stateManager(stateManager)
{}

State::~State(){}

void State::render()
{
    for(auto stateElements : m_stateElementList)
    {
        for(auto elements : *((*stateElements).getDrawableList()))
        {
            m_stateManager->getWindowManager()->render(*elements);
        }
        for(auto elements : *((*stateElements).getTempDrawableList()))
        {
            m_stateManager->getWindowManager()->render(*elements);
        }
    }
}

void State::update()
{
    for(auto stateElements : m_stateElementList)
    {
        stateElements->update();
    }
}

void State::addStateElement(StateElement* stateElement)
{
    m_stateElementList.push_back(stateElement);
}
SketchContainer* State::getSketchContainer()
{
    return m_sketchContainer;
}

TextForm* State::getTextForm()
{
    return m_textForm;
}