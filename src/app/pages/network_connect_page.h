//
// Created by Locke Peng on 2022/2/21.
//

#include "../screen_page.h"
#include "../../view/gif_view.h"
#include "../../view/text_view.h"
#include "../network/wifi.h"

class NetworkConnectPage : public ScreenPage {

    class OnNetworkConnectionListener : public OnWifiConnectionListener {
    public:
        OnNetworkConnectionListener(NetworkConnectPage *parent);

    public:
        void onScan(std::vector<WifiEndpoint> endpoints) override;

        void onConnected(const char *ssid) override;

        void onDisconnected(const char *ssid) override;

    private:
        NetworkConnectPage *parent;
    };


public:
    void onCreate() override;

private:
    void connectToNetwork();

private:
    GifView *iconView = nullptr;
    TextView *textView = nullptr;
    std::shared_ptr<WifiConnection> connection;
    std::shared_ptr<OnNetworkConnectionListener> listener;
};