#ifndef SCIANIM_OBJECT
#define SCIANIM_OBJECT
#include <memory>
#include <vector>

#include <raylib.h>

const int ANIMATION_FLAG_SLOW_START = 1;
const int ANIMATION_FLAG_SLOW_END = 1 << 1;

class Animation {
private:
    float duration;
public:
    explicit Animation(float duration) : duration(duration) {}
    float getDuration() { return this->duration; }
};

class MoveAnimation : public Animation {
public:
    Vector2 startPosition;
    Vector2 newPosition;
};

class SleepAnimation : public Animation {};

class RelocateAnimation : public Animation {};


class ObjectBase {
protected:
    Vector2 position;
    Color   color;
    Color   borderColor;
    float   borderThickness;

public:
    explicit ObjectBase(Vector2);
    ObjectBase(Vector2, Color);
    ObjectBase(Vector2, Color, Color, float);
    virtual inline ~ObjectBase() {};


public: // Object Properties
    inline void setColor(Color color) { this->color = color; }
    [[ nodiscard ]] inline const Color& getColor() const { return this->color; }

    inline void setBorderColor(Color borderColor) { this->borderColor = borderColor; }
    [[ nodiscard ]] inline const Color& getBorderColor() const { return this->borderColor; }

    inline void setBorderThickness(float borderThickness) { this->borderThickness = borderThickness > 0.0f ? borderThickness : 0.0f; }
    [[ nodiscard ]] inline float getBorderThickness() const { return this->borderThickness; }

public: // Animations


public: // abstract methods
    virtual void draw(float) = 0;
    virtual void update(float) = 0;
};
#endif
