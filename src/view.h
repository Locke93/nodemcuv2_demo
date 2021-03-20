//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_VIEW_H
#define NODEMCUV2_VIEW_H

#include <U8g2lib.h>

class View {
protected:
    u8g2_uint_t positionX = 0;
    u8g2_uint_t positionY = 0;
public:
    View() = default;
    void setPosition(u8g2_uint_t x, u8g2_uint_t y) {
        this->positionX = x;
        this->positionY = y;
    }
    virtual void onDraw(U8G2 *u8g2) const = 0;
};

#endif //NODEMCUV2_VIEW_H

