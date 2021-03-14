//
// Created by Locke Peng on 2021/3/13.
//

#include "ui_thread.h"

#define SCREEN_FPS 24

void UiThread::init(U8G2 u8g2) {
    this->renderer = new Renderer(u8g2, SCREEN_FPS);
}

void UiThread::setRootView(View *view) {
    this->root = view;
}

void UiThread::async(const uint32_t *timestamp) {
    if (this->root != nullptr && this->renderer != nullptr) {
        this->renderer->asyncDraw(this->root, timestamp);
    }
}