//
// Created by Locke Peng on 2022/2/21.
//

#include "screen_page.h"

const void ScreenPage::onCreate(ViewGroup *root) {
    this->rootView = root;
    this->onCreate();
}

void ScreenPage::setContentView(View *view) {
    this->rootView->addView(view);
}

