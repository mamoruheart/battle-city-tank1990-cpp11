#ifndef GAME_H
#define GAME_H
#include "appstate.h"
#include "../objects/object.h"
#include "../objects/player.h"
#include "../objects/enemy.h"
#include "../objects/bullet.h"
#include "../objects/brick.h"
#include "../objects/eagle.h"
#include "../objects/bonus.h"
#include <vector>
#include <string>

/**
 * @brief The class is responsible for the movement of all tanks as well as interactions between tanks and between tanks and other objects on the map
 */
class Game : public AppState
{
public:
    /**
     * Default constructor – enables single-player mode
     */
    Game();
    /**
     * Constructor allowing to specify the initial number of players. The number of players can be either 1 or 2; any other value will start the game in single-player mode.
     * The constructor is called in @a Menu::nextState.
     * @param players_count - Number of players: 1 or 2
     */
    Game(int players_count);
    /**
     * Constructor accepting already existing players
     * Called in @a Score::nextState
     * @param players - Container with players
     * @param previous_level - Variable storing the number of the previous level
     */
    Game(std::vector<Player*> players, int previous_level);

    ~Game();
    /**
     * The function returns @a true if the player has destroyed all enemies or if the eagle has been hit or the player has lost all lives - meaning the game is over.
     * @return @a true or @a false
     */
    bool finished() const;
    /**
     * The function displays the round number at the start of the round. During gameplay, the function is responsible for drawing the level (walls, stones, water, ice, bushes),
     * players, enemies, bonuses, the eagle, and the game status on the right panel (remaining enemies, remaining player lives, round number).
     * After losing or during a pause, it displays the appropriate message in the center of the screen.
     */
    void draw();
    /**
     * The function updates the state of all objects on the board (tanks, bonuses, obstacles). It also checks collisions between tanks, between tanks and level elements, and between projectiles and tanks and map elements.
     * This is where destroyed objects are removed, new enemy tanks are added, and the conditions for ending the round are checked.
     * @param dt - Time since the last function call in milliseconds.
     */
    void update(Uint32 dt);
    /**
     * Here, the reaction to key presses occurs:
     * @li Enter - Game pause
     * @li Esc - Return to menu
     * @li N - Proceed to the next round if the game is not lost
     * @li B - Go back to the previous round if the game is not lost
     * @li T - Show paths to enemy tanks’ targets
     * @param ev - Pointer to an SDL_Event union storing the type and parameters of various events, including keyboard events.
     */
    void eventProcess(SDL_Event* ev);
    /**
     * Transition to the next state.
     * @return Pointer to an object of class @a Scores if the player has completed the round or lost. If the player pressed Esc, the function returns a pointer to the @a Menu object.
     */
    AppState* nextState();

private:
    /**
     * Loading the level map from a file
     * @param path - Path to the map file
     */
    void loadLevel(std::string path);
    /**
     * Removing remaining enemies, players, map objects, and bonuses
     */
    void clearLevel();
    /**
     * Loading a new level and creating new players if they do not already exist.
     * @see Game::loadLevel(std::string path)
     */
    void nextLevel();
    /**
     * Creating a new enemy if the number of opponents on the map is less than 4, assuming that not all 20 enemies have already been created on the map.
     * The function generates different enemy armor levels depending on the level; the higher the round number, the greater the chance that the enemy will have the fourth armor level.
     * The armor level number indicates how many times the enemy must be hit by a projectile to be destroyed. This number ranges from 1 to 4 and corresponds to different tank colors.
     * The generated enemy has an additional chance that hitting it will cause a bonus to appear on the map.
     */
    void generateEnemy();
    /**
     * The function generates a random bonus on the map and places it in a position that does not collide with the eagle.
     */
    void generateBonus();

