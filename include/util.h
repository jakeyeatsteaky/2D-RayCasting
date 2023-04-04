#ifndef UTIL_H
#define UTIL_H
#include <vector>
#include <string>

#include "SDL.h"

#include "DataStructures.h"
#include "Obstacle.h"

enum eAxis
{
    eAxis_x,
    eAxis_y,
    eAxis_z
};

std::vector<Vec3*> vecGen(std::vector<float>& comp);

void TestDotProduct(std::vector<Vec3*>& vecs, float* ans);

float magSquared(Vec3& vec);

// given center of spheres and their radii, write a function to determine if they intersect
bool sphereIntersection(const int x1, const int y1, const int z1, const int x2, const int y2, const int z2, const int r1, const int r2);

void calculatePlane(Vec3& p1, Vec3& p2, Vec3& p3, Plane& plane);

void calculatePlane(Vec3& normal, Vec3& point, Plane& plane);

std::string closerEnemy(Vec3& enemy1Pos, Vec3& enemy2Pos, Vec3& playerPos);

float DotProduct(Vec3& vec1, Vec3& vec2);

float PointPlaneDistance(Plane& plane, Vec3& point);

Vec3 getVecFromSphere(Sphere& s);

Vec3 calculateDirectionVector(Vec3& pointA, Vec3& pointB);

bool CollidingSpheres(Sphere& s1, Sphere& s2);

bool checkBoundingBoxes(std::array<float, 4> aabb1, std::array<float,4> aabb2);

int GenerateRandom(int start, int range);

void SeedRandom();

bool rectIntersection(SDL_Rect& rect1, SDL_Rect& rect2);

Vec3 rotateVector(Vec3& vec, float angleRad, eAxis axisOfRotation);

void rotate(Obstacle* obstacle);

#endif