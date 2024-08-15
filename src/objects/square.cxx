#include "square.hxx"
#include "object.hxx"
#include "raylib.h"
#include <cmath>

Square::Square(Vector2 position, float width)
    : ObjectBase(position), width(width)
{}

void Square::draw()
{
    DrawRectangleV(position, Vector2{width, width}, BLACK);
}

bool Square::update()
{
    if (((int) ceilf(currentAnimationDuration) % 4) < 2) {
        this->position.x += 100 * GetFrameTime();
    } else {
        this->position.x -= 100 * GetFrameTime();
    }
    currentAnimationDuration += GetFrameTime();
    return false;
}


Square::~Square() {}
