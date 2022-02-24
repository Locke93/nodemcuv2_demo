//
// Created by Locke Peng on 2022/2/21.
//

#include "network_connect_page.h"
#include "weather_page.h"
#include "../application.h"
#include "../resources.h"
#include "../local_properties.h"

void NetworkConnectPage::onCreate() {
    ViewGroup *rootView = new ViewGroup();

    iconView = new GifView();
    iconView->setImageSet(32, 32, wifi_icon_gif);
    iconView->setPosition(-4, 0);
    iconView->setInterval(300);
    rootView->addView(iconView);

    textView = new TextView();
    textView->setPosition(34, 22);
    textView->setFont(u8g2_font_6x10_tr);
    rootView->addView(textView);
    setContentView(reinterpret_cast<View *>(rootView));
    // connect to network via WiFi
    connectToNetwork();
}

void NetworkConnectPage::connectToNetwork() {
    if (!connection.get()) connection = std::make_shared<WifiConnection>();
    if (!listener.get()) listener = std::make_shared<OnNetworkConnectionListener>(this);
    connection->setOnConnectionListener(listener);
    connection->connect(WIFI_SSID, WIFI_PASSWORD);
}

NetworkConnectPage::OnNetworkConnectionListener::OnNetworkConnectionListener(NetworkConnectPage *parent) {
    this->parent = parent;
}

void NetworkConnectPage::OnNetworkConnectionListener::onScan(std::vector<WifiEndpoint> endpoints) {
}

void NetworkConnectPage::OnNetworkConnectionListener::onConnected(const char *ssid) {
    parent->textView->setText(parent->connection->getIpAddress());
    Application::getInstance()->launchScreenPageDelayed(new WeatherPage(), 2000);
}

void NetworkConnectPage::OnNetworkConnectionListener::onDisconnected(const char *ssid) {
    parent->textView->setText("disconnected");
}