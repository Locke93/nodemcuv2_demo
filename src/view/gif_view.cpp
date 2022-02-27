//
// Created by Locke Peng on 2021/3/20.
//

#include "gif_view.h"

GifView::~GifView() {
    if (this->bitmaps.size() == 0) return;
    for (auto iter = bitmaps.begin(); iter != bitmaps.end(); iter++) {
        delete[] iter;
    }
}

void GifView::setInterval(uint16_t t) {
    this->interval = t;
}

void GifView::setImageSet(u8g2_uint_t w, u8g2_uint_t h, std::initializer_list<const uint8_t *> bitmaps) {
    this->width = w;
    this->height = h;
    this->bitmaps = bitmaps;
}

void GifView::onDraw(U8G2 *u8g2) {
    if (this->bitmaps.size() == 0) return;
    auto temp = std::begin(this->bitmaps) + this->drawIndex;
    const uint8_t *image = (const uint8_t *) *temp;
    u8g2->drawXBMP(this->positionX, this->positionY, this->width, this->height, image);
    uint32_t now = micros() / 1000;
    if (now - this->drawTime >= this->interval) {
        this->drawIndex = (this->drawIndex + 1) % this->bitmaps.size();
        this->drawTime = now;
    }
}