#include "include/array.hpp"
#include "include/state.hpp"
#include <iostream>
Bar::Bar(int value, int arraySize, float barWidth, float areaWidth)
{
    m_value = value;
    m_width = barWidth;
    m_height = value * 6;
    m_color = sf::Color::Black;
}

Bar::~Bar(){}

sf::Color Bar::getColor()
{
    return m_color;
}

void Bar::setValue(int value)
{
    m_value = value;
}

int Bar::getHeight()
{
    return m_height;
}

int Bar::getWidth()
{
    return m_width;
}

int Bar::getValue()
{
    return m_value;
}

Array::Array(StateManager* stateManager, float x, float y, float width, float height, Action action) : 
SketchContainer(stateManager,x,y,width,height)
{
    m_action = action;
    m_barOffSet = 0.85;
    m_x = x;
    m_y = y;
    m_arrayWidth = width;
    m_arrayHeight = height;
    
    //Initilize variables
    m_minimumIndex = 0;
    m_inner = 0;
    m_outer = 0;
    m_sorted = false;
    m_paused = true;    
    
}

Array::~Array()
{
    for(auto bar : m_barList )
        delete bar;
}

int Array::getOuter()
{
    return m_outer;
}

int Array::getInner()
{
    return m_inner;
}

void Array::setOuter(int num)
{
    m_outer = num;
}

void Array::setInner(int num)
{
    m_inner = num;
}

void Array::create()
{
    //Clear previous outputs
    m_tempDrawableList.clear();
    m_barList.clear();

    //Set all of the sizes
    createFromInput();
    m_barWidth = m_arrayWidth / m_size - m_barOffSet;
    
    //Create Bars and Drawables
    for(int i =0; i < m_size; i++)
        m_barList.push_back(new Bar(rand()%95 + 5, m_size, m_barWidth, m_arrayHeight));
    createDrawableList();

    //Initialize Variables
    m_initialized = true;
    m_minimumIndex = 0;
    m_inner = 0;
    m_outer = 0;
    m_sorted = false;

    m_statusMessage = "Unsorted";
    m_statusPanel->setString(m_statusMessage);
}

void Array::reset()
{
    if(m_paused && m_initialized)
    {
        m_barList.clear();

        for (int i = 0; i < m_size; i++)
            m_barList.push_back(new Bar(rand() % 95 + 5, m_size, m_barWidth, m_arrayHeight));

        createDrawableList();
        m_initialized = true;
        m_minimumIndex = 0;
        m_inner = 0;
        m_outer = 0;
        m_sorted = false;

        m_statusMessage = "Unsorted";
        m_statusPanel->setString(m_statusMessage);
    }
}

void Array::update()
{
    if(!m_paused && m_action == Action::InsertionSort)
    {
        insertionSort();
        createDrawableList();
    }
    
    if(!m_paused && m_action == Action::BubbleSort)
    {
        bubbleSort();
        createDrawableList();
    }
    if(!m_paused && m_action == Action::SelectionSort)
    {
        selectionSort();
        createDrawableList();
    }
}

void Array::createDrawableList()
{
    int offset = 1;
    m_tempDrawableList.clear();

    for(int i = 0 ; i < m_size; i++)
    {
        sf::RectangleShape* barShape = new sf::RectangleShape(sf::Vector2f(m_barList[i]->getWidth(),m_barList[i]->getHeight()));
        m_tempDrawableList.push_back(barShape);

        barShape->setPosition(m_x + (offset + m_barList[i]->getWidth()) * i,
                              m_y + m_arrayHeight - m_barList[i]->getHeight());

        //Setup for InsertionSort
        if(m_action == Action::InsertionSort)
        {
            if(i == getOuter() && !m_sorted)
                barShape->setFillColor(sf::Color::Red);
            else if(i == getInner() + 1 && !m_sorted)
                barShape->setFillColor(sf::Color::Blue);
            else
                barShape->setFillColor(m_barList[i]->getColor());
        }

        //Setup for BubbleSort / SelectionSort
        else
        {
            if(i == getOuter() && !m_sorted)
                barShape->setFillColor(sf::Color::Red);
            else if(i == getInner() && !m_sorted)
                barShape->setFillColor(sf::Color::Blue);
            else
                barShape->setFillColor(m_barList[i]->getColor());
        }

        barShape->setOutlineColor(sf::Color(200, 200, 200, 255));
        barShape->setOutlineThickness(1);
    }
}

void Array::createFromInput()
{
    std::vector<int> values = m_stateManager->getState()->getTextForm()->extractValues();

    if(values.size() != 0)
    {
        m_size = values[0];
    }
}

void Array::insertionSort()
{
    if(!m_sorted)
    {
        int i = getOuter();
        int j = getInner();

        if(i == m_size)
            m_sorted = true;

        if(!m_sorted && i > 0)
        {
            if( j >= 0 && m_barList[j]->getValue() > m_barList[j+1]->getValue())
            {
                m_statusMessage = "Swapped " + std::to_string(j) + " and " + std::to_string(j+1);
                std::swap(m_barList[j],m_barList[j+1]);
                j--;
            }
            else
            {
                i++;
                j = i - 1;
            }
        }
        if(i == 0)
        {
            i++;
        }
        setInner(j);
        setOuter(i);
    }
    if (!m_sorted)
        m_statusPanel->setString(m_statusMessage);
    else
        m_statusMessage = "";
}

void Array::bubbleSort()
{
    int i = getOuter();
    int j = getInner();

    if(j == 0 || i == 0)
    {
        m_swapped = false;
    }

    if (i == m_size && j == m_size)
    {
        m_sorted = true;
        m_statusMessage = "";
    }

    if (!m_sorted)
    {
        if (m_barList[i]->getValue() < m_barList[j]->getValue())
        {
            m_statusMessage = "Swapped " + std::to_string(i) + " and " + std::to_string(j);
            std::swap(m_barList[i], m_barList[j]);
            m_swapped = true;
        }

        j++;

        if(j == m_size && m_swapped == false)
        {
            i = m_size;
            j = m_size;
        }
        else if (j == m_size)
        {
            i = 0;
            j = i;
        }

        setOuter(j);
        setInner(i);
    }

    m_statusPanel->setString(m_statusMessage);
}


void Array::selectionSort()
{
    int i = getOuter();
    int j = getInner();

    if(i == m_size - 1 && j == m_size)
    {
        m_sorted = true;
    }

    if(i < m_size && !m_sorted)
    {
        if(j < m_size)
        {
            //Store the index of the minimum value while iterating through the list
            if(m_barList[m_minimumIndex]->getValue() > m_barList[j]->getValue())
            {
                m_minimumIndex = j;
            }
            j++;
        }

        if(j == m_size)
        {
            
            m_statusMessage = "Swapped " + std::to_string(i) + " and " + std::to_string(m_minimumIndex) + "\nSelected Index: " + std::to_string(m_minimumIndex);
            std::swap(m_barList[i], m_barList[m_minimumIndex]);
            i++;
            m_minimumIndex = i;
            j = i + 1;            
        }
    }

    setOuter(i);
    setInner(j);
    
    m_statusPanel->setString(m_statusMessage);
    if(m_sorted)
        m_statusMessage = "";
        
}
