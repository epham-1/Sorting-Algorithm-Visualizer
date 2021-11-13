#pragma once

#include "state.hpp"
#include "button.hpp"
class MainMenu: public State
{
public:
    MainMenu(StateManager* stateManager);
    ~MainMenu();
};