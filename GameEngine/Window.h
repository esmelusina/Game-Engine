#pragma once
#include <cassert>

#define INIT_ASSERT assert(isInit && "Window is not initialized!")
/*
    There is only ever one window.
    Make details about the window accessible.
*/

/*
    Singleton Pattern:
        Private Constructors
        Public Static Accessor          
*/

class Window
{
    bool isInit;
    unsigned width, height;
    Window() : isInit(false) {}
    
public:

    static Window &instance() { static Window instance; return instance; }
    bool init(unsigned Width = 800, unsigned Height = 600, const char *Title = "Engine");
    bool step();
    void term();

    unsigned getWidth() { INIT_ASSERT; return width; }
    unsigned getHeight() { INIT_ASSERT; return height; }
    bool     isInitialized() { return isInit; }
};

