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

template<typename T>
class IWindow
{
    unsigned width, height;

protected:
    IWindow() : isInit(false) {}

public:
    bool isInit;

    static T &instance() { static T instance; return instance; }

    virtual bool init(unsigned Width = 800, unsigned Height = 600, const char *Title = "Engine") = 0;
    virtual bool step() = 0;
    virtual void term() = 0;

    unsigned getWidth()      { INIT_ASSERT; return width; }
    unsigned getHeight()     { INIT_ASSERT; return height; }
    bool     isInitialized() { return isInit; }
};



// Curiously Recursive Template Pattern
class Window : public IWindow<Window>
{
    // friends can access private members
    friend class IWindow<Window>;
    Window() {}

public:
    bool init(unsigned Width = 800, unsigned Height = 600, const char *Title = "Engine");
    bool step();
    void term();
};