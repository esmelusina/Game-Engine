#include "Window.h"


void main()
{
    auto &window = Window::instance();


    Window::instance().init();
   
    while (window.step())
    {
    
    }
    
    window.term();
}