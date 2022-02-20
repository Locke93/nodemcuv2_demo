//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_THREAD_MANAGER_H
#define NODEMCUV2_THREAD_MANAGER_H

#include <iostream>
#include "core/ui_thread.h"

class ThreadManager {
private:
    static ThreadManager *sThreadManager;
    UiThread *uiThread = nullptr;

    ThreadManager();
public:
    static ThreadManager *getInstance();

    UiThread *getUiThread();
};

#endif //NODEMCUV2_THREAD_MANAGER_H
