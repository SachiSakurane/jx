//
// Created by Himatya on 2020/05/20.
//

#pragma once

class RXButtonTest : public UnitTest {
public:
    RXButtonTest() : UnitTest("RXButtonTest") {}

private:
    void runTest() override {
        beginTest("Visibility Test");
        {
            ComponentVisibilityTest<Button>(*this);
        }

        beginTest("Mouse Test");
        {
            ComponentMouseTest<Button>(*this);
        }

        beginTest("Bounds Test");
        {
            ComponentBoundsTest<Button>(*this);
        }
    }
};

static RXButtonTest rxButtonTest;
