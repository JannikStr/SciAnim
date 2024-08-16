#include <algorithm>
#include <iostream>
#include <memory>

#include <raylib.h>
#include <raymath.h>

#include "object.hxx"

ObjectBase::ObjectBase(Vector2 position)
: position(position), color(BLACK), borderColor(BLACK), borderThickness(.0f), animations()
{}

ObjectBase::ObjectBase(Vector2 position, Color backgroundColor)
: position(position), color(backgroundColor), borderColor(BLACK), borderThickness(0.0f), animations()
{}

ObjectBase::ObjectBase(Vector2 position, Color backgroundColor, Color borderColor, float borderThickness)
: position(position), color(backgroundColor), borderColor(borderColor), animations()
{
    this->borderThickness = borderThickness > .0f ? borderThickness : 0.0f;
}

float ObjectBase::getStartingTime()
{
    float startingTime = 0;
    if(!this->animations.empty())
    {
        const auto previousAnimation = this->animations.back();
        startingTime = previousAnimation->getStartingTime() + previousAnimation->getDuration();
    }
    return startingTime;
}

void ObjectBase::move(Vector2 startingPosition, Vector2 targetPosition, float duration)
{

    this->animations.emplace_back(std::make_shared<MoveAnimation>(this->getStartingTime(), duration, startingPosition, targetPosition));
}

void ObjectBase::delay(float delay)
{
    this->animations.emplace_back(std::make_shared<DelayAnimation>(this->getStartingTime(), delay));
}


std::shared_ptr<const Animation> ObjectBase::getCurrentAnimation(float animationTime)
{
    for (const auto& animation : this->animations) {
        if(animation->getStartingTime() <= animationTime && animation->getStartingTime() + animation->getDuration() >= animationTime)
        {
            return animation;
        }
    }
    return nullptr;
}


void ObjectBase::update(float currentTime)
{
    auto animation = this->getCurrentAnimation(currentTime);
    std::cout << currentTime << std::endl;
    if(!animation) {
        return;
    }

    if(animation->getAnimationType() == AnimationTypes::ANIMATION_MOVE)
    {
        const auto castedAnimation = std::static_pointer_cast<const MoveAnimation>(animation);
        float completion = (currentTime - castedAnimation->getStartingTime())/castedAnimation->getDuration();
        completion = std::min(completion, 1.0f);
        auto direction = Vector2Subtract(castedAnimation->getTargetPosition(), castedAnimation->getStartingPosition());
        this->setPosition(Vector2Add(castedAnimation->getStartingPosition(), Vector2Scale(direction, completion)));
    }
    else if(animation->getAnimationType() == AnimationTypes::ANIMATION_DELAY)
    {
        return;
    }
}
