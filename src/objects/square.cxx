#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>
#include <raylib.h>
#include <raymath.h>
#include <cmath>

#include "animations/animation.hxx"
#include "square.hxx"
#include "object.hxx"

Square::Square(Vector2 position, float width)
: ObjectBase(position), width(width)
{}

Square::Square(Vector2 position, float width, Color backgroundColor)
: ObjectBase(position, backgroundColor), width(width)
{}

Square::Square(Vector2 position, float width, Color backgroundColor, Color borderColor, float borderThickness)
: ObjectBase(position, backgroundColor, borderColor, borderThickness), width(width)
{}

void Square::draw(float currentTime)
{
    Vector2 centered_pos = Vector2Subtract(position, Vector2{width/2, width/2});
    DrawRectangleV(centered_pos, Vector2{width, width}, this->getColor());
    if(this->borderThickness > 0) {
        DrawRectangleLinesEx(Rectangle{centered_pos.x, centered_pos.y, this->width, this->width}, this->borderThickness, this->borderColor);
    }

#ifdef SCIANIM_DEBUG
    DrawCircleV(position, 2, GREEN);
#endif
}

void Square::update(float currentTime)
{
    ObjectBase::update(currentTime);
}


Square::~Square() {}
