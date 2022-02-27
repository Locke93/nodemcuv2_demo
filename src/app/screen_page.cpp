//
// Created by Locke Peng on 2022/2/21.
//

#include "screen_page.h"

const void ScreenPage::onCreate(std::shared_ptr<ViewGroup> root) {
    this->rootView = root;
    this->onCreate();
}

void ScreenPage::setContentView(std::shared_ptr<View> view) {
    this->rootView->addView(view);
}

