#pragma once
#include "VMath.h"
#include "GCData.h"

class Rigidbody : public GCData<Rigidbody>
{
public:
    float mass;

    Vector2 velocity, acceleration, force, jerk;
    float drag;

    Rigidbody();
    void addForce(const Vector2 &);

    void integrate(class Transform *, float dt);
};