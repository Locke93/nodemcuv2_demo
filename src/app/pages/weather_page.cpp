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
    std::shared_ptr<ViewGroup> rooView = std::make_shared<ViewGroup>();

    textView = std::make_shared<TextView>();
    textView->setText("...");
    textView->setPosition(0, 20);
    textView->setFont(u8g2_font_8x13_tr);
    rooView->addView(textView);

    temView = std::make_shared<TextView>();
    temView->setPosition(80, 28);
    temView->setFont(u8g2_font_10x20_tr);
    rooView->addView(temView);

    cityView = std::make_shared<TextView>();
    cityView->setPosition(80, 8);
    cityView->setFont(u8g2_font_5x7_tr);
    rooView->addView(cityView);
    setContentView(std::static_pointer_cast<View>(rooView));

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
        std::string json = std::string(response);
        std::string city = getValueFromJson(json, "name");
        std::string text = getValueFromJson(json, "text");
        std::string code = getValueFromJson(json, "code");
        std::string temperature = getValueFromJson(json, "temperature");

        textView->setText(text);
        temView->setText(temperature);
        cityView->setText(city);
    };
    HttpManager::getInstance()->addRequest(*request, callback);
}

std::string WeatherPage::getValueFromJson(const std::string &json, const std::string &key) {
    int begin = json.find(key + "\":\"");
    if (begin < 0) return "";
    begin += key.length() + 3;
    int end = json.find("\"", begin);
    if (end < 0 || end <= begin) return "";
    return json.substr(begin, end - begin);
}