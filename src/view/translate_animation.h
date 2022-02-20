//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_TRANSLATE_ANIMATION_H
#define NODEMCUV2_TRANSLATE_ANIMATION_H

#include "view/animation.h"
#include "view/view.h"

class TranslateAnimation : Animation {
private:
    View *view;
    u8g2_uint_t fromX;
    u8g2_uint_t fromY;
    u8g2_uint_t toX;
    u8g2_uint_t toY;

protected:
    void onUpdate(float progress) override;

public:
    TranslateAnimation(View *view,
                       u8g2_uint_t fromX,
                       u8g2_uint_t fromY,
                       u8g2_uint_t toX,
                       u8g2_uint_t toY);
    bool start() override;
    bool stop() override;
};

#endif //NODEMCUV2_TRANSLATE_ANIMATION_H
