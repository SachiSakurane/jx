//
// Created by Himatya on 2020/05/13.
//

#pragma once

#include <jx/utility/dispose_bag.hpp>
#include <jx/utility/noncopyable.hpp>

namespace jx {
    template <class Type>
    class has_dispose_bag : private jx::noncopyable<Type> {
    protected:
        jx::dispose_bag bag;
    };
}
