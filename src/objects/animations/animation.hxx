#ifndef SCIANIM_ANIMATION
#define SCIANIM_ANIMATION

#include <raylib.h>

const int ANIMATION_FLAG_SLOW_START = 1;
const int ANIMATION_FLAG_SLOW_END = 1 << 1;

enum AnimationTypes {
    ANIMATION_MOVE,
    ANIMATION_SCALE,
    ANIMATION_DELAY
};

class Animation {
private:
    float startingTime;
    float duration;
    AnimationTypes animationType;
public:
    explicit Animation(float startingTime, float duration, AnimationTypes animationType) : startingTime(startingTime), duration(duration), animationType(animationType) {}
    inline float getStartingTime() const { return this->startingTime; }
    inline float getDuration() const { return this->duration; }
    inline AnimationTypes getAnimationType() const { return this->animationType; };
};

class MoveAnimation : public Animation {
private:
    Vector2 startingPosition;
    Vector2 targetPosition;
public:

    MoveAnimation(float startingTime, float duration, Vector2 startingPosition, Vector2 targetPosition);

    Vector2 getStartingPosition() const { return this->startingPosition; }
    Vector2 getTargetPosition() const { return this->targetPosition; }
};

class DelayAnimation : public Animation {
public:
    DelayAnimation(float startingTime, float delay);
};

class RelocateAnimation : public Animation {};

#endif
