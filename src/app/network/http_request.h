//
// Created by Locke Peng on 2022/2/22.
//

#pragma once

#include <iostream>
#include <ESP8266HTTPClient.h>

class HttpRequest {

public:
    HttpRequest(const char *host, const char *path);

    void addQuery(const char *key, const char *value);

    String toString();
private:
    String request;
};
