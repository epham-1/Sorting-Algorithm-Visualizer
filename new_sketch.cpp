#include "include/new_sketch.hpp"

NewSketch::NewSketch(StateManager* stateManager) : State(stateManager)
{
    m_stateElementList.push_back(new Panel(m_stateManager, 250, 116, 700, 250, "Create a New Sketch", 52, sf ::Color(0, 0, 0, 0), 0));
    m_stateElementList.push_back(new Button(m_stateManager,425,430,350,50,"Insertion Sort",Action::InsertionSort));
    m_stateElementList.push_back(new Button(m_stateManager,425,490,350,50,"Bubble Sort",Action::BubbleSort));
    m_stateElementList.push_back(new Button(m_stateManager,425,550,350,50,"Selection Sort",Action::SelectionSort));
    m_stateElementList.push_back(new Button(m_stateManager,425,610,350,50,"Back",Action::Back));
}

NewSketch::~NewSketch(){}