//
// Created by Locke Peng on 2022/2/22.
//

#pragma once

#include <iostream>
#include <ESP8266HTTPClient.h>

class HttpConnection {
public:
    HttpConnection(const char *host, const char *path);

    void addQuery(const char *key, const char *value);

    const char *post(const char *payload);

    const char *get();

    const char *patch(const char *payload);

private:
    String request;
    HTTPClient httpClient;
};
