//
// Created by Locke Peng on 2022/2/21.
//

#include "weather_page.h"
#include "../../view/text_view.h"
#include "../network/http.h"


void WeatherPage::onCreate() {
    auto *textView = new TextView();
    textView->setText("inquire...");
    textView->setPosition(0, 20);
    textView->setFont(u8g2_font_8x13_tr);
    setContentView(textView);

    const char *host = "http://api.k780.com";
    const char *path = "/";
    HttpConnection *httpConnect = new HttpConnection(host, path);
    httpConnect->addQuery("app", "weather.today");
    httpConnect->addQuery("weaId", "1");
    httpConnect->addQuery("appkey", "10003");
    httpConnect->addQuery("sign", "b59bc3ef6191eb9f747dd4e83c99f2a4");
    httpConnect->addQuery("format", "json");
    auto result = httpConnect->get();
    Serial.println(result);
}