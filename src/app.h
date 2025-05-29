#ifndef APP_H
#define APP_H

#include "app_state/appstate.h"

/**
 * @brief
 * The main class of the application. Its behavior is equivalent to the behavior of the application.
 */
class App
{
public:
    App();
    ~App();
    /**
     * The function includes the initialization of the SDL2 library, the game engine, and the loading of textures and fonts.
     * After successful initialization, the program enters the main loop, which sequentially: responds to events,
     * updates the current state of the application, and draws objects on the screen.
     */
    void run();
    /**
     * A function that handles events waiting in the queue.
     */
    void eventProces();
private:
    /**
     * A variable that keeps the main program loop running.
     */
    bool is_running;
    /**
     * The current state of the application.
     */
    AppState* m_app_state;
    /**
     * The application window object.
     */
    SDL_Window* m_window;
};

#endif // APP_H
