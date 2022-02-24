//
// Created by Locke Peng on 2022/2/20.
//

#pragma once

#include <initializer_list>

// width: 32, height: 32
const unsigned char wifi_icon_0[]
U8X8_PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x80,
                0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const unsigned char wifi_icon_1[]
U8X8_PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0xe0, 0x07, 0x00, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00,
                0x38, 0x1c, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x80,
                0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const unsigned char wifi_icon_2[]
U8X8_PROGMEM = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x1f,
                0x00, 0x00, 0xfe, 0x7f, 0x00, 0x00, 0xff, 0xff, 0x00, 0x80, 0x3f, 0xfc, 0x01, 0x80, 0x0f, 0xf0, 0x01,
                0x80, 0xe3, 0xc7, 0x01, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00,
                0x38, 0x1c, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x80,
                0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const std::initializer_list<const uint8_t *> wifi_icon_gif = {wifi_icon_0, wifi_icon_1, wifi_icon_2};

#define WEATHER_ICON_0     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322513924-8d39d7ad-2558-4775-80aa-ed2bc61dce66.png"
#define WEATHER_ICON_1     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322513835-60507db3-4688-40b5-a9cd-4859de4a56e4.png"
#define WEATHER_ICON_2     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322513872-7d61a2ec-297e-4ed4-b039-ac81147ed5ca.png"
#define WEATHER_ICON_3     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322513870-36aaae3f-230b-4717-b5a8-a937978df48c.png"
#define WEATHER_ICON_4     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322513924-80d1b83c-7aaf-4a64-80c3-e0cd93b18b61.png"
#define WEATHER_ICON_5     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322514334-3f8e5599-faf9-4551-855f-f6cc62d203e3.png"
#define WEATHER_ICON_6     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322514343-f48ebe31-cba6-4179-a157-4e5b2d4d12ae.png"
#define WEATHER_ICON_7     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322514455-c13da7b9-cd30-48ad-b6ef-af0e018e8f26.png"
#define WEATHER_ICON_8     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322514477-ee5f1465-1df0-45f6-a18d-8e341668a264.png"
#define WEATHER_ICON_9     "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322514484-9fd9584e-3d22-4dc3-8a0a-ee5972222b51.png"
#define WEATHER_ICON_10    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322514773-6cc8758b-08fe-48cb-b769-7c6d0d10cd56.png"
#define WEATHER_ICON_11    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322514822-ae80b7be-a988-4503-8515-f45b548d8dd9.png"
#define WEATHER_ICON_12    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322515055-240079dc-1fcf-49c3-8284-705b55a9ffb5.png"
#define WEATHER_ICON_13    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322515069-d7fe8530-bb74-4033-8aaf-838e8ea00cd9.png"
#define WEATHER_ICON_14    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322515170-f7b6361a-c430-43a0-92bc-e77d4ca122ee.png"
#define WEATHER_ICON_15    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322515257-3bb269c2-0c65-4a92-be42-8df4e4197c52.png"
#define WEATHER_ICON_16    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322515380-ac4caa6d-2e68-457b-a016-e1b60b884064.png"
#define WEATHER_ICON_17    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516301-94df2c74-eb20-4671-80bc-3bfddcbfa1e4.png"
#define WEATHER_ICON_18    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322515679-46d9b6e0-458d-4308-888a-b23cf13689f2.png"
#define WEATHER_ICON_19    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322515788-3a4bfbf3-de34-4a3e-a6a5-b424cef191a3.png"
#define WEATHER_ICON_20    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322515881-2a668ed4-082d-4129-8b24-66f79355f75d.png"
#define WEATHER_ICON_21    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516017-291c49e3-6014-47a1-b9cf-700a1129992e.png"
#define WEATHER_ICON_22    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516334-67913a0c-0436-4e88-baac-4262c3f47a9d.png"
#define WEATHER_ICON_23    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516441-ad6f5030-270d-4877-9e52-565aa8a35f80.png"
#define WEATHER_ICON_24    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516491-2a49cd2f-0554-4b63-81b8-8f10bb6a4d5c.png"
#define WEATHER_ICON_25    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516798-d02ca1b2-142b-4368-b9ed-7444e2135af1.png"
#define WEATHER_ICON_26    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516776-cc4d0148-d640-429d-8d6a-dee1ca60389e.png"
#define WEATHER_ICON_27    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516810-82cc50d8-129c-4a88-a9d1-fcc4281be7e8.png"
#define WEATHER_ICON_28    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322516962-236feb6b-a6f3-4ae8-be10-a98c19954bb8.png"
#define WEATHER_ICON_29    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322517080-2cc1cd8f-6a3b-4f06-9c58-fb266dbd25fb.png"
#define WEATHER_ICON_30    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322517351-4f14defc-65d9-411a-8ff9-a273c4e0ae12.png"
#define WEATHER_ICON_31    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322517295-36b5ec42-5157-41cd-bd59-715075a13208.png"
#define WEATHER_ICON_32    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322517532-bf49e806-2e6f-4496-86c5-a13208c022fa.png"
#define WEATHER_ICON_33    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322517488-59030409-ffbd-4f94-b0ba-a3984f6f233e.png"
#define WEATHER_ICON_34    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322517670-dd633d28-9b6c-43de-9a6f-a120fad9d856.png"
#define WEATHER_ICON_35    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322517791-6968fa92-7382-489f-91dc-31131c57850f.png"
#define WEATHER_ICON_36    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322517908-0dfc7d9e-0d13-49c5-9e17-167571d62456.png"
#define WEATHER_ICON_37    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322518040-766e01dc-1532-4f57-8275-88777deeb017.png"
#define WEATHER_ICON_38    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322518031-14f319d2-5a5f-4f0a-af96-41ad800a2ccf.png"
#define WEATHER_ICON_99    "https://cdn.nlark.com/yuque/0/2021/png/1013239/1619322518462-422e9768-739f-4686-8daa-418c53f613f8.png"