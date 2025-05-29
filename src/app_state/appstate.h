#ifndef APPSTATE_H
#define APPSTATE_H

#include <SDL2/SDL_events.h>
#include <string>

/**
 * @brief
 * The class is an interface from which the classes @a Game, @a Menu, and @a Scores inherit.
 */
class AppState
{
public:
    virtual ~AppState() {}

    /**
     * The function checks if the current game state has ended.
     * @return @a true if the current game state has ended, otherwise @a false.
     */
    virtual bool finished() const = 0;
    /**
     * Function that draws game elements belonging to the given state.
     */
    virtual void draw() = 0;
    /**
     * Function updating the state of objects and counters in the game.
     * @param dt - Time since the last function call in milliseconds.
     */
    virtual void update(Uint32 dt) = 0;
    /**
     * Function that enables handling of events detected by the SDL2 library.
     * @param ev - Pointer to the SDL_Event union that holds the type and parameters of various events.
     */
    virtual void eventProcess(SDL_Event* ev) = 0;
    /**
     * Function returning the next state after the current one ends. The function should only be called only when the @a finished function returns @a true.
     * @return Next game state.
     */
    virtual AppState* nextState() = 0;
};
#endif // APPSTATE_H
