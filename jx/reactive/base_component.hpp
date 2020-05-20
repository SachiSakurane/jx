//
// Created by Himatya on 2020/05/19.
//

#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include <jx/utility/void_event.hpp>

namespace jx
{
    template<class ComponentType, class Enable = void>
    class BaseComponent {};

    template<class ComponentType>
    class BaseComponent<ComponentType, std::enable_if_t<std::is_base_of_v<juce::Component, ComponentType>>>
        : public ComponentType {
    public:
        template <typename... Args>
        explicit BaseComponent (Args &&... args) : ComponentType {std::forward<Args>(args)... } {}

    private:
        template <class Type>
        friend class BaseComponentExtension;

        void paint(juce::Graphics& g) override {
            ComponentType::paint(g);
            paint_.get_subscriber().on_next(std::ref(g));
        }

        void resized() override {
            ComponentType::resized();
            resized_.get_subscriber().on_next(ComponentType::getLocalBounds());
        }

        const rxcpp::subjects::subject<std::reference_wrapper<juce::Graphics>> paint_;
        const rxcpp::subjects::subject<juce::Rectangle<int>> resized_;
    };
}
