#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

/**
 * @brief
 * Class is responsible for drawing objects on the screen
 */
class Renderer
{
public:
    Renderer();
    ~Renderer();
    /**
     * Loading texture from file and creating a renderer associated with the application window
     * @param window - pointer to the application window content object
     */
    void loadTexture(SDL_Window* window);
    /**
     * Loading font in three different sizes
     */
    void loadFont();
    /**
     * Clearing the screen buffer
     */
    void clear();
    /**
     * Presentation of the screen buffer
     */
    void flush();
    /**
     * Redrawing a texture fragment onto a screen buffer fragment
     * @param texture_src - source rectangle from texture
     * @param window_dest - destination rectangle on the screen buffer
     */
    void drawObject(const SDL_Rect *texture_src, const SDL_Rect *window_dest);
    /**
     * Setting the scale of the displayed buffer so that it maintains the board's proportions and is positioned in the center of the application window
     * @param xs - horizontal scale as the ratio of window width to map width
     * @param ys - vertical scale as the ratio of window height to map height
     * @see AppConfig::map_rect
     */
    void setScale(float xs, float ys);
    /**
     * Drawing text in the window buffer at the selected starting position
     * @param start - position of the starting point of the drawn text; negative value of either coordinate results in centering the text on that axis
     * @param text - drawn text
     * @param text_color - colors of the drawn text
     * @param font_size - font number with which the text will be drawn; three values available: 1, 2, 3
     */
    void drawText(const SDL_Point* start, std::string text, SDL_Color text_color, int font_size = 1);
    /**
     * Function drawing a rectangle in the window buffer
     * @param rect - position of the rectangle on the board
     * @param rect_color - rectangle color
     * @param fill - variable telling whether the rectangle should be filled
     */
    void drawRect(const SDL_Rect* rect, SDL_Color rect_color, bool fill = false);

private:
    /**
     * Pointer to an object associated with the window buffer
     */
    SDL_Renderer* m_renderer;
    /**
     * Pointer to a texture containing all visible game elements
     */
    SDL_Texture* m_texture;
    /**
     * Pointer to an auxiliary texture for drawing text on the screen
     */
    SDL_Texture* m_text_texture;
    /**
     * Font with size 28
     */
    TTF_Font* m_font1;
    /**
     * Font with size 14
     */
    TTF_Font* m_font2;
    /**
     * Font with size 10
     */
    TTF_Font* m_font3;
};

#endif // RENDERER_H
