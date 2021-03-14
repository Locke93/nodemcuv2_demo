//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_ANIMATION_H
#define NODEMCUV2_ANIMATION_H

#include <cstdint>
#include "thread.h"
#include "thread_manager.h"

class Animation {
protected:
    uint32_t duration = 0;
    bool isRepeat = true;
    bool reverse = false;
    Thread *thread = nullptr;

    virtual void onUpdate(float progress) = 0;
protected:
    ~Animation();
public:
    void setDuration(uint32_t duration);
    void setRepeat(bool isRepeat);
    void setReverse(bool reverse);
    virtual bool start();
    virtual bool stop();

    class AnimationThread : Thread {
    private:
        Animation *parent;
        uint32_t *startTime;
    protected:
        ~AnimationThread() override;
    public:
        explicit AnimationThread(Animation *animation);
        void async(const uint32_t *timestamp) override;
    };
};


#endif //NODEMCUV2_ANIMATION_H

