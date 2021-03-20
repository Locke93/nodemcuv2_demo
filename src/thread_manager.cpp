//
// Created by Locke Peng on 2021/3/13.
//

#include "thread_manager.h"

ThreadManager *ThreadManager::sThreadManager = nullptr;

ThreadManager *ThreadManager::getInstance(void) {
    if (sThreadManager == nullptr) {
        sThreadManager = new ThreadManager();
    }
    return sThreadManager;
}

ThreadManager::ThreadManager() {
    this->uiThread = new UiThread();
}

UiThread *ThreadManager::getUiThread() {
    return this->uiThread;
}