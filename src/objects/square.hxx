#ifndef SCIANIM_SQUARE
#define SCIANIM_SQUARE

#include "object.hxx"

class Square : public ObjectBase {
private:
    float width;
public:
    Square(Vector2 position, float width);
    Square(Vector2 position, float width, Color backgroundColor);
    Square(Vector2 position, float width, Color backgroundColor, Color borderColor, float borderThickness);

    void draw(float) override;
    void update(float) override;

    ~Square() override;

};

#endif
