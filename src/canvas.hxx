#ifndef SCIANIM_CANVAS
#define SCIANIM_CANVAS

#include "objects/object.hxx"
#include <memory>
#include <type_traits>
#include <vector>
class Canvas {
    float currentTime;
    std::vector<std::shared_ptr<ObjectBase>> objects;

    Color bgColor;

public:
    Canvas() : currentTime(0), objects(), bgColor(DARKGRAY) {}

    template<typename T, std::enable_if_t<std::is_base_of_v<ObjectBase, T>, bool> Dummy = true>
    std::shared_ptr<T>  addObject(const T& object);

    void update(float currentTime);
    void draw(float currentTime);

public:
    void setTime(float time);

    void setBackgroundColor(Color color) { this->bgColor = color; }
    [[ nodiscard ]] const Color& getBackgroundColor() const { return this->bgColor; }
};

template<typename T, std::enable_if_t<std::is_base_of_v<ObjectBase, T>, bool> Dummy>
std::shared_ptr<T> Canvas::addObject(const T& object)
{
    std::shared_ptr<T> stored_object = std::make_shared<T>(object);
    this->objects.emplace_back(stored_object);
    return stored_object;
}


#endif
