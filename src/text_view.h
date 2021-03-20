//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_TEXT_VIEW_H
#define NODEMCUV2_TEXT_VIEW_H

#include "view.h"

class TextView : public View {
private:
    const uint8_t *font = nullptr;
    const char *text = nullptr;
public:
    TextView() = default;

    void setFont(const uint8_t *font);

    void setText(const char *text);

    void onDraw(U8G2 *u8g2) const override;
};

#endif //NODEMCUV2_TEXT_VIEW_H
