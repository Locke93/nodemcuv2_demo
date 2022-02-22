//
// Created by Locke Peng on 2022/2/20.
//

#include "wifi.h"
#include <ESP8266WiFi.h>

void WifiConnection::setOnConnectionListener(std::shared_ptr<OnWifiConnectionListener> listener) {
    this->_listener = std::weak_ptr<OnWifiConnectionListener>(listener);
}

void WifiConnection::scan() {
}

void WifiConnection::connect(const char *ssid, const char *password) {
    Serial.println("======== wifi connecting... =========");
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    _activeEndpoint = std::make_shared<WifiEndpoint>(ssid, password == nullptr);
    _ticker.attach(5, std::bind(&WifiConnection::onCheckConnectionState, this));
}

void WifiConnection::disconnect() {
    WiFi.disconnect();
}

void WifiConnection::onCheckConnectionState() {
    if (WiFi.isConnected() && !_isConnected) {
        Serial.println("======== wifi connected =========");
        Serial.println(WiFi.localIP());
        auto localIp = WiFi.localIP().toString();
        char *temp = new char[localIp.length() + 1];
        localIp.toCharArray(temp, localIp.length() + 1, 0);
        _ipAddress = temp;
        _isConnected = true;
        auto callback = _listener.lock();
        if (callback) callback->onConnected(_activeEndpoint->ssid);
    } else if (!WiFi.isConnected() && _isConnected) {
        Serial.println("======== wifi disconnected =========");
        _isConnected = false;
        delete _ipAddress;
        auto *ssid = _activeEndpoint->ssid;
        _activeEndpoint = nullptr;
        auto callback = _listener.lock();
        if (callback) callback->onDisconnected(ssid);
    }
}

bool WifiConnection::isConnected() {
    return _isConnected;
}

WifiEndpoint *WifiConnection::getActiveEndpoint() {
    return _activeEndpoint.get();
}

const char *WifiConnection::getIpAddress() {
    return _ipAddress;
}

WifiConnection::~WifiConnection() {
    _ticker.detach();
    _activeEndpoint = nullptr;
    if (_ipAddress) delete _ipAddress;
}