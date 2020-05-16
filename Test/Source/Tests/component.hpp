//
// Created by Himatya on 2020/05/17.
//

#pragma once

class RXComponentTest : public UnitTest {
public:
    RXComponentTest() : UnitTest("RXComponentTest") {}

    void runTest() override {
        beginTest("bounds");
        {
            mk2::rx::dispose_bag bag;

            Rectangle<int> bounds1 {100, 50, 400, 200};
            jx::RX<Component> component;
            component.rx.boundsChanged().subscribe([this](const auto& b) {
                logMessage("subject bounds changed: " + b.toString());
            }) | mk2::rx::disposed(bag);
            component.rx.bounds.get_subscriber().on_next(bounds1);
            expect(bounds1 == component.rx.bounds.get_value());

            Rectangle<int> bounds2 {400, 500, 4000, 2100};
            component.rx.bounds.get_subscriber().on_next(bounds2);
            expect(bounds2 == component.rx.bounds.get_value());
        }
    }
};

static RXComponentTest rxComponentTest;
