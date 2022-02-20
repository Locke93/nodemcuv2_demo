//
// Created by Locke Peng on 2021/3/19.
//

#ifndef NODEMCUV2_UI_COMPONENT_H
#define NODEMCUV2_UI_COMPONENT_H

class UiComponent {
public:
    virtual ~UiComponent() = default;
    virtual void async(const uint32_t *timestamp) = 0;
};

#endif //NODEMCUV2_UI_COMPONENT_H
