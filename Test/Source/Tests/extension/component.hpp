//
// Created by Himatya on 2020/05/17.
//

#pragma once

class RXComponentTest : public UnitTest {
public:
    RXComponentTest() : UnitTest("RXComponentTest") {}

    void runTest() override {
        beginTest("Mouse Test");
        {
            jx::dispose_bag bag;
            jx::RX<Component> component;

            component.rx.mouse(jx::MouseEventType::kDown).subscribe([](const auto&){}) | jx::disposed(bag);
            component.rx.mouse(jx::MouseEventType::kDrag).subscribe([](const auto&){}) | jx::disposed(bag);
            component.rx.mouse(jx::MouseEventType::kDoubleClick).subscribe([](const auto&){}) | jx::disposed(bag);
            component.rx.mouse(jx::MouseEventType::kUp).subscribe([](const auto&){}) | jx::disposed(bag);
            component.rx.mouse(jx::MouseEventType::kExit).subscribe([](const auto&){}) | jx::disposed(bag);
            component.rx.mouse(jx::MouseEventType::kMove).subscribe([](const auto&){}) | jx::disposed(bag);
            component.rx.mouse(jx::MouseEventType::kEnter).subscribe([](const auto&){}) | jx::disposed(bag);

            component.rx.wheelMove().subscribe([](const auto&){}) | jx::disposed(bag);

            component.rx.magnify().subscribe([](const auto&){}) | jx::disposed(bag);
        }

        beginTest("Bounds Test");
        {
            jx::dispose_bag bag;

            Rectangle<int> bounds1 {100, 50, 400, 200};
            jx::RX<Component> component;
            component.rx.boundsChanged().subscribe([this](const auto& b) {
                logMessage("subject bounds changed: " + b.toString());
            }) | jx::disposed(bag);
            component.rx.bounds.get_subscriber().on_next(bounds1);
            expect(bounds1 == component.rx.bounds.get_value());

            Rectangle<int> bounds2 {400, 500, 4000, 2100};
            component.rx.bounds.get_subscriber().on_next(bounds2);
            expect(bounds2 == component.rx.bounds.get_value());
        }
    }
};

static RXComponentTest rxComponentTest;
