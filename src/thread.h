//
// Created by Locke Peng on 2021/3/13.
//

#ifndef NODEMCUV2_THREAD_H
#define NODEMCUV2_THREAD_H

class Thread {
public:
    virtual void async(const uint32_t *timestamp) = 0;
    virtual ~Thread() = default;
};

#endif //NODEMCUV2_THREAD_H
