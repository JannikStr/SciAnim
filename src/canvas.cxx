#include "canvas.hxx"
#include "raylib.h"
#include <memory>

void Canvas::update(float time)
{
    for(auto &object : this->objects)
    {
        object->update();
    }
}

void Canvas::draw(float time)
{
    ClearBackground(this->bgColor);
    for(auto &object : this->objects)
    {
        object->draw();
    }
}

void Canvas::setTime(float time)
{
    this->currentTime = time;
}

