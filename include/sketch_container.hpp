#pragma once

#include "state_element.hpp"
#include "panel.hpp"

class SketchContainer: public StateElement
{
public:
    SketchContainer(StateManager* stateManager, float x, float y, float width, float height);
    ~SketchContainer();

    bool isPaused();
    void setPaused(bool flag);
    virtual void create() = 0;
    virtual void reset() = 0;
    virtual void update() = 0;

    Panel* getStatusPanel();

protected:
    std::string m_statusMessage;
    Panel* m_statusPanel;
    bool m_paused;
    bool m_initialized;
};