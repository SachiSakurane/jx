//
// Created by Himatya on 2020/05/20.
//

#pragma once

template<class ComponentType, class TestType>
void ComponentVisibilityTest(TestType& test) {
    jx::dispose_bag bag;
    jx::RX<ComponentType> component;

    component.rx.visibility().subscribe([&test](const bool& b){
        test.logMessage("subject visibility changed: " + std::to_string(b));
    }) | jx::disposed(bag);

    component.setVisible(true);
    test.expect(component.isVisible());
    component.setVisible(false);
    test.expect(!component.isVisible());
}

template<class ComponentType, class TestType>
void ComponentMouseTest(TestType& test) {
    jx::dispose_bag bag;
    jx::RX<ComponentType> component;

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

template<class ComponentType, class TestType>
void ComponentBoundsTest(TestType& test) {
    jx::dispose_bag bag;
    jx::RX<ComponentType> component;

    Rectangle<int> bounds1 {100, 50, 400, 200};
    component.rx.bounds().subscribe([&test](const auto& b) {
        test.logMessage("subject bounds changed: " + b.toString());
    }) | jx::disposed(bag);
    component.setBounds(bounds1);

    Rectangle<int> bounds2 {400, 500, 4000, 2100};
    component.setBounds(bounds2);
}
