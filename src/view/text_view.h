//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_TEXT_VIEW_H
#define NODEMCUV2_TEXT_VIEW_H

#include "view/view.h"
#include <string>

class TextView : public View {
private:
    const uint8_t *font = nullptr;
    std::string text = "";
public:

    void setFont(const uint8_t *font);

    void setText(const std::string &text);

    void onDraw(U8G2 *u8g2) override;
};

#endif //NODEMCUV2_TEXT_VIEW_H
