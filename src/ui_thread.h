//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_UI_THREAD_H
#define NODEMCUV2_UI_THREAD_H

#include <U8g2lib.h>
#include "thread.h"
#include "renderer.h"
#include "view.h"

class UiThread : Thread {
private:
    View *root = nullptr;
    Renderer *renderer = nullptr;
public:
    UiThread() = default;
    void init(U8G2 u8g2);
    void setRootView(View *view);
    void async(const uint32_t *timestamp) override;
};

#endif //NODEMCUV2_UI_THREAD_H
