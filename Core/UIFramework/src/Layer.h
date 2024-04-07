//
// Created by 4rtemTrickster on 07-Apr-24.
//

#pragma once

class Layer
{
public:
    virtual ~Layer() = default;

    virtual void on_attach() {}
    virtual void on_detach() {}

    virtual void on_update(float ts) {}
    virtual void on_ui_render() {}
};

template<class T>
concept LayerSubclass = std::is_base_of<Layer, T>::value;

