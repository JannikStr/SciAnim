#ifndef SCIANIM_CANVAS
#define SCIANIM_CANVAS

#include "objects/object.hxx"
#include <memory>
#include <vector>
class Canvas {
    float currentTime;
    std::vector<std::shared_ptr<ObjectBase>> objects;

public:
    Canvas() : currentTime(0), objects() {}

    void addObject(std::shared_ptr<ObjectBase> object);

    void update(float currentTime);
    void draw(float currentTime);
    void setTime(float time);

};

#endif
