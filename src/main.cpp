#include <Arduino.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include <memory>
#include "app/application.h"
#include "app/pages/network_connect_page.h"

#define RESET_PIN U8X8_PIN_NONE
#define CLOCK_PIN U8X8_PIN_D4
#define DATA_PIN U8X8_PIN_D5

U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R2, RESET_PIN, CLOCK_PIN, DATA_PIN);

void setup() {
    Serial.begin(115200);
    Serial.println("======== setup =========");
    Application::getInstance()->onCreate(&u8g2);
    auto network = std::make_shared<NetworkConnectPage>();
    Application::getInstance()->launchScreenPage(network);
}

void loop() {
    Application::getInstance()->onLoop();
}