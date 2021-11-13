#include "include/array_sketch_menu.hpp"

ArraySketchMenu::ArraySketchMenu(StateManager* stateManager,Action action) : State(stateManager)
{
    //Header
    switch(action)
    {
        case Action::InsertionSort:
            m_stateElementList.push_back(new Panel(m_stateManager, 10, 10, 1180, 50, "Array - Insertion Sort", 32, sf::Color(200, 200, 200), 0));
            break;
        case Action::BubbleSort:
            m_stateElementList.push_back(new Panel(m_stateManager, 10, 10, 1180, 50, "Array - Bubble Sort", 32, sf::Color(200, 200, 200), 0));
            break;
        case Action::SelectionSort:
            m_stateElementList.push_back(new Panel(m_stateManager, 10, 10, 1180, 50, "Array - Selection Sort", 32, sf::Color(200, 200, 200), 0));
    }
    //Visualization Area
    m_sketchContainer = new Array(stateManager,10,70,882.5,660,action);
    m_stateElementList.push_back(m_sketchContainer);
    m_stateElementList.push_back(m_sketchContainer->getStatusPanel());
    
    //Status Area
    m_stateElementList.push_back(new Panel(m_stateManager,902.5,70,287.5,325,"",32,sf::Color(200,200,200),1));
    m_stateElementList.push_back(new Panel(m_stateManager,912.5,80,267.5,50,"Status:",32,sf::Color(150,150,150,0),1));

    m_stateElementList.push_back(m_sketchContainer->getStatusPanel());
    //Input Area
    m_stateElementList.push_back(new Panel(m_stateManager,902.5,405,287.5,265,"",32,sf::Color(200,200,200),1));
    m_stateElementList.push_back(new Panel(m_stateManager,912.5,415,267.5,50,"Input:",32,sf::Color(150,150,150,0),1));
    m_textForm = new TextForm(m_stateManager,912.5,475,267.5,185,26,sf::Color::White);
    m_stateElementList.push_back(m_textForm);
    m_stateElementList.push_back(new Button(m_stateManager,902.5,680,287.5,50,"Create",Action::Create));

    //Bottom Area
    m_stateElementList.push_back(new Button(m_stateManager,10,740,287.5,50,"Reset",Action::Back));
    m_stateElementList.push_back(new Button(m_stateManager,307.5,740,287.5,50,"Run",Action::Run));
    m_stateElementList.push_back(new Button(m_stateManager,605,740,287.5,50,"Pause",Action::Pause));
    m_stateElementList.push_back(new Button(m_stateManager,902.5,740,287.5,50,"Back",Action::Back));
}

ArraySketchMenu::~ArraySketchMenu(){}

SketchContainer* ArraySketchMenu::getSketchMenu()
    {
        return m_sketchContainer;
    }