#include <raylib.h>
#include <raymath.h>
#include <cmath>

#include "square.hxx"
#include "object.hxx"

Square::Square(Vector2 position, float width)
    : ObjectBase(position), width(width)
{}

void Square::draw()
{
    DrawRectangleV(position, Vector2{width, width}, this->getColor());
}

void Square::update()
{
}


Square::~Square() {}
