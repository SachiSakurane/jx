//
// Created by Himatya on 2020/05/11.
//

#pragma once

enum MouseEventType {
    kMove,
    kEnter,
    kExit,
    kDown,
    kDrag,
    kUp,
    kDoubleClick,
};

class ComponentExtension
    : private juce::ComponentListener
    , private juce::MouseListener {
public:
    explicit ComponentExtension(juce::Component& parent);
    ~ComponentExtension() override;

    [[nodiscard]] rxcpp::observable<juce::MouseEvent> mouse(MouseEventType type) const {
        return mouse_[type].get_observable();
    }

    [[nodiscard]] rxcpp::observable<std::pair<juce::MouseEvent, juce::MouseWheelDetails>> wheelMove() const {
        return wheel_move_.get_observable();
    }

    [[nodiscard]] rxcpp::observable<std::pair<juce::MouseEvent, float>> magnify() const {
        return magnify_.get_observable();
    }

private:
    void mouseMove (const juce::MouseEvent &event) override {
        mouse_[MouseEventType::kMove].get_subscriber().on_next(event);
    }
    void mouseEnter (const juce::MouseEvent &event) override {
        mouse_[MouseEventType::kEnter].get_subscriber().on_next(event);
    }
    void mouseExit (const juce::MouseEvent &event) override {
        mouse_[MouseEventType::kExit].get_subscriber().on_next(event);
    }
    void mouseDown (const juce::MouseEvent &event) override {
        mouse_[MouseEventType::kDown].get_subscriber().on_next(event);
    }
    void mouseDrag (const juce::MouseEvent &event) override {
        mouse_[MouseEventType::kDrag].get_subscriber().on_next(event);
    }
    void mouseUp (const juce::MouseEvent &event) override {
        mouse_[MouseEventType::kUp].get_subscriber().on_next(event);
    }
    void mouseDoubleClick (const juce::MouseEvent &event) override {
        mouse_[MouseEventType::kDoubleClick].get_subscriber().on_next(event);
    }
    void mouseWheelMove (const juce::MouseEvent &event, const juce::MouseWheelDetails &wheel) override {
        wheel_move_.get_subscriber().on_next( std::make_pair(event, wheel) );
    }
    void mouseMagnify (const juce::MouseEvent &event, float scaleFactor) override {
        magnify_.get_subscriber().on_next( std::make_pair(event, scaleFactor) );
    }

    mk2::rx::dispose_bag bag_;
    juce::Component& parent_;

    const rxcpp::subjects::subject<juce::MouseEvent> mouse_[MouseEventType::kDoubleClick + 1];
    const rxcpp::subjects::subject<std::pair<juce::MouseEvent, juce::MouseWheelDetails>> wheel_move_;
    const rxcpp::subjects::subject<std::pair<juce::MouseEvent, float>> magnify_;
};
