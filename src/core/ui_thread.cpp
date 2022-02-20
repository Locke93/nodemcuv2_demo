//
// Created by Locke Peng on 2021/3/13.
//

#include "ui_thread.h"

#define SCREEN_FPS 60

void UiThread::init(U8G2 *u8g2) {
    this->renderer = new Renderer(u8g2);
    this->ticker.attach_ms_scheduled(1000 / SCREEN_FPS, std::bind(&UiThread::async, this));
}

void UiThread::setRootView(View *view) {
    this->root = view;
}

void UiThread::attachComponent(UiComponent *component) {
    this->components.push_back(component);
}

void UiThread::detachComponent(UiComponent *component) {
    this->components.remove(component);
}

void UiThread::async() {
    uint32_t now = micros() / 1000;
    for (UiComponent *component: components) {
        component->async(&now);
    }
    if (this->root != nullptr && this->renderer != nullptr) {
        this->renderer->draw(this->root);
    }
}

UiThread::~UiThread() {
    components.clear();
    ticker.detach();
    if (this->renderer != nullptr) {
        delete this->renderer;
        this->renderer = nullptr;
    }
}