//
// Created by Locke Peng on 2022/2/21.
//

#include <string>
#include <Ticker.h>
#include <memory>
#include "../screen_page.h"
#include "../../view/text_view.h"

class WeatherPage : public ScreenPage {
public:
    ~WeatherPage();

    void onCreate() override;

private:
    void requestWeather();

    std::string getValueFromJson(const std::string &json, const std::string &key);

private:
    std::shared_ptr<TextView> textView;
    std::shared_ptr<TextView> temView;
    std::shared_ptr<TextView> cityView;
    Ticker ticker;
};
