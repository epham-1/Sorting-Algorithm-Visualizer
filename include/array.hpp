#pragma once
#include "panel.hpp"
#include "sketch_container.hpp"
class Array;

class Bar
{
public:
    friend Array;
    //Constructor
    //Initializes all of the varibles needed for the bar class
    Bar(int value, int arraySize, float barWidth, float areaWidth);
    ~Bar();
    //Set color of the bar
    void setColor(sf::Color color);
    //Returns the color of the bar
    sf::Color getColor();
    //Sets the value of the bar
    void setValue(int value);
    int getHeight();
    int getWidth();
    int getValue();
    
private:
    int m_value;
    float m_width,m_height;
    sf::Color m_color;

};
class Array:public SketchContainer
{
public:
    Array(StateManager* stateManager, float x, float y, float width, float height, Action action);
    ~Array();

    void create();
    void update();
    void reset();
private:
    void createDrawableList();
    void createFromInput();

    int getOuter();
    int getInner();
    void setOuter(int num);
    void setInner(int num);

    void insertionSort();
    void bubbleSort();
    void selectionSort();

    //Private Members
    std::vector<Bar*> m_barList;
    int m_inner, m_outer;
    float m_arrayWidth, m_arrayHeight;
    float m_barWidth, m_barHeight, m_barOffSet;
    float m_x,m_y;
    Action m_action;
    int m_size;
    int m_minimumIndex;
    bool m_sorted;

    //Variable for bubbleSort
    bool m_swapped;
};
