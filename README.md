# nodemcuv2_demo
A demo ui lib for NodeMCU/ESP8266, base on the [U8G2](https://github.com/olikraus/u8g2)

### Why use it
* Quickly to finish the UI development base on the U8G2
* High scalability
* Support animation

### Implemented:
* TextView
* ImageView
* GifView
* TranslateAnimation


### Usage:
1. Init UiThread and add root view into it.
```c++
U8G2_SSD1306_128X32_UNIVISION_1_SW_I2C u8g2(U8G2_R2, CLOCK_PIN, DATA_PIN, RESET_PIN);

void setup() {
    UiThread *uiThread = ThreadManager::getInstance()->getUiThread();
    uiThread->init(&u8g2);
    auto *rootView = new ViewGroup();
    createView(rootView);
    uiThread->setRootView(reinterpret_cast<View *>(rootView));
}
```

2. Create content views and config the animation
```c++
void createView(ViewGroup *rootView) {
    auto *textView = new TextView();
    textView->setText("Hello");
    textView->setFont(u8g2_font_9x15_tr);
    rootView->addView(reinterpret_cast<View *>(textView));
    auto animation = new TranslateAnimation(textView, 0, 20, 48, 20);
    reinterpret_cast<Animation *>(animation)->setDuration(3000);
    reinterpret_cast<Animation *>(animation)->setReverse(true);
    animation->start();
}
```


### Licence
> Copyright [lcokean] [1072174696@qq.com]
>
> Licensed under the Apache License, Version 2.0 (the "License");
> you may not use this file except in compliance with the License.
> You may obtain a copy of the License at
>
>    http://www.apache.org/licenses/LICENSE-2.0
>
> Unless required by applicable law or agreed to in writing, software
> distributed under the License is distributed on an "AS IS" BASIS,
> WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
> See the License for the specific language governing permissions and
> limitations under the License.
