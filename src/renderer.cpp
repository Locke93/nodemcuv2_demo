//
// Created by Locke Peng on 2021/3/13.
//

#include "renderer.h"

Renderer::Renderer(U8G2 u8g2, uint8_t fps) {
    u8g2.begin();
    this->u8g2 = u8g2;
    this->wait = 1000 / fps;
}

void Renderer::asyncDraw(View *view, const uint32_t *timestamp) {
        if (*timestamp >= this->next) {
        this->next = *timestamp + wait;
        onDraw(view);
    }
}

void Renderer::onDraw(View *view) {
    this->u8g2.firstPage();
    do {
        view->onDraw(this->u8g2);
    } while (this->u8g2.nextPage());
}