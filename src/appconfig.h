#ifndef APPCONFIG_H
#define APPCONFIG_H

#include "objects/player.h"
#include <iostream>
#include <SDL2/SDL_rect.h>
#include <vector>

using namespace std;

/**
 * @brief A class containing a collection of application parameters.
 */
class AppConfig
{
public:
    /**
     * Path to the object texture.
     */
    static string texture_path;
    /**
     * Path to the directory with levels.
     */
    static string levels_path;
    /**
     * Path to the font.
     */
    static string font_name;
    /**
     * Text displayed after losing.
     */
    static string game_over_text;
    /**
     * Dimensions of the game board.
     */
    static SDL_Rect map_rect;
    /**
     * Dimensions and position of the game status area relative to the game board.
     */
    static SDL_Rect status_rect;
    /**
     * Size of the application window.
     */
    static SDL_Rect windows_rect;
    /**
     * Size of a cell on the board.
     */
    static SDL_Rect tile_rect;
    /**
     * Two starting positions of the players.
     */
    static vector<SDL_Point> player_starting_point;
    /**
     * Three starting positions of the enemies.
     */
    static vector<SDL_Point> enemy_starting_point;
    /**
     * Control of the players' tanks.
     */
    static vector <Player::PlayerKeys> player_keys;
    /**
     * Duration of displaying the round number at its start.
     */
    static unsigned level_start_time;
    /**
     * Duration of sliding on ice in milliseconds.
     */
    static unsigned slip_time;
    /**
     * Number of enemies to kill during one round.
     */
    static unsigned enemy_start_count;
    /**
     * Time after which a new enemy can appear on the map, in milliseconds.
     */
    static unsigned enemy_redy_time;
    /**
     * Default maximum number of bullets the player can shoot.
     */
    static unsigned player_bullet_max_size;
    /**
     * Time for displaying the scores after the points countdown ends, in milliseconds.
     */
    static unsigned score_show_time;
    /**
     * Duration for which the bonus is visible on the map, in milliseconds.
     */
    static unsigned bonus_show_time;
    /**
     * Duration of the shield's effect in milliseconds.
     */
    static unsigned tank_shield_time;
    /**
     * Duration for which enemies are frozen, in milliseconds.
     */
    static unsigned tank_frozen_time;
    /**
     * Time between defeating all enemies and transitioning to the results screen, in milliseconds.
     */
    static unsigned level_end_time;
    /**
     * Duration of the stone shield around the eagle, in milliseconds.
     */
    static unsigned protect_eagle_time;
    /**
     * Bonus blinking duration in milliseconds.
     */
    static unsigned bonus_blink_time;
    /**
     * Minimum time between player’s shots in milliseconds.
     */
    static unsigned player_reload_time;
    /**
     * Maximum number of tanks on the map at one time.
     */
    static int enemy_max_count_on_map;
    /**
     * Speed of the 'GAME OVER' text movement.
     */
    static double game_over_entry_speed;
    /**
     * Nominal speed of the tank.
     */
    static double tank_default_speed;
    /**
     * Nominal speed of the bullet.
     */
    static double bullet_default_speed;
    /**
     * Variable storing information about whether showing enemy targets has been enabled.
     */
    static bool show_enemy_target;
};

#endif // APPCONFIG_H
