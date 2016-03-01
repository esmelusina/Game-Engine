#include "Window.h"
#include "Input.h"
#include <iostream>

void main()
{
    auto &window = Window::instance();   
    auto &input = Input::instance();

    window.init();
    input.init();

    while (window.step())
    {
        input.step();

    }    
    window.term();
}