//
// Created by Locke Peng on 2022/2/21.
//

#include "application.h"
#include "../core/thread_manager.h"
#include "network/http_manager.h"

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
    rootView = std::make_shared<ViewGroup>();
    uiThread->setRootView(reinterpret_cast<View *>(rootView.get()));
}

void Application::onLoop() {
    HttpManager::getInstance()->execute();
}

void Application::launchScreenPage(std::shared_ptr<ScreenPage> page) {
    if (rootView == nullptr || rootView.get() == nullptr) return;
    rootView->removeAllViews();
    page->onCreate(rootView);
    activePage = page;
}

void Application::launchScreenPageDelayed(std::shared_ptr<ScreenPage> page, long delay) {
    if (rootView == nullptr || rootView.get() == nullptr) return;
    ticker.once_ms(delay, [this, page] {
        rootView->removeAllViews();
        page->onCreate(rootView);
        //activePage = page;
    });
}