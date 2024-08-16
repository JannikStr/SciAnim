#include "animation.hxx"

MoveAnimation::MoveAnimation(float startingTime, float duration, Vector2 startingPosition, Vector2 targetPosition)
: Animation(startingTime, duration, AnimationTypes::ANIMATION_MOVE), startingPosition(startingPosition), targetPosition(targetPosition)
{}

DelayAnimation::DelayAnimation(float startingTime, float delay)
: Animation(startingTime, delay, AnimationTypes::ANIMATION_DELAY)
{}
