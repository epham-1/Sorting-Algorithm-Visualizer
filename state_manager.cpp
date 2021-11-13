#include "include/state_manager.hpp"
#include "include/main_menu.hpp"
#include "include/state.hpp"
#include "include/new_sketch.hpp"
#include "include/help_menu.hpp"
#include "include/array_sketch_menu.hpp"

StateManager::StateManager()
{
    m_state = nullptr;
}

StateManager::StateManager(WindowManager *windowManager,EventManager *eventManager)
{
    m_windowManager = windowManager;
    m_eventManager = eventManager;
    perform(Action::MainMenu);
}

StateManager::~StateManager(){
    delete m_state;
}

void StateManager::Start()
{
    perform(Action::MainMenu);
}

void StateManager::setEventManager(EventManager *eventManager)
{
    m_eventManager = eventManager;
}

void StateManager::setWindowManager(WindowManager *windowManager)
{
    m_windowManager = windowManager;
}

void StateManager::setState(State *state)
{
    m_state = state;
}

State* StateManager::getState()
{
    return m_state;
}

WindowManager* StateManager::getWindowManager()
{
    return m_windowManager;
}

EventManager* StateManager::getEventManager()
{
    return m_eventManager;
}

void StateManager::perform(Action action)
{
    switch(action)
    {
    case Action::MainMenu:
    case Action::Back:
        setState(new MainMenu(this));
        break;
    case Action::QuitApplication:
        getWindowManager()->endWindow();
    case Action::NewSketch:
        setState(new NewSketch(this));
        break;
    case Action::HelpMenu:
        setState(new HelpMenu(this));
        break;
    case Action::InsertionSort:
        setState(new ArraySketchMenu(this,action));
        break;
    case Action::BubbleSort:
        setState(new ArraySketchMenu(this,action));
        break;
    case Action::SelectionSort:
        setState(new ArraySketchMenu(this,action));
        break;
    case Action::Create:
        getState()->getSketchContainer()->create();
        break;
    case Action::Run:
        getState()->getSketchContainer()->setPaused(false);
        break;
    case Action::Pause:
        getState()->getSketchContainer()->setPaused(true);
        break;
    default:
        break;
    }
    
}

void StateManager::update()
{
    if(m_state != nullptr)
        m_state->update();
}

void StateManager::render()
{
    if(m_state != nullptr)
        m_state->render();
}