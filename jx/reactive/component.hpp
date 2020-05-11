//
// Created by Himatya on 2020/05/11.
//

#pragma once

template <class Type, typename Enable = void>
class ReactiveComponent;

template <class ComponentType>
class ReactiveComponent<ComponentType, std::enable_if_t<std::is_base_of_v<juce::Component, ComponentType>>>
: public ComponentType
{
public:
    template<typename... Args>
    ReactiveComponent(Args&&... args) : ComponentType(std::forward<Args>(args)...), rx(*this) {}

    const ComponentExtension rx;
};
