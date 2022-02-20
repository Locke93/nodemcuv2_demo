//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_ANIMATION_H
#define NODEMCUV2_ANIMATION_H

#include <cstdint>
#include "core/thread_manager.h"
#include "core/ui_thread.h"
#include "core/ui_component.h"

class Animation {
private:
    UiComponent *component = nullptr;
protected:
    uint32_t duration = 0;
    bool isRepeat = true;
    bool reverse = false;
    virtual void onUpdate(float progress) = 0;
protected:
    ~Animation();
public:
    void setDuration(uint32_t duration);
    void setRepeat(bool isRepeat);
    void setReverse(bool reverse);
    virtual bool start();
    virtual bool stop();

    class AnimationComponent : UiComponent {
    private:
        Animation *parent;
        uint32_t startTime;
    protected:
        ~AnimationComponent() override;
    public:
        explicit AnimationComponent(Animation *animation);
        void async(const uint32_t *timestamp) override;
    };
};


#endif //NODEMCUV2_ANIMATION_H

