#ifndef SPRITECONFIG_H
#define SPRITECONFIG_H

#include "../type.h"
#include <map>
#include <SDL2/SDL.h>

/**
 * @brief
 * Structure storing information about a given type of object animation
 */
struct SpriteData
{
    SpriteData() { rect.x = 0; rect.y = 0; rect.w = 0; rect.h = 0; frames_count = 0; frame_duration = 0; loop = false;}
    SpriteData(int x, int y, int w, int h, int fc, int fd, bool l)
        { rect.x = x; rect.y = y; rect.w = w; rect.h = h; frames_count = fc; frame_duration = fd; loop = l;}

    /**
     * Position and dimensions of the first animation frame
     */
    SDL_Rect rect;
    /**
     * Number of frames in the animation
     */
    int frames_count;
    /**
     * Display time of one frame in milliseconds
     */
    unsigned frame_duration;
    /**
     * Variable determining whether the animation is looped
     */
    bool loop;
};

/**
 * @brief
 * Class stores information about all types of animations in the game
 */
class SpriteConfig
{
public:
    /**
     * In the constructor, successive animations are added using the @a SpriteConfig::insert function
     */
    SpriteConfig();
    /**
     * Getting the selected animation type
     * @param sp - searched animation type
     * @return animation of a given type
     */
    const SpriteData* getSpriteData(SpriteType sp) const;
private:
    /**
     * Container storing all animation types
     */
    std::map<SpriteType, SpriteData> m_configs;
    /**
     * Function used when adding a new animation type
     * @param st - animation type
     * @param x - horizontal position of the first animation frame in the texture
     * @param y - vertical position of the first animation frame in the texture
     * @param w - width of animation frames
     * @param h - height of animation frames
     * @param fc - number of frames in the animation
     * @param fd - display time of one frame
     * @param l - Animation looping
     */
    void insert(SpriteType st , int x, int y, int w, int h, int fc, int fd, bool l);
};

#endif // SPRITECONFIG_H
