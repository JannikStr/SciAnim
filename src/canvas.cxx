#include "canvas.hxx"
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
    for(auto &object : this->objects)
    {
        object->draw();
    }
}

void Canvas::setTime(float time)
{
    this->currentTime = time;
}

void Canvas::addObject(std::shared_ptr<ObjectBase> object)
{
    this->objects.emplace_back(object);
}
