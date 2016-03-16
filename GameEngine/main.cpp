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
#include "RenderSystem.h"
#include "Assets.h"

void main()
{
    auto &window = Window::instance();   
    auto &input  = Input::instance();
    auto &time   = Time::instance();

    window.init();
    input.init();
    time.init();

    Asset::instance().loadTexture("Ship", "../textures/spaceship.png");

    //Factory::makeBall({ 40,  40 },  {10,10},  400,  40)->rigidbody->addTorque(1000);
     //        Factory::makeBall({ 80,  200 },  { 100,0}, 120, 120);
    auto e = Factory::makeBall({ 720, 200 }, { }, 60, 1);
    
  
    e->controller = PlayerController::make();
    e->sprite = Sprite::make();
    e->sprite->assetName = "Ship";
    e->sprite->dimension = Vector2{72,72};

    DebugDraw debugDraw;
    RigidbodyDynamics rigidbodies;
    LifetimeSystem lifetimes;
    CollisionDetection collisioner;
    DynamicResolution dynamic;
    PlayerFlightSystem flightsystem;
    RenderSystem render;
    
    while (window.step())
    {
        input.step();
        time.step();

        debugDraw.step();
        flightsystem.step();

        
        rigidbodies.step();
        lifetimes.step();
        
        collisioner.step();
        dynamic.step();
        render.step();

    }    

    time.term();
    input.term();
    window.term();
}