    /**
     * Check if the tank can freely move forward; if not, it stops it. The function prevents moving outside the game board.
     * If the tank drives onto ice, it causes it to slip. If the tank has the "Boat" bonus, it can pass through water. Tanks cannot pass through the eagle.
     * @param tank - The tank for which we are checking collisions
     * @param dt - The last time change; assuming small changes in subsequent time steps, we can predict the tank's next position and respond accordingly.
     */
    void checkCollisionTankWithLevel(Tank* tank, Uint32 dt);
    /**
     * Check if there is a collision between the tanks being examined; if so, both are stopped.
     * @param tank1
     * @param tank2
     * @param dt
     */
    void checkCollisionTwoTanks(Tank* tank1, Tank* tank2, Uint32 dt);
    /**
     * Check if the selected projectile collides with any map element (water and ice are ignored). If so, both the projectile and the object are destroyed.
     * If the eagle is hit, it results in a loss (game over).
     * @param bullet - bullet, missile
     */
    void checkCollisionBulletWithLevel(Bullet* bullet);
    /**
     * Checking collision of a projectile with bushes on the map. The bushes and the projectile are destroyed if the projectile has increased damage.
     * @param bullet - bullet, missile
     * @see Bullet::increased_damage
     */
    void checkCollisionBulletWithBush(Bullet* bullet);
    /**
     * Checking whether a given player hit a selected enemy. If so, the player earns points and the enemy loses one armor level.
     * @param player - player
     * @param enemy - enemy
     */
    void checkCollisionPlayerBulletsWithEnemy(Player* player, Enemy* enemy);
    /**
     * Check if the enemy hit the player with a projectile. If so, the player loses one life unless they had a shield.
     * @param enemy - player
     * @param player - enemy
     */
    void checkCollisionEnemyBulletsWithPlayer(Enemy* enemy, Player* player);
    /**
     * If two projectiles collide, both are destroyed.
     * @param bullet1
     * @param bullet2
     */
    void checkCollisionTwoBullets(Bullet* bullet1, Bullet* bullet2);
    /**
     * Check if the player has collected a bonus. If so, the appropriate action occurs:
     * @li Grenade – all visible enemies are destroyed
     * @li Helmet – the player gets temporary protection from all projectiles
     * @li Clock – freezes visible enemies
     * @li Shovel – temporarily creates a stone wall around the eagle
     * @li Tank – increases the player's number of lives by 1
     * @li Star – upgrades the player's tank (increases speed and number of projectiles)
     * @li Weapon - maximum player upgrade
     * @li Boat - ability to pass through water
     * For collecting a bonus, the player receives additional points.
     * @param player
     * @param bonus
     */
    void checkCollisionPlayerWithBonus(Player* player, Bonus* bonus);

    /**
     * Number of columns in the map grid
     */
    int m_level_columns_count;
    /**
     * Number of rows in the map grid
     */
    int m_level_rows_count;
    /**
     * Obstacles on the map
     */
    std::vector< std::vector <Object*> > m_level;
    /**
     * Bushes on the map
     */
    std::vector<Object*> m_bushes;

    /**
     * Set of enemies
     */
    std::vector<Enemy*> m_enemies;
    /**
     * Set of remaining players
     */
    std::vector<Player*> m_players;
    /**
     * Set of killed players
     */
    std::vector<Player*> m_killed_players;
    /**
     * Set of bonuses on the map
     */
    std::vector<Bonus*> m_bonuses;
    /**
     * Eagle object
     */
    Eagle* m_eagle;

    /**
     * Current level number
     */
    int m_current_level;
    /**
     * Number of players in the selected game mode (1 or 2)
     */
    int m_player_count;
    /**
     * Number of remaining enemies to kill on the current level
     */
    int m_enemy_to_kill;

    /**
     * Variable that stores whether the level start screen is currently being displayed
     */
    bool m_level_start_screen;
    /**
     * Variable that stores whether the eagle is protected by the stone wall
     */
    bool m_protect_eagle;
    /**
     * Time for which the level start screen has already been displayed
     */
    Uint32 m_level_start_time;
    /**
     * Time since the last enemy creation
     */
    Uint32 m_enemy_redy_time;
    /**
     * Time that has passed since winning the map
     */
    Uint32 m_level_end_time;
    /**
     * Time how long the little eagle has been protected by the stone wall
     */
    Uint32 m_protect_eagle_time;

    /**
     * Defeat state
     */
    bool m_game_over;
    /**
     * Position of the 'GAME OVER' text if @a m_game_over equals @a true
     */
    double m_game_over_position;
    /**
     * Variable stores information on whether the current game state should be ended and transition to displaying results or the game menu
     */
    bool m_finished;
    /**
     * Variable tells whether pause has been activated
     */
    bool m_pause;
    /**
     * Number of the position of the newly created enemy. Changed with each enemy creation.
     */
    int m_enemy_respown_position;
};

#endif // GAME_H
