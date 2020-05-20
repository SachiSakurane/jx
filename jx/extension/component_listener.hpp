
//
// Created by Himatya on 2020/05/11.
//

#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include <jx/type_traits/sanity.hpp>
#include <jx/utility/disposed.hpp>
#include <jx/utility/has_dispose_bag.hpp>

namespace jx
{
    enum MouseEventType
    {
        kMove,
        kEnter,
        kExit,
        kDown,
        kDrag,
        kUp,
        kDoubleClick,
    };

    class ComponentListenerExtension
        : juce::ComponentListener
        , juce::MouseListener
    {
        juce::Component &parent_;

    public:
        explicit ComponentListenerExtension (juce::Component &parent)
            : parent_ { parent }
        {
            parent_.addComponentListener(this);
            parent_.addMouseListener(this, true);
        }

        ~ComponentListenerExtension () override
        {
            parent_.removeComponentListener(this);
            parent_.removeMouseListener(this);
        }

        [[nodiscard]] rxcpp::observable <juce::MouseEvent> mouse (MouseEventType type) const
        {
            return mouse_[type].get_observable();
        }

        [[nodiscard]] rxcpp::observable <std::pair<juce::MouseEvent, juce::MouseWheelDetails>> wheelMove () const
        {
            return wheel_move_.get_observable();
        }

        [[nodiscard]] rxcpp::observable <std::pair<juce::MouseEvent, float>> magnify () const
        {
            return magnify_.get_observable();
        }

        [[nodiscard]] rxcpp::observable <juce::Rectangle<int>> bounds () const
        {
            return bounds_.get_observable().distinct_until_changed();
        }

        [[nodiscard]] rxcpp::observable <bool> visibility () const {
            return visibility_.get_observable();
        }

        [[nodiscard]] rxcpp::observable <bool> enablement () const {
            return enablement_.get_observable();
        }

    private:
        void componentMovedOrResized (juce::Component &, bool moved, bool resized) override
        {
            if (moved || resized)
                bounds_.get_subscriber().on_next(parent_.getBounds());
        }

        void componentVisibilityChanged (juce::Component &) override {
            visibility_.get_subscriber().on_next(parent_.isVisible());
        }

        void componentEnablementChanged (juce::Component &) override {
            enablement_.get_subscriber().on_next(parent_.isEnabled());
        }

        void mouseMove (const juce::MouseEvent &event) override
        {
            mouse_[MouseEventType::kMove].get_subscriber().on_next(event);
        }

        void mouseEnter (const juce::MouseEvent &event) override
        {
            mouse_[MouseEventType::kEnter].get_subscriber().on_next(event);
        }

        void mouseExit (const juce::MouseEvent &event) override
        {
            mouse_[MouseEventType::kExit].get_subscriber().on_next(event);
        }

        void mouseDown (const juce::MouseEvent &event) override
        {
            mouse_[MouseEventType::kDown].get_subscriber().on_next(event);
        }

        void mouseDrag (const juce::MouseEvent &event) override
        {
            mouse_[MouseEventType::kDrag].get_subscriber().on_next(event);
        }

        void mouseUp (const juce::MouseEvent &event) override
        {
            mouse_[MouseEventType::kUp].get_subscriber().on_next(event);
        }

        void mouseDoubleClick (const juce::MouseEvent &event) override
        {
            mouse_[MouseEventType::kDoubleClick].get_subscriber().on_next(event);
        }

        void mouseWheelMove (const juce::MouseEvent &event, const juce::MouseWheelDetails &wheel) override
        {
            wheel_move_.get_subscriber().on_next(std::make_pair(event, wheel));
        }

        void mouseMagnify (const juce::MouseEvent &event, float scaleFactor) override
        {
            magnify_.get_subscriber().on_next(std::make_pair(event, scaleFactor));
        }

        const rxcpp::subjects::subject <juce::MouseEvent> mouse_[MouseEventType::kDoubleClick + 1];
        const rxcpp::subjects::subject <std::pair<juce::MouseEvent, juce::MouseWheelDetails>> wheel_move_;
        const rxcpp::subjects::subject <std::pair<juce::MouseEvent, float>> magnify_;

        const rxcpp::subjects::subject <juce::Rectangle<int>> bounds_;
        const rxcpp::subjects::subject <bool> visibility_;
        const rxcpp::subjects::subject <bool> enablement_;

    };

    template <class ComponentType>
    class _ComponentListenerExtension : public SanityCheck<ComponentListenerExtension, ComponentType, juce::Component>
    {
    public:
        explicit _ComponentListenerExtension (ComponentType &parent)
            : SanityCheck<ComponentListenerExtension, ComponentType, juce::Component>{parent} {}
    };
}
