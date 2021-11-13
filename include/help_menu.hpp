#pragma once

#include "state.hpp"
#include "button.hpp"
class HelpMenu: public State
{
public:
    HelpMenu(StateManager* stateManager);
    ~HelpMenu();
};