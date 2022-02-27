//
// Created by Locke Peng on 2022/2/22.
//

#pragma once

#include <string>

class HttpRequest {

public:
    HttpRequest(const std::string &host, const std::string &path);

    void addQuery(const std::string &key, const std::string &value);

    std::string toString();

private:
    std::string request;
};
