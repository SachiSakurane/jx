//
// Created by Himatya on 2020/05/19.
//

#pragma once

#include <jx/reactive/base_component.hpp>
#include <jx/type_traits/sanity.hpp>

namespace jx
{
    template<class Type>
    class BaseComponentExtension {
    public:
        using ComponentType = Type;

        explicit BaseComponentExtension(ComponentType& parent) : parent_ {parent} {}

        [[nodiscard]] rxcpp::observable<std::reference_wrapper<juce::Graphics>> paint() const {
            return parent_.paint_.get_observable();
        }

        [[nodiscard]] rxcpp::observable<juce::Rectangle<int>> resized() const {
            return parent_.resized_.get_observable();
        }

    private:
        ComponentType& parent_;
    };

    template <class ComponentType>
    class _BaseComponentExtension : public SanityCheck<BaseComponentExtension<ComponentType>, ComponentType, juce::Component>
    {
    public:
        explicit _BaseComponentExtension (ComponentType &parent)
            : SanityCheck<BaseComponentExtension<ComponentType>, ComponentType, juce::Component> { parent } {}
    };
}