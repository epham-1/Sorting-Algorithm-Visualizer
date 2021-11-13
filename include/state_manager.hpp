#pragma once
#include <SFML/Graphics.hpp>
#include "window_manager.hpp"
#include "event_manager.hpp"
//Forward Declaration of State Class
class State;

enum class Action
{
    MainMenu,
    Back,
    QuitApplication,
    InsertionSort,
    NewSketch,
    HelpMenu,
    Create,
    Run,
    Pause,
    BubbleSort,
    SelectionSort,
    
    
        
};
class StateManager{
public:
    StateManager();
    StateManager(WindowManager *windowManager,EventManager *eventManager);
    ~StateManager();

    void Start();

    //Setters
    void setWindowManager(WindowManager *windowManager);
    void setEventManager(EventManager *eventManager);
    void setState(State *state);
    //Getters
    State *getState();
    WindowManager *getWindowManager();
    EventManager *getEventManager();

    void perform(Action action);

    void render();
    void update();
private:
    WindowManager *m_windowManager;
    EventManager *m_eventManager;

    State *m_state;
};