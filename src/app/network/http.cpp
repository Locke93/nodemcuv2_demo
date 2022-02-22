//
// Created by Locke Peng on 2022/2/22.
//

#include "http.h"

HttpConnection::HttpConnection(const char *host, const char *path) {
    request = host;
    request += path;
}

void HttpConnection::addQuery(const char *key, const char *value) {
    if (request.lastIndexOf('?') < 0) {
        request += '?';
    } else {
        request += '&';
    }
    request += key;
    request += '=';
    request += value;
}

const char *HttpConnection::post(const char *payload) {
    httpClient.begin(request);
    int code = httpClient.POST(payload);
    if (code == HTTP_CODE_OK) {
        return httpClient.getString().c_str();
    }
    return nullptr;
}

const char *HttpConnection::get() {
    Serial.println(request);
    httpClient.begin(request);
    int code = httpClient.GET();
    Serial.println(code);
    if (code == HTTP_CODE_OK) {
        return httpClient.getString().c_str();
    }
    return nullptr;
}

const char *HttpConnection::patch(const char *payload) {
    httpClient.begin(request);
    int code = httpClient.PATCH(payload);
    if (code == HTTP_CODE_OK) {
        return httpClient.getString().c_str();
    }
    return nullptr;
}