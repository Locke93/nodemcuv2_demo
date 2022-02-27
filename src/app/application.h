//
// Created by Locke Peng on 2022/2/21.
//

#include "screen_page.h"
#include "../view/view_group.h"
#include <Ticker.h>
#include <memory>

class Application {
private:
    static Application *sApplication;
public:
    static Application *getInstance();

    void onCreate(U8G2 *u8g2);

    void launchScreenPage(std::shared_ptr<ScreenPage> page);

    void launchScreenPageDelayed(std::shared_ptr<ScreenPage> page, long delay);

    void onLoop();

private:
    std::shared_ptr<ViewGroup> rootView = nullptr;
    std::shared_ptr<ScreenPage> activePage = nullptr;
    Ticker ticker;
};
