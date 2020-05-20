//
// Created by Himatya on 2020/05/17.
//

#pragma once

#include "component_basic_test.hpp"

class RXComponentTest : public UnitTest {
public:
    RXComponentTest() : UnitTest("RXComponentTest") {}

    class SubComponent : public Component {};

    void runTest() override {
        beginTest("Visibility Test");
        {
            ComponentVisibilityTest<Component>(*this);
        }

        beginTest("Mouse Test");
        {
            ComponentMouseTest<Component>(*this);
        }

        beginTest("Bounds Test");
        {
            ComponentBoundsTest<Component>(*this);
        }

        beginTest("SubComponent Test");
        {
            ComponentVisibilityTest<SubComponent>(*this);
            ComponentMouseTest<SubComponent>(*this);
            ComponentBoundsTest<SubComponent>(*this);
        }
    }
};

static RXComponentTest rxComponentTest;
