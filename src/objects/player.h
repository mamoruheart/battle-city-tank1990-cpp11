#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"

/**
 * @brief Class corresponding to player tanks
 */
class Player : public Tank
{
public:

    /**
     * @brief Structure storing the keys corresponding to player tank controls
     */
    struct PlayerKeys
    {
        PlayerKeys(): up(SDL_SCANCODE_UNKNOWN), down(SDL_SCANCODE_UNKNOWN), left(SDL_SCANCODE_UNKNOWN), right(SDL_SCANCODE_UNKNOWN), fire(SDL_SCANCODE_UNKNOWN) {}
        PlayerKeys(SDL_Scancode u, SDL_Scancode d, SDL_Scancode l, SDL_Scancode r, SDL_Scancode f): up(u), down(d), left(l), right(r), fire(f) {}
        /**
         * Key corresponding to moving upward
         */
        SDL_Scancode up;
        /**
         * Key corresponding to moving downward
         */
        SDL_Scancode down;
        /**
         * Key corresponding to moving left
         */
        SDL_Scancode left;
        /**
         * Key corresponding to moving right
         */
        SDL_Scancode right;
        /**
         * Key corresponding to firing a projectile
         */
        SDL_Scancode fire;
    };

    /**
     * Creating a player at the first of the player positions
     * @see AppConfig::player_starting_point
     */
    Player();
    /**
     * Creating a player’s tank
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param type - player type
     */
    Player(double x, double y, SpriteType type);

    /**
     * The function is responsible for changing the player tank’s animation as well as checking the state of pressed keys and reacting to those keys that control the player’s tank
     * @param dt - Time since the last function call, used for changing the animation
     */
    void update(Uint32 dt);
    /**
     * The function is responsible for subtracting life, clearing all flags, and triggering the tank respawn animation
     */
    void respawn();
    /**
     * The function is responsible for triggering the tank explosion animation if the tank did not have a shield, a boat, or three stars
     */
    void destroy();
    /**
     * The function is responsible for creating a projectile if the maximum number has not yet been created,
     * assigning it increased speed if the player has at least one star, and adding increased damage if the player has three stars.
     * @return A pointer to the created projectile; if no projectile was created, it returns a @a nullptr
     */
    Bullet* fire();

    /**
     * The function changes the current number of stars owned. If the number of stars is non-zero, the tank's default speed is increased,
     * and if the number of stars is greater than 1 and for each positive @a c, the maximum number of projectiles is increased.
     * @param c - change in the number of stars, can be negative
     */
    void changeStarCountBy(int c);

    /**
     * Keys controlling the movements of the current player
     */
    PlayerKeys player_keys;
    /**
     * Points currently held by the player
     */
    unsigned score;

private:
    /**
     * The current number of stars held; can range from [0, 3]
     */
    int star_count;
    /**
     * The time that has passed since the last projectile was fired
     */
    Uint32 m_fire_time;
};

#endif // PLAYER_H
