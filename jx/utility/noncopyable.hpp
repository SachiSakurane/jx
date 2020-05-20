//
// Created by Himatya on 2018/01/12.
//

#pragma once

namespace jx{

    template<typename T>
    class noncopyable
    {
    protected:
        noncopyable() = default;
        virtual ~noncopyable() = default;
    private:
        noncopyable(const noncopyable &) = delete;
        noncopyable& operator=(const noncopyable &) = delete;
    };

}
