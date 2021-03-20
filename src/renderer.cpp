//
// Created by Locke Peng on 2021/3/13.
//

#include "renderer.h"

Renderer::Renderer(U8G2 *u8g2) {
    u8g2->begin();
    this->u8g2 = u8g2;
}

void Renderer::draw(const View *view) {
    this->u8g2->firstPage();
    do {
        view->onDraw(this->u8g2);
    } while (this->u8g2->nextPage());
}