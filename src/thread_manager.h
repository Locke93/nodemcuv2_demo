//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_THREAD_MANAGER_H
#define NODEMCUV2_THREAD_MANAGER_H

#include <iostream>
#include <list>
#include "thread.h"
#include "ui_thread.h"

class ThreadManager {
private:
    static ThreadManager *sThreadManager;
    std::list<Thread *> threads;
    UiThread *uiThread = nullptr;

    ThreadManager();
public:
    static ThreadManager *getInstance();

    UiThread *getUiThread();

    void registerThread(Thread *thread);

    void unregisterThread(Thread *thread);

    void async();
};

#endif //NODEMCUV2_THREAD_MANAGER_H
