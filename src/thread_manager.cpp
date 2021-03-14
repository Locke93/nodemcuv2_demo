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
    this->threads.push_back(reinterpret_cast<Thread *>(this->uiThread));
}

UiThread *ThreadManager::getUiThread() {
    return this->uiThread;
}

void ThreadManager::registerThread(Thread *thread) {
    this->threads.push_back(thread);
}

void ThreadManager::unregisterThread(Thread *thread) {
    this->threads.remove(thread);
}

void ThreadManager::async() {
    uint32_t now = micros() / 1000;
    for (Thread *thread: this->threads) {
        thread->async(&now);
    }
}