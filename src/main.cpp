#include <Arduino.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#include "core/thread_manager.h"
#include "view/translate_animation.h"
#include "view/view_group.h"
#include "view/text_view.h"
#include "view/image_view.h"
#include "view/gif_view.h"

#define RESET_PIN U8X8_PIN_NONE
#define CLOCK_PIN U8X8_PIN_D4
#define DATA_PIN U8X8_PIN_D5

U8G2_SSD1306_128X32_UNIVISION_1_HW_I2C u8g2(U8G2_R2, RESET_PIN, CLOCK_PIN, DATA_PIN);

const unsigned char gif_1[] U8X8_PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00,
        0x00, 0x02, 0x08, 0x00, 0x80, 0x71, 0x10, 0x00, 0x40, 0x10, 0x20, 0x00,
        0x40, 0x80, 0x01, 0x00, 0xe0, 0x43, 0x40, 0x00, 0x20, 0x00, 0x40, 0x00,
        0x20, 0x03, 0x00, 0x18, 0x20, 0x00, 0x40, 0x18, 0x20, 0x00, 0x40, 0x28,
        0x20, 0x70, 0x40, 0x6c, 0x60, 0x90, 0x61, 0x84, 0x40, 0x08, 0xc0, 0x87,
        0x40, 0x00, 0x00, 0x60, 0x80, 0x00, 0x00, 0x1c, 0x00, 0x03, 0x80, 0x01,
        0x00, 0x44, 0x01, 0x00, 0x00, 0x84, 0x03, 0x00, 0xc0, 0xa6, 0x41, 0x00,
        0x20, 0xe0, 0x44, 0x00, 0x20, 0x40, 0x44, 0x00, 0x10, 0x41, 0x24, 0x00,
        0x50, 0x8c, 0x13, 0x00, 0x70, 0x10, 0x10, 0x00, 0x30, 0x60, 0xe0, 0x03,
        0x20, 0x80, 0x00, 0x02, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const unsigned char gif_2[] U8X8_PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x07, 0x00,
        0x00, 0x06, 0x18, 0x00, 0x00, 0x31, 0x10, 0x00, 0x80, 0x10, 0x20, 0x00,
        0x40, 0x80, 0x40, 0x00, 0xe0, 0x41, 0x40, 0x00, 0x20, 0x02, 0x40, 0x00,
        0x20, 0x03, 0x40, 0x00, 0xa0, 0x00, 0x18, 0x00, 0x20, 0x00, 0x5c, 0x00,
        0x20, 0xf0, 0x54, 0x00, 0x20, 0x10, 0x76, 0x00, 0x40, 0x08, 0x61, 0x00,
        0x40, 0x00, 0xe1, 0x00, 0x80, 0xe0, 0x38, 0x39, 0x00, 0x33, 0x0c, 0x3a,
        0x00, 0x0c, 0x03, 0x2c, 0x00, 0x64, 0x80, 0x64, 0x00, 0x04, 0xc0, 0x47,
        0x80, 0x03, 0x40, 0x44, 0x20, 0x00, 0x20, 0x18, 0x10, 0x00, 0x20, 0x00,
        0x90, 0x0f, 0x10, 0x00, 0x50, 0x30, 0x10, 0x00, 0x30, 0xc0, 0xe0, 0x03,
        0x20, 0x00, 0x03, 0x02, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void createView(ViewGroup *rootView) {
    auto *textView = new TextView();
    textView->setText("Hello");
    textView->setFont(u8g2_font_9x15_tr);
    rootView->addView(reinterpret_cast<View *>(textView));
    auto animation1 = new TranslateAnimation(textView, 0, 20, 48, 20);
    reinterpret_cast<Animation *>(animation1)->setDuration(3000);
    reinterpret_cast<Animation *>(animation1)->setReverse(true);
    animation1->start();

    /*auto *imageView = new ImageView();
    imageView->setImage(32, 32, gif_1);
    rootView->addView(reinterpret_cast<View *>(imageView));
    auto animation2 = new TranslateAnimation(imageView, 48, 0, 96, 0);
    reinterpret_cast<Animation *>(animation2)->setDuration(3000);
    reinterpret_cast<Animation *>(animation2)->setReverse(true);
    animation2->start();*/

    auto *gifView = new GifView();
    gifView->setImageSet(32, 32, {gif_1, gif_2});
    gifView->setInterval(200);
    rootView->addView(reinterpret_cast<View *>(gifView));
    auto animation2 = new TranslateAnimation(gifView, 48, 0, 96, 0);
    reinterpret_cast<Animation *>(animation2)->setDuration(3000);
    reinterpret_cast<Animation *>(animation2)->setReverse(true);
    animation2->start();
}

void setup() {
    //Serial.begin(9600);
    //Serial.println("======== setup =========");
    UiThread *uiThread = ThreadManager::getInstance()->getUiThread();
    uiThread->init(&u8g2);
    auto *rootView = new ViewGroup();
    createView(rootView);
    uiThread->setRootView(reinterpret_cast<View *>(rootView));
}

void loop() {
    //Serial.println("======== loop =========");
    delay(100L);
}