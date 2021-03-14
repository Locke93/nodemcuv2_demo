//
// Created by Locke Peng on 2021/3/13.
//

#include "translate_animation.h"

TranslateAnimation::TranslateAnimation(View *view,
                                       u8g2_uint_t fromX,
                                       u8g2_uint_t fromY,
                                       u8g2_uint_t toX,
                                       u8g2_uint_t toY) {
    this->view = view;
    this->fromX = fromX;
    this->fromY = fromY;
    this->toX = toX;
    this->toY = toY;
}

bool TranslateAnimation::start() {
    bool result = Animation::start();
    if (result) {
        view->setPosition(this->fromX, this->fromY); // set from position
    }
    return result;
}

bool TranslateAnimation::stop() {
    bool result = Animation::stop();
    if (result) {
        view->setPosition(this->fromX, this->fromY); // reset to origin position
    }
    return result;
}

void TranslateAnimation::onUpdate(float progress) {
    u8g2_uint_t x = (fromX + (toX - fromX) * progress);
    u8g2_uint_t y = (fromY + (toY - fromY) * progress);
    view->setPosition(x, y);
}