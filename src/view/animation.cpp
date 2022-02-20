//
// Created by Locke Peng on 2021/3/13.
//

#include "animation.h"


void Animation::setDuration(uint32_t duration) {
    this->duration = duration;
}

void Animation::setRepeat(bool isRepeat) {
    this->isRepeat = isRepeat;
}

void Animation::setReverse(bool reverse) {
    this->reverse = reverse;
}

bool Animation::start() {
    if (this->component != nullptr) return false;
    this->component = reinterpret_cast<UiComponent *>(new Animation::AnimationComponent(this));
    ThreadManager::getInstance()->getUiThread()->attachComponent(this->component);
    return true;
}

bool Animation::stop() {
    if (this->component == nullptr) return false;
    ThreadManager::getInstance()->getUiThread()->detachComponent(this->component);
    delete this->component;
    this->component = nullptr;
    return true;
}

Animation::~Animation() {
    Animation::stop();
}

Animation::AnimationComponent::AnimationComponent(Animation *animation) {
    this->parent = animation;
    this->startTime = micros() / 1000;
}

Animation::AnimationComponent::~AnimationComponent() {
    this->parent = nullptr;
}

void Animation::AnimationComponent::async(const uint32_t *timestamp) {
    uint32_t diff = *timestamp - (this->startTime);
    uint32_t durationInMs = this->parent->duration;
    bool isOvertime = diff > durationInMs;
    if (isOvertime && !parent->isRepeat) {
        parent->stop();
    } else {
        auto time = diff % durationInMs;
        float progress = time / (float) durationInMs;
        if (isOvertime && this->parent->reverse && (diff / durationInMs) % 2 != 0) {
            parent->onUpdate(1.0f - progress);
        } else {
            parent->onUpdate(progress);
        }
    }
}

