//
// Created by Locke Peng on 2022/2/20.
//

#include <vector>
#include <Ticker.h>
#include <memory>
#include <string>

class WifiEndpoint {
public:
    std::string ssid;
    bool open = false;
public:
    WifiEndpoint(const std::string &ssid, const bool open) {
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
    std::string _ipAddress;
    Ticker _ticker;
public:

    ~WifiConnection();

    void setOnConnectionListener(std::shared_ptr<OnWifiConnectionListener> listener);

    void scan();

    void connect(const std::string &ssid, const std::string &password);

    void disconnect();

    bool isConnected();

    WifiEndpoint *getActiveEndpoint();

    std::string getIpAddress();

private:
    void onCheckConnectionState();
};



