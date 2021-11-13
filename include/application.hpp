#include <SFML/Graphics.hpp>
#include "window_manager.hpp"
#include "state_manager.hpp"
#include "event_manager.hpp"

class Application
{
public:
    //Default Constructor
    //Initializes the EventManager, StateManager, and the WindowManager
    Application();
    //Destructor
    ~Application();

    //Runs the main loop of the function
    void run();

    //Updates the state and event managers
    void update();

    //Clears the screen and re-renders the screen
    void render();
private:
    WindowManager m_windowManager;
    StateManager m_stateManager;
    EventManager m_eventManager;
};