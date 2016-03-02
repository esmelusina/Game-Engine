#pragma once
#include "Shapes.h"
#include "collision.h"
#include "Transform.h"
#include "GCData.h"
// Shapes!


struct Collider : GCData<Collider>
{
    enum SHAPE {e_CIRCLE = 1, e_AABB = 2, e_RAY = 4, e_PLANE = 8} shape;
    union
    {
        Circle  circle;
        AABB    aabb;
        Ray     ray;
        Plane   plane;
    };
    
    ConvexHull chull;
};

CollisionData EvaluateCollision(const Transform &at, const Collider &ac,
                                const Transform &bt, const Collider &bc);


/*
template<typename T>
class ColliderT
{
public:
    T shape;
    ConvexHull chull;
    operator const T&() const { return shape; }
};

template<typename T, typename R>
inline CollisionData EvaluateCollisionT(const Transform &at, const ColliderT<T> &ac,
                                        const Transform &bt, const ColliderT<R> &bc)
{
    return itest(at.getGlobalTransform() * ac, bt.getGlobalTransform() * bt);
}
*/