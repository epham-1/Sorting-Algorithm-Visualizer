#include "include/main_menu.hpp"

MainMenu::MainMenu(StateManager* stateManager) : State(stateManager)
{
    // Title
    m_stateElementList.push_back(new Panel(m_stateManager, 250, 116, 700, 250, "AlgoSketch", 104, sf ::Color(0, 0, 0, 0), 0));

    // Buttons
    m_stateElementList.push_back(new Button(m_stateManager, 425, 460, 350, 50, "New Sketch", Action::NewSketch));
    m_stateElementList.push_back(new Button(m_stateManager, 425, 520, 350, 50, "Help", Action::HelpMenu));
    m_stateElementList.push_back(new Button(m_stateManager, 425, 580, 350, 50, "Quit", Action::QuitApplication));
}

MainMenu::~MainMenu(){}