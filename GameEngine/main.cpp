#include "Window.h"
#include "Input.h"
#include "Time.h"
#include <iostream>
#include "Factory.h"
#include "DebugDraw.h"

void main()
{
    auto &window = Window::instance();   
    auto &input  = Input::instance();
    auto &time   = Time::instance();

    window.init();
    input.init();
    time.init();

    Factory::makeBall({ 40,  40 },  {10,10},  400,  40);
    Factory::makeBall({ 70,  70 },  {40,40},  120,  12);
    Factory::makeBall({ 80, 200 },  {0,100},  280, 200);
    
    DebugDraw debugDraw;
    
    while (window.step())
    {
        input.step();
        time.step();

        debugDraw.step();
    }    

    time.term();
    input.term();
    window.term();
}