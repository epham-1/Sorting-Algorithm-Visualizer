#pragma once
#include <vector>
#include "state_manager.hpp"
#include "text_form.hpp"
#include "sketch_container.hpp"

class StateElement;

class State
{
public:
    State(StateManager* stateManager);
    ~State();

    void render();

    void update();

    void addStateElement(StateElement* stateElement);

    SketchContainer* getSketchContainer();

    TextForm* getTextForm();

protected:
    std::vector<StateElement*> m_stateElementList;
    StateManager* m_stateManager;
    SketchContainer* m_sketchContainer;
    TextForm* m_textForm;
};