#ifndef SCORES_H
#define SCORES_H
#include "appstate.h"
#include "../objects/player.h"

#include <vector>
#include <string>

/**
 * @brief
 * Class is responsible for displaying players' results from the previous round
 */
class Scores : public AppState
{
public:
    Scores();
    /**
     * Constructor called by Game after the gameplay ends
     * @param players - container with all players who participated in the gameplay
     * @param level - last level number
     * @param game_over - variable telling whether the last level was lost
     */
    Scores(std::vector<Player*> players, int level, bool game_over);
    /**
     * Function returns @a true after a specified time of displaying the score screen
     * @return @a true or @a false
     */
    bool finished() const;
    /**
     * Function is responsible for drawing the appropriate texts and player tanks on the screen
     */
    void draw();
    /**
     * Function is responsible for changing the score counter
     * @param dt - time since the last function call allows determining the display time of the results window
     */
    void update(Uint32 dt);
    /**
     * Function responds to pressing the Enter key, which ends the point countdown and accelerates the transition to the next state
     * @param ev - pointer to SDL_Event union storing the type and parameters of various events
     */
    void eventProcess(SDL_Event* ev);
    /**
     * Function returns a pointer to an object that is the next application state. If the player lost, the next state is @a Menu; if they passed the round, the next state is @a Game.
     * @return pointer to the next state
     */
    AppState* nextState();

private:
    /**
     * Container with all players (killed and not killed)
     */
    std::vector<Player*> m_players;
    /**
     * Last level number
     */
    int m_level;
    /**
     * Variable stores whether the last level was lost
     */
    bool m_game_over;
    /**
     * Current value of the score counter
     */
    unsigned m_score_counter;
    /**
     * Variable telling whether the score counter is enabled
     */
    bool m_score_counter_run;
    /**
     * Result that the score counter is aiming for
     */
    unsigned m_max_score;
    /**
     * Time since the end of point counting in milliseconds
     */
    Uint32 m_show_time;
};

#endif // SCORES_H
