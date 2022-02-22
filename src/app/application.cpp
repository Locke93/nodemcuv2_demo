//
// Created by Locke Peng on 2022/2/21.
//

#include "application.h"
#include "../core/thread_manager.h"

Application *Application::sApplication = nullptr;

Application *Application::getInstance(void) {
    if (sApplication == nullptr) {
        sApplication = new Application();
    }
    return sApplication;
}

void Application::onCreate(U8G2 *u8g2) {
    UiThread *uiThread = ThreadManager::getInstance()->getUiThread();
    uiThread->init(u8g2);
    rootView = new ViewGroup();
    uiThread->setRootView(reinterpret_cast<View *>(rootView));
}

void Application::launchScreenPage(ScreenPage *page) {
    if (rootView == nullptr) return;
    rootView->removeAllViews();
    page->onCreate(rootView);
}

void Application::launchScreenPageDelayed(ScreenPage *page, long delay) {
    if (rootView == nullptr) return;
    ticker.once_ms(delay, [this, page] {
        rootView->removeAllViews();
        page->onCreate(rootView);
    });
}