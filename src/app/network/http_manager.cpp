//
// Created by Locke Peng on 2022/2/22.
//

#include "http_manager.h"

HttpManager *HttpManager::sHttpManager = nullptr;

HttpManager *HttpManager::getInstance() {
    if (sHttpManager == nullptr) {
        sHttpManager = new HttpManager();
    }
    return sHttpManager;
}

void HttpManager::addRequest(HttpRequest &request, HttpCallback &callback) {
    queue.push(std::make_pair(request, callback));
}

void HttpManager::execute() {
    if (queue.empty()) return;
    auto pair = queue.front();
    queue.pop();
    HttpRequest &request = pair.first;
    HttpCallback callback = pair.second;
    doRequest(request, callback);
}

void HttpManager::doRequest(HttpRequest &request, HttpCallback &callback) {
    wiFiClient.setInsecure();
    httpClient.begin(wiFiClient, request.toString());
    int code = httpClient.GET();
    if (code == HTTP_CODE_OK) {
        callback(httpClient.getString().c_str());
    } else {
        callback(nullptr);
    }
    httpClient.end();
}