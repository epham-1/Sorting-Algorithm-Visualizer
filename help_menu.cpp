#include "include/help_menu.hpp"

HelpMenu::HelpMenu(StateManager* stateManager) : State(stateManager)
{
    m_stateElementList.push_back(new Panel(m_stateManager,10,10,1180,50,"Help",32,sf::Color(200,200,200),0));
    m_stateElementList.push_back(new Panel(m_stateManager,210,70,1180,730,"General:\nInput array size only.\nClicking reset will shuffle the array.",36,sf::Color(100,100,100,0),1));
    m_stateElementList.push_back(new Button(m_stateManager,902.5,740,287.5,50,"Back",Action::Back));
}

HelpMenu::~HelpMenu(){}