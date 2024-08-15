
#include "object.hxx"
#include <algorithm>

ObjectBase::ObjectBase(Vector2 position) : position(position), currentAnimationDuration(.0f), keyFrames() {
    keyFrames.push_back(KeyFrame{
        .duration = 0,
        .endDuration = 0.0f,
        .kfPosition = position
    });
}

void ObjectBase::addKeyFramePosition(float duration, Vector2 kfPosition)
{
    const KeyFrame &lastKeyFrame = this->keyFrames.back();
    this->keyFrames.push_back(KeyFrame{
        .duration = duration,
        .endDuration = lastKeyFrame.endDuration + duration,
        .kfPosition = kfPosition
    });
}

const KeyFrame& ObjectBase::getNextKeyFrame(float totalDuration)
{
    auto is_key_frame = [totalDuration](KeyFrame frame){return (totalDuration >= frame.endDuration - frame.duration && totalDuration < frame.endDuration); };
    if (auto it = std::find_if(this->keyFrames.begin(), this->keyFrames.end(), is_key_frame); it != keyFrames.end())
    {
        return *it;
    }
    return this->keyFrames.back();
}
