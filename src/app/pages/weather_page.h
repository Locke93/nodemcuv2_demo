//
// Created by Locke Peng on 2022/2/21.
//

#include "../screen_page.h"
#include "../../view/text_view.h"
#include <string.h>
#include <Ticker.h>

class WeatherPage : public ScreenPage {
public:
    ~WeatherPage();
    void onCreate() override;

private:
    void requestWeather();

    String getValueFromJson(const String &json, const String &key);

private:
    TextView *textView;
    TextView *temView;
    TextView *cityView;
    Ticker ticker;
};
