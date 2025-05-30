#ifndef BULLET_H
#define BULLET_H

#include "object.h"

/**
 * @brief Class responsible for projectiles fired by tanks
 */
class Bullet : public Object
{
public:
    /**
     * Creating a projectile at position (0, 0)
     */
    Bullet();
    /**
     * Creating a projectile (missile)
     * @param x - initial horizontal position
     * @param y - initial vertical position
     */
    Bullet(double x, double y);

    /**
     * Updating the position of the projectile
     * @param dt - time since the last function call
     */
    void update(Uint32 dt);
    /**
     * Enabling the projectile explosion animation
     */
    void destroy();
    
    /**
     * The speed of the projectile's movement
     */
    double speed;
    /**
     * The variable stores information about whether the projectile has collided with something
     */
    bool collide;
    /**
     * The variable stores information about whether the projectile has increased damage
     * Increased damage allows destroying stone walls and bushes
     */
    bool increased_damage;
    /**
     * The direction of the projectile's movement
     */
    Direction direction;
};

#endif // BULLET_H
