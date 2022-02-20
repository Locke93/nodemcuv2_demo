//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_UI_THREAD_H
#define NODEMCUV2_UI_THREAD_H

#include <U8g2lib.h>
#include <list>
#include <Ticker.h>
#include "renderer.h"
#include "view/view.h"
#include "ui_component.h"

class UiThread {
private:
    View *root = nullptr;
    Renderer *renderer = nullptr;
    Ticker ticker;
    std::list<UiComponent *> components;
    void async();
public:
    UiThread() = default;
    ~UiThread();
    void init(U8G2 *u8g2);
    void setRootView(View *view);
    void attachComponent(UiComponent *component);
    void detachComponent(UiComponent *component);
};

#endif //NODEMCUV2_UI_THREAD_H
