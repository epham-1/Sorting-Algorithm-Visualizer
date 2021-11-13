#include "include/sketch_container.hpp"
#include "include/state.hpp"

SketchContainer::SketchContainer(StateManager* stateManager, float x, float y, float width, float height) : 
StateElement(stateManager,x,y,width,height)
{
    m_paused = true;

    //Initialize
    m_statusMessage = "";
    m_statusPanel = new Panel(stateManager, 912.5,150,267.5, 245,m_statusMessage, 24,sf::Color(0,0,0,0), 1);
    m_stateManager->getState()->addStateElement(m_statusPanel);
}

SketchContainer::~SketchContainer(){}

bool SketchContainer::isPaused()
{
    return m_paused;
}

void SketchContainer::setPaused(bool flag)
{
    m_paused = flag;
}

Panel* SketchContainer::getStatusPanel()
{
    return m_statusPanel;
}

