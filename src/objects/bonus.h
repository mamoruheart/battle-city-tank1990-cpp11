#ifndef BONUS_H
#define BONUS_H

#include "object.h"

/**
 * @brief Class responsible for displaying the bonus
 */
class Bonus : public Object
{
public:
    /**
     * Creating a default bonus - a star at position (0, 0)
     */
    Bonus();
    /**
     * Creating a bonus
     * @param x - Initial horizontal position
     * @param y - Initial vertical position
     * @param type - Type of bonus
     */
    Bonus(double x, double y, SpriteType type);

    /**
     * Function for drawing the bonus
     */
    void draw();
    /**
     * Function updating the bonus animation. Allowing removal after the appropriate time.
     * Increasing the blinking frequency if the bonus is about to be removed
     * @param dt - Time since the last function call
     */
    void update(Uint32 dt);
private:
    /**
     * Time since the bonus was created
     */
    Uint32 m_bonus_show_time;
    /**
     * Variable storing information about whether the bonus is currently displayed; used for blinking.
     */
    bool m_show;
};

#endif // BONUS_H
