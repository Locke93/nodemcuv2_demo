//
// Created by Locke Peng on 2022/2/22.
//

#include "http_request.h"

HttpRequest::HttpRequest(const std::string &host, const std::string &path) {
    request = host;
    request += path;
}

void HttpRequest::addQuery(const std::string &key, const std::string &value) {
    if (request.find_last_of('?') == std::string::npos) {
        request += '?';
    } else {
        request += '&';
    }
    request += key;
    request += '=';
    request += value;
}

std::string HttpRequest::toString() {
    return request;
}