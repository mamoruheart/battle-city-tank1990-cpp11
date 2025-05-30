#ifndef TANK_H
#define TANK_H

#include "object.h"
#include "bullet.h"
#include "../type.h"

#include <vector>

typedef unsigned TankStateFlags;

/**
 * @brief
 * Class responsible for the basic mechanics of tanks: driving and shooting
 */
class Tank : public Object
{
public:
    /**
     * Creating a tank at the first of the enemy positions
     * @see AppConfig::enemy_starting_point
     */
    Tank();
    /**
     * Creating a tank
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param type - tank type
     */
    Tank(double x, double y, SpriteType type);
    virtual ~Tank();

    /**
     * The function draws the image of the tank, and if necessary, it also draws the shield and the boat
     * Calls the drawing of projectiles
     */
    void draw();
    /**
     * The function is responsible for changing the tank’s position, updating the positions of the dest_rect and collision_rect rectangles, the positions of shields and boats, the tank’s animation,
     * calling the projectile update, and removing destroyed projectiles. The function also counts down the time for having a shield and freezing, and disables these flags
     * @param dt - Time since the last function call, used for changing the animation
     */
    void update(Uint32 dt);
    /**
     * The function is responsible for creating a projectile if the maximum number of projectiles has not yet been created
     * @return Pointer to the created projectile; if no projectile has been created, returns @a nullptr
     */
    virtual Bullet* fire();
    /**
     * The function returns the collision rectangle that would be in the next frame assuming the velocity and direction are the same as the current ones
     * @param dt - estimated time for calculating the next frame
     * @return next collision rectangle
     */
    SDL_Rect nextCollisionRect(Uint32 dt);
    /**
     * The function sets the next movement direction taking into account slipping on ice. When changing direction, the tank is aligned to multiples of the board cell dimensions @a AppConfig::tile_rect
     * @param d - new direction
     */
    void setDirection(Direction d);
    /**
     * The function stops the tank
     * @param intersect_rect - collison area
     */
    void collide(SDL_Rect &intersect_rect);
    /**
     * The function is responsible for clearing all flags and starting the tank creation animation
     */
    virtual void respawn();
    /**
     * The function is responsible for starting the tank explosion animation
     */
    virtual void destroy();
    /**
     * Setting the selected flag
     * @param flag
     */
    void setFlag(TankStateFlag flag);
    /**
     * Clearing the selected flag
     * @param flag
     */
    void clearFlag(TankStateFlag flag);
    /**
     * Checking whether the selected flag is set
     * @param flag
     * @return @a true if the flag is set, otherwise @a false
     */
    bool testFlag(TankStateFlag flag);

    /**
     * The default speed of a given tank. It may vary for different types of tanks or can be changed after the player picks up a bonus
     */
    double default_speed;
    /**
     * Current speed of the tank
     */
    double speed;
    /**
     * The variable stores information about whether the tank is currently stopped
     */
    bool stop;
    /**
     * The variable stores the current driving direction of the tank
     */
    Direction direction;
    /**
     * Container with the tank's fired projectiles
     */
    std::vector<Bullet*> bullets;
    /**
     * The number of player lives or the armor level number of the enemy tank
     */
    int lives_count;

protected:
    /**
     * Flags that the tank currently has
     */
    TankStateFlags m_flags;
    /**
     * Time since the slip occurred
     */
    Sint32 m_slip_time;
    /**
     * It corresponds to the tank's orientation during a slip and may differ from the direction of the tank's movement on ice
     */
    Direction new_direction;
    /**
     * The maximum number of projectiles a tank can fire
     */
    unsigned m_bullet_max_size;

    /**
     * Pointer to the tank's shield. If the tank does not have a shield, the variable has the value nullptr;
     */
    Object* m_shield;
    /**
     * Pointer to the boat that the tank may have. If the tank does not have a boat, the variable has the value nullptr;
     */
    Object* m_boat;
    /**
     * Time since acquiring the shield
     */
    Uint32 m_shield_time;
    /**
     * Time since the tank was frozen
     */
    Uint32 m_frozen_time;
};

#endif // TANK_H
