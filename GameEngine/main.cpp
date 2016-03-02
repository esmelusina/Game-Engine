#include "Window.h"
#include "Input.h"
#include "Time.h"
#include <iostream>
#include "Entity.h"

void main()
{
    auto &window = Window::instance();   
    auto &input  = Input::instance();
    auto &time   = Time::instance();

    window.init();
    input.init();
    time.init();


    auto e       = Entity   ::make();
    e->transform = Transform::make();
    e->rigidbody = Rigidbody::make();
    e->collider  = Collider ::make();
    

    while (window.step())
    {
        input.step();
        time.step();
    }    

    time.term();
    input.term();
    window.term();
}