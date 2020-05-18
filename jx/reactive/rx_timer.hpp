//
// Created by Himatya on 2020/05/16.
//

#pragma once

#include <juce_events/juce_events.h>

namespace jx
{
    class RXTimer : private juce::Timer
    {
    public:
        struct RXTimerEvent {};

        RXTimer () = default;
        explicit RXTimer (int freq)
        {
            start(freq);
        }

        void start (int freq)
        {
            startTimerHz(freq);
            activity.get_subscriber().on_next(true);
        }

        void stop ()
        {
            stopTimer();
            activity.get_subscriber().on_next(false);
        }

        [[nodiscard]] rxcpp::composite_subscription subscribe (std::function<void ()> &&f) const
        {
            return timer_.get_observable().subscribe([v = std::move(f)] (const auto &) {
                v();
            });
        }

        [[nodiscard]] bool running () const { return isTimerRunning(); }

        const rxcpp::subjects::subject<bool> activity;

    private:
        void timerCallback () override
        {
            timer_.get_subscriber().on_next(RXTimerEvent());
        }

        const rxcpp::subjects::subject <RXTimerEvent> timer_;
    };
}
