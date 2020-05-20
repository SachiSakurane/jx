//
// Created by Himatya on 2020/05/17.
//

#pragma once

class RXComponentTest : public UnitTest {
public:
    RXComponentTest() : UnitTest("RXComponentTest") {}

    void runTest() override {
        beginTest("Visibility Test");
        {
            jx::dispose_bag bag;
            jx::RX<Component> component;

            component.rx.visibility().subscribe([this](const bool& b){
                logMessage("subject visibility changed: " + std::to_string(b));
            }) | jx::disposed(bag);

            component.setVisible(true);
            expect(component.isVisible());
            component.setVisible(false);
            expect(!component.isVisible());
        }

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
            component.rx.bounds().subscribe([this](const auto& b) {
                logMessage("subject bounds changed: " + b.toString());
            }) | jx::disposed(bag);
            component.setBounds(bounds1);

            Rectangle<int> bounds2 {400, 500, 4000, 2100};
            component.setBounds(bounds2);
        }
    }
};

static RXComponentTest rxComponentTest;
