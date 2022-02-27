//
// Created by Locke Peng on 2022/2/22.
//

#pragma once

#include <queue>
#include <memory>
#include "http_request.h"
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>


class HttpManager {

public:
    typedef std::function<void(const std::string &response)> HttpCallback;

private:
    static HttpManager *sHttpManager;
public:
    static HttpManager *getInstance();

    void addRequest(HttpRequest &request, HttpCallback &callback);

    void execute();

private:
    void doRequest(HttpRequest &request, HttpCallback &callback);

private:
    HTTPClient httpClient;
    WiFiClientSecure wiFiClient;
    std::queue<std::pair<HttpRequest, HttpCallback>> queue;
};
