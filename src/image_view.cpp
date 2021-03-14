//
// Created by Locke Peng on 2021/3/14.
//

#include "image_view.h"

void ImageView::setImage(u8g2_uint_t w, u8g2_uint_t h, const uint8_t *bitmap) {
    this->width = w;
    this->height = h;
    this->bitmap = bitmap;
}

void ImageView::onDraw(U8G2 u8g2) {
    if (this->bitmap == nullptr) return;
    u8g2.drawXBMP(this->positionX, this->positionY, this->width, this->height, this->bitmap);
}