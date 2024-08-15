#ifndef SCIANIM_SQUARE
#define SCIANIM_SQUARE

#include "object.hxx"

class Square : public ObjectBase {
private:
    float width;
public:
    Square(Vector2 position, float width);

    void draw() override;
    bool update() override;

    ~Square() override;

};

#endif
