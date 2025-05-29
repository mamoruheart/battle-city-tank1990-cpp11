#ifndef ENGINE_H
#define ENGINE_H

#include "renderer.h"
#include "spriteconfig.h"

/**
 * @brief Class combines elements related to the program's operation
 */
class Engine
{
public:
    Engine();

    /**
     * @return static instance of @a Engine object
     */
    static Engine& getEngine(); // the engine can be accessible in every module using only the namespace and not a pointer
    /**
     * Function converts the given numeric value to text
     * @param num - integer
     * @return integer as text
     */
    static std::string intToString(int num);
    /**
     * Function creates component objects of the engine
     */
    void initModules();
    /**
     * Function destroys component objects of the engine
     */
    void destroyModules();

    /**
     * @return pointer to Renderer object allowing drawing on the screen
     */
    Renderer* getRenderer() const;
    /**
     * @return pointer to SpriteConfig object storing information about textures
     */
    SpriteConfig* getSpriteConfig() const;
private:
    Renderer* m_renderer;
    SpriteConfig* m_sprite_config;
};

#endif // ENGINE_H
