//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_RENDERER_H
#define NODEMCUV2_RENDERER_H

#include <U8g2lib.h>
#include <time.h>
#include <sys/time.h>
#include "view.h"

class Renderer {
private:
    U8G2 u8g2;
    uint8_t wait;
    uint32_t next = 0;

    void onDraw(View *view);
public:
    Renderer(U8G2 u8g2, uint8_t fps);
    void asyncDraw(View *view, const uint32_t *timestamp);
};

#endif //NODEMCUV2_RENDERER_H