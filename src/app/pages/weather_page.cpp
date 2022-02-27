//
// Created by Locke Peng on 2022/2/21.
//

#include "weather_page.h"
#include "../network/http_request.h"
#include "../network/http_manager.h"
#include "../local_properties.h"
#include "../resources.h"

WeatherPage::~WeatherPage() {
    ticker.detach();
}

void WeatherPage::onCreate() {
    std::shared_ptr<ViewGroup> rooView = std::make_shared<ViewGroup>();

    iconView = std::make_shared<ImageView>();
    iconView->setPosition(0, 0);
    iconView->setImage(74, 32, weather_icon_99);
    rooView->addView(iconView);

    temView = std::make_shared<TextView>();
    temView->setPosition(80, 28);
    temView->setFont(u8g2_font_10x20_tr);
    rooView->addView(temView);

    textView = std::make_shared<TextView>();
    textView->setPosition(80, 8);
    textView->setFont(u8g2_font_5x7_tr);
    rooView->addView(textView);
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
    HttpManager::HttpCallback callback = [this](const std::string &response) {
        Serial.println(response.c_str());
        std::string city = getValueFromJson(response, "name");
        std::string text = getValueFromJson(response, "text");
        std::string code = getValueFromJson(response, "code");
        std::string temperature = getValueFromJson(response, "temperature");

        auto icon = getIconByCode(code);
        iconView->setImage(icon.first.first, icon.first.second, icon.second);
        textView->setText(text);
        temView->setText(temperature + "'C");
    };
    HttpManager::getInstance()->addRequest(*request, callback);
}

std::pair<std::pair<int, int>, const uint8_t *> WeatherPage::getIconByCode(const std::string &code) {
    if (code == "0") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_0);
    }
    if (code == "1") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_1);
    }
    if (code == "2") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_2);
    }
    if (code == "3") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_3);
    }
    if (code == "4") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_4);
    }
    if (code == "5") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_5);
    }
    if (code == "6") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_6);
    }
    if (code == "7") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_7);
    }
    if (code == "8") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_8);
    }
    if (code == "9") {
        return std::make_pair(std::make_pair(48, 32), weather_icon_9);
    }
    if (code == "10") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_10);
    }
    if (code == "11") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_11);
    }
    if (code == "12") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_12);
    }
    if (code == "13") {
        return std::make_pair(std::make_pair(33, 32), weather_icon_13);
    }
    if (code == "14") {
        return std::make_pair(std::make_pair(33, 32), weather_icon_14);
    }
    if (code == "15") {
        return std::make_pair(std::make_pair(33, 32), weather_icon_15);
    }
    if (code == "16") {
        return std::make_pair(std::make_pair(33, 32), weather_icon_16);
    }
    if (code == "17") {
        return std::make_pair(std::make_pair(34, 32), weather_icon_17);
    }
    if (code == "18") {
        return std::make_pair(std::make_pair(34, 32), weather_icon_18);
    }
    if (code == "19") {
        return std::make_pair(std::make_pair(31, 32), weather_icon_19);
    }
    if (code == "20") {
        return std::make_pair(std::make_pair(33, 32), weather_icon_20);
    }
    if (code == "21") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_21);
    }
    if (code == "22") {
        return std::make_pair(std::make_pair(34, 32), weather_icon_22);
    }
    if (code == "23") {
        return std::make_pair(std::make_pair(34, 32), weather_icon_23);
    }
    if (code == "24") {
        return std::make_pair(std::make_pair(34, 32), weather_icon_24);
    }
    if (code == "25") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_25);
    }
    if (code == "26") {
        return std::make_pair(std::make_pair(38, 32), weather_icon_26);
    }
    if (code == "27") {
        return std::make_pair(std::make_pair(38, 32), weather_icon_27);
    }
    if (code == "28") {
        return std::make_pair(std::make_pair(55, 32), weather_icon_28);
    }
    if (code == "29") {
        return std::make_pair(std::make_pair(55, 32), weather_icon_29);
    }
    if (code == "30") {
        return std::make_pair(std::make_pair(35, 32), weather_icon_30);
    }
    if (code == "31") {
        return std::make_pair(std::make_pair(36, 32), weather_icon_31);
    }
    if (code == "32") {
        return std::make_pair(std::make_pair(41, 32), weather_icon_32);
    }
    if (code == "33") {
        return std::make_pair(std::make_pair(41, 32), weather_icon_33);
    }
    if (code == "34") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_34);
    }
    if (code == "35") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_35);
    }
    if (code == "36") {
        return std::make_pair(std::make_pair(33, 32), weather_icon_36);
    }
    if (code == "37") {
        return std::make_pair(std::make_pair(28, 32), weather_icon_37);
    }
    if (code == "38") {
        return std::make_pair(std::make_pair(32, 32), weather_icon_38);
    }
    return std::make_pair(std::make_pair(74, 32), weather_icon_99);
}

std::string WeatherPage::getValueFromJson(const std::string &json, const std::string &key) {
    auto begin = json.find(key + "\":\"");
    if (begin == std::string::npos) return "";
    begin += key.length() + 3;
    auto end = json.find("\"", begin);
    if (end == std::string::npos || end <= begin) return "";
    return json.substr(begin, end - begin);
}