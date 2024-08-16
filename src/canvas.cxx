#include "canvas.hxx"
#include "raylib.h"
#include <memory>

void Canvas::update()
{
    for(auto &object : this->objects)
    {
        object->update(this->currentTime);
    }
    this->currentTime += GetFrameTime();
}

void Canvas::draw()
{
    ClearBackground(this->bgColor);
    for(auto &object : this->objects)
    {
        object->draw(this->currentTime);
    }
}

void Canvas::setTime(float time)
{
    this->currentTime = time;
}

