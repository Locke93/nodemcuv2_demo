//
// Created by Locke Peng on 2021/3/14.
//

#ifndef NODEMCUV2_IMAGE_VIEW_H
#define NODEMCUV2_IMAGE_VIEW_H

#include "view/view.h"

class ImageView : public View {
private:
    u8g2_uint_t width = 0;
    u8g2_uint_t height = 0;
    const uint8_t *bitmap = nullptr;
public:
    ImageView() = default;
    void setImage(u8g2_uint_t w, u8g2_uint_t h, const uint8_t *bitmap);
    void onDraw(U8G2 *u8g2) override;
};

#endif //NODEMCUV2_IMAGE_VIEW_H
