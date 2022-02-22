//
// Created by Locke Peng on 2022/2/21.
//

#include "weather_page.h"
#include "../../view/text_view.h"
#include "../network/http_request.h"
#include "../network/http_manager.h"

void WeatherPage::onCreate() {
    auto *textView = new TextView();
    textView->setText("inquire...");
    textView->setPosition(0, 20);
    textView->setFont(u8g2_font_8x13_tr);
    setContentView(textView);
    requestLocation();
    requestWeather();
}

void WeatherPage::requestLocation() {
    HttpRequest *request = new HttpRequest("https://ip.tool.lu", "/");
    HttpManager::HttpCallback callback = [](const char *response) {
        Serial.println(response);
    };
    HttpManager::getInstance()->addRequest(*request, callback);
}

void WeatherPage::requestWeather() {
    HttpRequest *request = new HttpRequest("http://api.k780.com", "/");
    request->addQuery("app", "weather.today");
    request->addQuery("weaId", "1");
    request->addQuery("appkey", "10003");
    request->addQuery("sign", "b59bc3ef6191eb9f747dd4e83c99f2a4");
    request->addQuery("format", "json");
    HttpManager::HttpCallback callback = [](const char *response) {
        Serial.println(response);
    };
    HttpManager::getInstance()->addRequest(*request, callback);
}