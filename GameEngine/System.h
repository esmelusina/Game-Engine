#pragma once
#include "Entity.h"

/*
    Piece of logic that updates the rest of the game.
*/

class System
{
    virtual bool condition(Handle<Entity> i) = 0;
    virtual void update   (Handle<Entity> i) = 0;

public:
    void step()
    {
        for (unsigned i = 0; i < Entity::getData().size(); ++i)
            if (Entity::at(i).isValid() && condition(i))
                update(i);
    }
};