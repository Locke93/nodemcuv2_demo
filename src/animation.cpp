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
    if (this->thread != nullptr) return false;
    this->thread = reinterpret_cast<Thread *>(new Animation::AnimationThread(this));
    ThreadManager::getInstance()->registerThread(this->thread);
    return true;
}

bool Animation::stop() {
    if (this->thread == nullptr) return false;
    ThreadManager::getInstance()->unregisterThread(this->thread);
    delete this->thread;
    this->thread = nullptr;
    return true;
}

Animation::~Animation() {
    stop();
}

Animation::AnimationThread::AnimationThread(Animation *animation) {
    this->parent = animation;
    uint32_t now = micros() / 1000;
    this->startTime = &now;
}

Animation::AnimationThread::~AnimationThread() {
    delete this->startTime;
    this->startTime = nullptr;
    this->parent = nullptr;
}

void Animation::AnimationThread::async(const uint32_t *timestamp) {
    uint32_t diff = *timestamp - *(this->startTime);
    uint32_t durationInMs = this->parent->duration;
    bool isOvertime = diff > durationInMs;
    if (isOvertime && !parent->isRepeat) {
        parent->stop();
    } else {
        float progress = (diff % durationInMs) / (float) durationInMs;
        if (isOvertime && this->parent->reverse && (diff / durationInMs) % 2 != 0) {
            parent->onUpdate(1.0f - progress);
        } else {
            parent->onUpdate(progress);
        }
    }
}

