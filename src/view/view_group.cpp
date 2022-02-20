//
// Created by Locke Peng on 2021/3/13.
//

#include "view_group.h"

void ViewGroup::addView(View *view) {
    this->childs.push_back(view);
}

void ViewGroup::addView(View *view, int index) {
    std::list<View *>::iterator itr = this->childs.begin();
    this->childs.insert(itr, index, view);
}

void ViewGroup::onDraw(U8G2 *u8g2) {
    for (View *v: this->childs) {
        v->onDraw(u8g2);
    }
}