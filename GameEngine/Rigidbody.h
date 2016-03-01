#pragma once
#include "VMath.h"

class Rigidbody
{
public:
    float mass;

    Vector2 velocity, acceleration, force, jerk;
    float drag;

    Rigidbody();
    void addForce(const Vector2 &);

    void integrate(class Transform *, float dt);
};