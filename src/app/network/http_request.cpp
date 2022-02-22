//
// Created by Locke Peng on 2022/2/22.
//

#include "http_request.h"

HttpRequest::HttpRequest(const char *host, const char *path) {
    request = host;
    request += path;
}

void HttpRequest::addQuery(const char *key, const char *value) {
    if (request.lastIndexOf('?') < 0) {
        request += '?';
    } else {
        request += '&';
    }
    request += key;
    request += '=';
    request += value;
}

String HttpRequest::toString() {
    return request;
}