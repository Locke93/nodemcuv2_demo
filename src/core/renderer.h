//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_RENDERER_H
#define NODEMCUV2_RENDERER_H

#include <U8g2lib.h>
#include "view/view.h"

class Renderer {
private:
    U8G2 *u8g2;
public:
    Renderer(U8G2 *u8g2);
    void draw(View *view);
};

#endif //NODEMCUV2_RENDERER_H