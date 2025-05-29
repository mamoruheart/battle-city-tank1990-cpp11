#ifndef MENU_H
#define MENU_H

#include "appstate.h"
#include "../objects/player.h"

#include <vector>
#include <string>
/**
 * @brief
 * Game mode selection class: 1 player or 2 players or exit. The class is the first state of the application, appears right after program startup and allows transition to the game state (Game class).
 */
class Menu : public AppState
{
public:
    Menu();
    ~Menu();
    /**
     * Function checking whether the menu state should be ended and transition to the next game state
     * @return @a true if one of the menu options has been selected or the Esc key was pressed, @a false otherwise
     */
    bool finished() const;
    /**
     * Function draws the game logo, menu text and selected position indicator in the shape of a tank
     */
    void draw();
    /**
     * Function is responsible for animating the indicator in the form of a tank
     * @param dt - time since last animation
     * @see Tank::update(Uint32 dt)
     */
    void update(Uint32 dt);
    /**
     * Function responds to key reactions:
     * @li "Up and down arrow - change selected menu position
     * @li Enter and Space - confirm current menu position
     * @li Esc - exit from program
     * @param ev - pointer to SDL_Event union storing the type and parameters of various events
     */
    void eventProcess(SDL_Event* ev);
    /**
     * Transition to the game in the selected mode or exit from the application.
     * @return @a nullptr if 'Exit' was selected or Esc was pressed, otherwise the function returns a pointer to Game
     */
    AppState* nextState();

private:
    /**
     * Container storing all the text that appears in the menu
     */
    std::vector<std::string> m_menu_texts;
    /**
     * Index of the selected menu position
     */
    int m_menu_index;
    /**
     * Variable responsible for the indicator in the form of a tank
     */
    Player* m_tank_pointer;
    /**
     * Variable stores information on whether the current game state should be ended and transition to the game or shut down the application.
     */
    bool m_finished;
};

#endif // MENU_H
