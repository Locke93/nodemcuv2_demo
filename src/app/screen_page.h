//
// Created by Locke Peng on 2022/2/21.
//

#pragma once

#include <memory>
#include "../view/view.h"
#include "../view/view_group.h"

class ScreenPage {
public:
    const void onCreate(std::shared_ptr<ViewGroup> rootView);

    virtual void onCreate() = 0;

protected:
    void setContentView(std::shared_ptr<View> view);

private:
    std::shared_ptr<ViewGroup> rootView;
};
