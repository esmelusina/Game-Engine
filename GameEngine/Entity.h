#pragma once
#include "GCData.h"

#include "Collider.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Lifespan.h"

struct Entity : GCData<Entity>
{
    Handle<Transform> transform;
    Handle<Rigidbody> rigidbody;
    Handle<Lifecycle> lifecycle;
    Handle<Collider > collider;

    void onFree()
    {
        Transform::free(transform.index);
        Rigidbody::free(rigidbody.index);
        Lifecycle::free(lifecycle.index);
        Collider ::free( collider.index);
    }
};

