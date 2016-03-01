#include "Window.h"
#include "sfwdraw.h"

bool Window::init(unsigned Width, unsigned Height, const char * Title)
{
    isInit = sfw::initContext(Width, Height, Title);
    return isInit;
}

bool Window::step() { INIT_ASSERT; return sfw::stepContext(); }

void Window::term() { INIT_ASSERT; sfw::termContext(); isInit = false; }

