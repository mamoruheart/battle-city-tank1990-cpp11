#ifndef BRICK_H
#define BRICK_H

#include "object.h"

/**
 * @brief Class responsible for a single piece of the wall
 */
class Brick : public Object
{
public:
    /**
     * Creating a wall piece at position (0, 0)
     */
    Brick();
    /**
     * Creating a wall
     * @param x - Initial horizontal position
     * @param y - Initial vertical position
     */
    Brick(double x, double y);

    /**
     * The function was implemented to avoid modifying collision_rect
     * @param dt - time since the last function call
     */
    void update(Uint32 dt);
    /**
     * Function that changes the state of a wall after being hit by a bullet. The function modifies collision_rect.
     * @param bullet_direction - direction of the bullet's movement
     */
    void bulletHit(Direction bullet_direction);
private:
    /**
     * Number of bullet hits on the wall
     */
    int m_collision_count;
    /**
     * One of the ten possible states the wall can be in
     */
    int m_state_code;
};

#endif // BRICK_H
