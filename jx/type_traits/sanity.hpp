//
// Created by Himatya on 2020/05/13.
//

#pragma once

template <class Type, class TargetType, class BaseType, typename Enable = void>
class SanityCheck {
public:
    explicit SanityCheck(TargetType&) {}
};

template <class Type, class TargetType, class BaseType>
class SanityCheck <Type, TargetType, BaseType, std::enable_if_t<std::is_base_of_v<TargetType, BaseType>>>
    : public Type  {
public:
    explicit SanityCheck(TargetType& parent) : Type {parent} {}
};
