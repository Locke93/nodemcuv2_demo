//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_VIEW_GROUP_H
#define NODEMCUV2_VIEW_GROUP_H

#include <iostream>
#include <list>
#include <memory>
#include "view.h"

class ViewGroup : public View {
private:
    std::list<std::shared_ptr<View>> childs;
public:
    ViewGroup() = default;

    void addView(std::shared_ptr<View> view);

    void addView(std::shared_ptr<View> view, int index);

    void onDraw(U8G2 *u8g2) override;

    void removeAllViews();
};

#endif //NODEMCUV2_VIEW_GROUP_H

