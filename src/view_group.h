//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_VIEW_GROUP_H
#define NODEMCUV2_VIEW_GROUP_H

#include <iostream>
#include <list>
#include "view.h"

class ViewGroup : View {
private:
    std::list<View *> childs;
public:
    ViewGroup() = default;

    void addView(View *view);

    void addView(View *view, int index);

    void onDraw(U8G2 u8g2) override;
};

#endif //NODEMCUV2_VIEW_GROUP_H

