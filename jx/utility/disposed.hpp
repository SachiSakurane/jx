//
// Created by Himatya on 2019/12/01.
//

#pragma once

#include <jx/utility/dispose_bag.hpp>

namespace jx {
    class disposed_tag {
    public:
        explicit disposed_tag(jx::dispose_bag& bag) : bag_{bag} {}

        void push(rxcpp::composite_subscription&& subscription) {
            bag_.push(std::move(subscription));
        }

    private:
        jx::dispose_bag& bag_;
    };

    inline void operator | (rxcpp::composite_subscription&& subscription, jx::disposed_tag bag) {
        bag.push(std::move(subscription));
    }

    inline disposed_tag disposed(jx::dispose_bag& by) {
        return disposed_tag{by};
    }
}