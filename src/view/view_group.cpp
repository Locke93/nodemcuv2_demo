//
// Created by Locke Peng on 2021/3/13.
//

#include "view_group.h"

void ViewGroup::addView(std::shared_ptr<View> view) {
    this->childs.push_back(view);
}

void ViewGroup::addView(std::shared_ptr<View> view, int index) {
    std::list<std::shared_ptr<View>>::iterator itr = this->childs.begin();
    this->childs.insert(itr, index, view);
}

void ViewGroup::onDraw(U8G2 *u8g2) {
    if (this->childs.empty()) return;
    for (std::shared_ptr<View> v: this->childs) {
        auto view = v.get();
        if (view) view->onDraw(u8g2);
    }
}

void ViewGroup::removeAllViews() {
    if (this->childs.empty()) return;
    this->childs.clear();
}