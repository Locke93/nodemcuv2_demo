//
// Created by Locke Peng on 2022/2/21.
//

#include "screen_page.h"
#include "../view/view_group.h"
#include <Ticker.h>

class Application {
private:
    static Application *sApplication;
public:
    static Application *getInstance();

    void onCreate(U8G2 *u8g2);

    void launchScreenPage(ScreenPage *page);

    void launchScreenPageDelayed(ScreenPage *page, long delay);

    void onLoop();

private:
    ViewGroup *rootView = nullptr;
    Ticker ticker;
};
