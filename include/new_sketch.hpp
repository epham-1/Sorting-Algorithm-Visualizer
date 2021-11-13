#pragma once

#include "state.hpp"
#include "button.hpp"
class NewSketch: public State
{
public:
    NewSketch(StateManager* stateManager);
    ~NewSketch();
};