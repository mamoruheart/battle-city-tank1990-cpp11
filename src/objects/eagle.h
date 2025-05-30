#ifndef EAGLE_H
#define EAGLE_H

#include "object.h"

/**
 * @brief The class of the eagle that players are to defend and opponents to destroy
 */
class Eagle : public Object
{
public:
    /**
     * Creating the eagle at position (0, 0)
     */
    Eagle();
    /**
     * Creating the eagle
     * @param x - initial horizontal position
     * @param y - initial vertical position
     */
    Eagle(double x, double y);
    /**
     * Updating the eagle animation
     * @param dt - time since the last function call
     */
    void update(Uint32 dt);
    /**
     * Triggering the eagle's explosion
     */
    void destroy();
};

#endif // EAGLE_H
