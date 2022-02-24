//
// Created by Locke Peng on 2022/2/21.
//

#include "weather_page.h"
#include "../network/http_request.h"
#include "../network/http_manager.h"
#include "../local_properties.h"

WeatherPage::~WeatherPage() {
    ticker.detach();
}

void WeatherPage::onCreate() {
    ViewGroup *rooView = new ViewGroup();

    textView = new TextView();
    textView->setText("...");
    textView->setPosition(0, 20);
    textView->setFont(u8g2_font_8x13_tr);
    rooView->addView(textView);

    temView = new TextView();
    temView->setPosition(80, 28);
    temView->setFont(u8g2_font_10x20_tr);
    rooView->addView(temView);

    cityView = new TextView();
    cityView->setPosition(80, 8);
    cityView->setFont(u8g2_font_5x7_tr);
    rooView->addView(cityView);
    setContentView(reinterpret_cast<View *>(rooView));

    ticker.attach(60 * 15, std::bind(&WeatherPage::requestWeather, this));
    requestWeather();
}

// https://seniverse.yuque.com/docs/share/cd531fe7-714d-4bd7-8113-55adeaec54af?#fR0aI
void WeatherPage::requestWeather() {
    HttpRequest *request = new HttpRequest("https://api.seniverse.com", "/v3/weather/now.json");
    request->addQuery("language", "en"); // zh-Hans
    request->addQuery("unit", "c");
    request->addQuery("location", "ip");
    request->addQuery("key", APP_KEY);
    HttpManager::HttpCallback callback = [this](const char *response) {
        Serial.println(response);
        String *json = new String(response);
        String city = getValueFromJson(*json, "name");
        String text = getValueFromJson(*json, "text");
        String code = getValueFromJson(*json, "code");
        String temperature = getValueFromJson(*json, "temperature");

        char *temp1 = new char[text.length() + 1];
        text.toCharArray(temp1, text.length() + 1, 0);
        textView->setText(temp1);

        char *temp2 = new char[temperature.length() + 1];
        temperature.toCharArray(temp2, temperature.length() + 1, 0);
        temView->setText(temp2);

        char *temp3 = new char[city.length() + 1];
        city.toCharArray(temp3, city.length() + 1, 0);
        cityView->setText(temp3);
    };
    HttpManager::getInstance()->addRequest(*request, callback);
}

String WeatherPage::getValueFromJson(const String &json, const String &key) {
    int begin = json.indexOf(key + "\":\"");
    if (begin < 0) return "";
    begin += key.length() + 3;
    int end = json.indexOf("\"", begin);
    if (end < 0 || end <= begin) return "";
    return json.substring(begin, end);
}