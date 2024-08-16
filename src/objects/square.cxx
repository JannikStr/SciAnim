#include <raylib.h>
#include <raymath.h>
#include <cmath>

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
    DrawRectangleV(position, Vector2{width, width}, this->getColor());
    if(this->borderThickness > 0) {
        DrawRectangleLinesEx(Rectangle{this->position.x, this->position.y, this->width, this->width}, this->borderThickness, this->borderColor);
    }
}

void Square::update(float currentTime)
{
}


Square::~Square() {}
