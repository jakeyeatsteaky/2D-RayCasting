#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "DataStructures.h"

class Obstacle 
{
public:
    Obstacle(): start(Vec2<float>(0,0)), end(Vec2<float>(0,0)) {}
    Obstacle(Vec2<float> start, Vec2<float> end): start(start), end(end) {}
    ~Obstacle() = default;
    Vec2<float>& getStartPoint() {return start;}
    Vec2<float>& getEndPoint() {return end;}
    

    Vec2<float> start;
    Vec2<float> end;
private:
};

#endif