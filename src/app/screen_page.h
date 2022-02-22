//
// Created by Locke Peng on 2022/2/21.
//

#pragma once
#include "../view/view.h"
#include "../view/view_group.h"

class ScreenPage {
public:
    const void onCreate(ViewGroup *rootView);

    virtual void onCreate() = 0;

protected:
    void setContentView(View *view);

private:
    ViewGroup *rootView;
};
