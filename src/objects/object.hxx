#ifndef SCIANIM_OBJECT
#define SCIANIM_OBJECT
#include <memory>
#include <vector>

#include <raylib.h>

#include "animations/animation.hxx"

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
    inline void setPosition(Vector2 position) { this->position = position; }
    [[ nodiscard ]] inline const Vector2& getPosition() const { return position; }

    inline void setColor(Color color) { this->color = color; }
    [[ nodiscard ]] inline const Color& getColor() const { return this->color; }

    inline void setBorderColor(Color borderColor) { this->borderColor = borderColor; }
    [[ nodiscard ]] inline const Color& getBorderColor() const { return this->borderColor; }

    inline void setBorderThickness(float borderThickness) { this->borderThickness = borderThickness > 0.0f ? borderThickness : 0.0f; }
    [[ nodiscard ]] inline float getBorderThickness() const { return this->borderThickness; }

private: // Animations
    std::vector<std::shared_ptr<Animation>> animations;
protected:
    float getStartingTime();
public:

    std::shared_ptr<const Animation> getCurrentAnimation(float);

    void move(Vector2 startingPosition, Vector2 targetPosition, float duration);
    void delay(float delay);


public: // abstract methods
    virtual void draw(float) = 0;
    virtual void update(float);
};
#endif
