#ifndef SCIANIM_OBJECT
#define SCIANIM_OBJECT
#include "raylib.h"
#include <vector>

struct KeyFrame {
    float duration;
    float endDuration;
    Vector2 kfPosition;
};

class ObjectBase {
protected:
    Vector2 position;
    float currentAnimationDuration;
    std::vector<KeyFrame> keyFrames;
public:
    explicit ObjectBase(Vector2);

    void addKeyFramePosition(float duration, Vector2 kfPosition);
    [[ nodiscard ]] const KeyFrame& getNextKeyFrame(float totalDuration);

public:
    virtual void draw() = 0;
    virtual bool update() = 0;

    virtual ~ObjectBase() {}
};
#endif
