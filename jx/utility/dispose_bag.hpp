//
// Created by Himatya on 2019/11/30.
//

#pragma once

namespace jx {
    class dispose_bag {
    public:
        dispose_bag() = default;

        dispose_bag(dispose_bag&& obj) noexcept
            : subscriptions_ { std::move(obj.subscriptions_) } {
            obj.subscriptions_.clear();
        }

        ~dispose_bag() {
            for (auto&& subscription : subscriptions_) {
                if (subscription.is_subscribed())
                    subscription.unsubscribe();
            }
        }

        void push(rxcpp::composite_subscription &&subscription) {
            subscriptions_.emplace_back(subscription);
        }

        dispose_bag& operator +=(rxcpp::composite_subscription &&subscription) {
            this->subscriptions_.emplace_back(subscription);
            return *this;
        }

    private:
        std::vector<rxcpp::composite_subscription> subscriptions_;
    };
}