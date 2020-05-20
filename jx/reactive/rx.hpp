//
// Created by Himatya on 2020/05/11.
//

#pragma once

#include <jx/extension/component_listener.hpp>
#include <jx/reactive/reactive.hpp>

#include <jx/reactive/base_component.hpp>
#include <jx/extension/base_component.hpp>

namespace jx
{
    // Typeとis_sameでふるい掛けて
    // Componentはbased
    template <class Type>
    class RXType : public jx::BaseComponent<Type> {
    public:
    };

    template <class Type>
    class RX : public jx::BaseComponent<Type>
    {
    public:
        using BaseType = jx::BaseComponent<Type>;

        template <typename... Args>
        explicit RX (Args &&... args) : BaseType {std::forward<Args>(args)...}, rx(*this) {}

        const Reactive<BaseType, _BaseComponentExtension, _ComponentListenerExtension> rx;
    };
}
