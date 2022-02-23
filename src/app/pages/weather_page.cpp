//
// Created by Locke Peng on 2022/2/21.
//

#include "weather_page.h"
#include "../../view/view_group.h"
#include "../network/http_request.h"
#include "../network/http_manager.h"
#include "../local_properties.h"

void WeatherPage::onCreate() {
    ViewGroup *rooView = new ViewGroup();

    textView = new TextView();
    textView->setText("...");
    textView->setPosition(0, 20);
    textView->setFont(u8g2_font_8x13_tr);
    rooView->addView(textView);

    temView = new TextView();
    temView->setText("10");
    temView->setPosition(80, 28);
    temView->setFont(u8g2_font_10x20_tr);
    rooView->addView(temView);

    cityView = new TextView();
    cityView->setText("Xiamen");
    cityView->setPosition(80, 8);
    cityView->setFont(u8g2_font_5x7_tr);
    rooView->addView(cityView);

    setContentView(reinterpret_cast<View *>(rooView));
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
        String temperature = getValueFromJson(*json, "temperature");

        Serial.println(text);
        textView->setText(text.c_str());
        Serial.println(temperature);
        temView->setText(temperature.c_str());
        Serial.println(city);
        cityView->setText(city.c_str());
    };
    HttpManager::getInstance()->addRequest(*request, callback);

    //** Response example **/
    //{"results":[{"location":{"id":"WS7GQBRNR6V8","name":"厦门","country":"CN","path":"厦门,厦��,福建,中国","timezone":"Asia/Shanghai","timezone_offset":"+08:00"},"now":{"text":"阴","code":"9","temperature":"9"},"last_update":"2022-02-23T21:44:47+08:00"}]}
}

String WeatherPage::getValueFromJson(const String &json, const String &key) {
    int begin = json.indexOf(key + "\":\"");
    if (begin < 0) return "";
    begin += key.length() + 3;
    int end = json.indexOf("\"", begin);
    if (end < 0 || end <= begin) return "";
    return json.substring(begin, end);
}