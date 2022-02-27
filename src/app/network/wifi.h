//
// Created by Locke Peng on 2022/2/20.
//

#include <vector>
#include <Ticker.h>
#include <memory>
#include <string>

class WifiEndpoint {
public:
    const char *ssid = nullptr;
    bool open = false;
public:
    WifiEndpoint(const char *ssid, const bool open) {
        this->ssid = ssid;
        this->open = open;
    }
};

class OnWifiConnectionListener {
public:
    virtual void onScan(std::vector<WifiEndpoint> endpoints) = 0;

    virtual void onConnected(const std::string &ssid) = 0;

    virtual void onDisconnected(const std::string &ssid) = 0;
};

class WifiConnection {
private:
    std::weak_ptr<OnWifiConnectionListener> _listener;
    bool _isConnected = false;
    std::shared_ptr<WifiEndpoint> _activeEndpoint = nullptr;
    const char *_ipAddress = nullptr;
    Ticker _ticker;
public:

    ~WifiConnection();

    void setOnConnectionListener(std::shared_ptr<OnWifiConnectionListener> listener);

    void scan();

    void connect(const char *ssid, const char *password);

    void disconnect();

    bool isConnected();

    WifiEndpoint *getActiveEndpoint();

    const char *getIpAddress();

private:
    void onCheckConnectionState();
};



