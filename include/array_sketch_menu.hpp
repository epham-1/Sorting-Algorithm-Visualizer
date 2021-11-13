#pragma once

#include "state.hpp"
#include "button.hpp"
#include "array.hpp"
class ArraySketchMenu: public State
{
public:
    //Contructors the Array Sketch Menu
    ArraySketchMenu(StateManager* stateManager,Action action);

    //Destructor for the Array Sketch Menu
    ~ArraySketchMenu();

    SketchContainer* getSketchMenu();
};