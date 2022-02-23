//
// Created by Locke Peng on 2021/3/13.
//

#include "text_view.h"

void TextView::setFont(const uint8_t *font) {
    this->font = font;
}

void TextView::setText(const char *text) {
    this->text = text;
}

void TextView::onDraw(U8G2 *u8g2) {
    if (this->text == nullptr) return;
    u8g2->setFont(this->font);
    u8g2->drawStr(this->positionX, this->positionY, this->text);
}


