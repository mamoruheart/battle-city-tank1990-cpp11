#ifndef OBJECT_H
#define OBJECT_H

#include "../engine/engine.h"

/**
 * @brief
 * Base class for objects in the game
 */
class Object
{
public:
    /**
     * Creating an object at position (0, 0)
     */
    Object();
    /**
     * Creating an object
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param type - type of object
     */
    Object(double x, double y, SpriteType type);
    /**
     * Creating an object
     * @param x - initial horizontal position
     * @param y - initial vertical position
     * @param sprite - animation of an object of a given type
     */
    Object(double x, double y, const SpriteData* sprite);
    virtual ~Object();

    /**
     * Drawing an object using the method @a drawObject from the @a Renderer class, from a texture with coordinates src_rect onto a map area with coordinates dest_rect
     */
    virtual void draw();
    /**
     * Updating the rectangle dest_rect based on the object's position: pos_x, pos_y. Counting down the display time of one animation frame and changing the frame after the appropriate time has elapsed.
     * @param dt - time since the last function call, used for counting the frame display time
     */
    virtual void update(Uint32 dt);

    /**
     * A variable indicates whether the object should be deleted. If the variable is equal to @a true, then updating and drawing the object is skipped.
     */
    bool to_erase;
    /**
     * Collision rectangle; it may be smaller than the dimensions of dest_rect.
     */
    SDL_Rect collision_rect;
    /**
     * The target position of the object on the screen
     */
    SDL_Rect dest_rect;
    /**
     * Position on the texture of the currently displayed frame
     */
    SDL_Rect src_rect;
    /**
     * Type of object
     */
    SpriteType type;
    /**
     * Exact horizontal position of the object
     */
    double pos_x;
    /**
     * Exact vertical position of the object
     */
    double pos_y;

protected:
    /**
     * The function returns a rectangle shifted by a multiple of the size of the rectangle rect
     * @param rect - base rectangle
     * @param x - horizontal shift
     * @param y - vertical shift
     * @return shifted rectangle
     */
    SDL_Rect moveRect(const SDL_Rect &rect, int x, int y);

    /**
     * Animation corresponding to a given type of object
     */
    const SpriteData* m_sprite;
    /**
     * Display time of the current animation frame
     */
    Uint32 m_frame_display_time;
    /**
     * Number of the current animation frame
     */
    int m_current_frame;
};

/**
 * A function that determines the intersection (common area) of two rectangles
 * @param rect1
 * @param rect2
 * @return The intersection (common part); if rect1 and rect2 do not have a common area, the resulting rectangle will have negative dimensions
 */
SDL_Rect intersectRect(SDL_Rect* rect1, SDL_Rect* rect2);

#endif // OBJECT_H
