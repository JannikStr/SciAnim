#include "object.hxx"
#include "raylib.h"
#include <algorithm>

ObjectBase::ObjectBase(Vector2 position)
: position(position), color(BLACK), borderColor(BLACK), borderThickness(.0f)
{}

ObjectBase::ObjectBase(Vector2 position, Color backgroundColor)
: position(position), color(backgroundColor), borderColor(BLACK), borderThickness(0.0f)
{}

ObjectBase::ObjectBase(Vector2 position, Color backgroundColor, Color borderColor, float borderThickness)
: position(position), color(backgroundColor), borderColor(borderColor)
{
    this->borderThickness = borderThickness > .0f ? borderThickness : 0.0f;
}
