//
// Created by Himatya on 2020/05/19.
//

#pragma once

#include <type_traits>

namespace jx
{
    template <class Type, template <class> class Extension>
    class ReactiveImpl2 : public Extension<Type>
    {
    public:
        explicit ReactiveImpl2 (Type &type) : Extension<Type> { type } {}
    };

    template <class Type, template <class> class Extension, template <class> class... Extensions>
    class ReactiveImpl : public ReactiveImpl2<Type, Extension>, public ReactiveImpl<Type, Extensions...>
    {
    public:
        explicit ReactiveImpl (Type &type)
            : ReactiveImpl2<Type, Extension> { type }, ReactiveImpl<Type, Extensions...> { type } {}
    };

    template <class Type, template <class> class Extension>
    class ReactiveImpl<Type, Extension> : public ReactiveImpl2<Type, Extension>
    {
    public:
        explicit ReactiveImpl (Type &type) : ReactiveImpl2<Type, Extension> { type } {}
    };

    template <class Type, template <class> class... ExtensionType>
    class Reactive : public ReactiveImpl<Type, ExtensionType...>
    {
    public:
        explicit Reactive (Type &type) : ReactiveImpl<Type, ExtensionType...> { type } {}
    };
}