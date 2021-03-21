//
// Created by Locke Peng on 2021/3/20.
//

#ifndef NODEMCUV2_GIF_VIEW_H
#define NODEMCUV2_GIF_VIEW_H

#include <cstdint>
#include <initializer_list>
#include "view.h"

class GifView : public View {
private:
    u8g2_uint_t width = 0;
    u8g2_uint_t height = 0;
    uint16_t interval = 100; // in ms
    std::initializer_list<const uint8_t *> bitmaps;
    uint8_t drawIndex = 0;
    uint32_t drawTime = 0;
public:
    void setInterval(uint16_t t);

    void setImageSet(u8g2_uint_t w, u8g2_uint_t h, std::initializer_list<const uint8_t *> bitmaps);

    void onDraw(U8G2 *u8g2) override;
};

#endif //NODEMCUV2_GIF_VIEW_H
