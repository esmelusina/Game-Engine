#include "Window.h"
#include "Input.h"
#include "Time.h"
#include <iostream>
#include "Factory.h"
#include "DebugDraw.h"
#include "RigidbodyDynamics.h"
#include "LifetimeSystem.h"

#include "CollisionDetection.h"
#include "DynamicResolution.h"

#include "PlayerFlightSystem.h"

void main()
{
    auto &window = Window::instance();   
    auto &input  = Input::instance();
    auto &time   = Time::instance();

    window.init();
    input.init();
    time.init();

    //Factory::makeBall({ 40,  40 },  {10,10},  400,  40)->rigidbody->addTorque(1000);
     //        Factory::makeBall({ 80,  200 },  { 100,0}, 120, 120);
    auto e = Factory::makeBall({ 720, 200 }, { }, 60, 1);
    
  
    e->controller = PlayerController::make();

    DebugDraw debugDraw;
    RigidbodyDynamics rigidbodies;
    LifetimeSystem lifetimes;
    CollisionDetection collisioner;
    DynamicResolution dynamic;
    PlayerFlightSystem flightsystem;
    
    while (window.step())
    {
        input.step();
        time.step();

        debugDraw.step();
        std::cout << e->rigidbody->torque << std::endl;
        flightsystem.step();

        
        rigidbodies.step();
        lifetimes.step();
        
        collisioner.step();
        dynamic.step();


    }    

    time.term();
    input.term();
    window.term();
}