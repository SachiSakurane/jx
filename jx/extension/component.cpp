//
// Created by Himatya on 2020/05/11.
//

using namespace mk2::rx;

ComponentExtension::ComponentExtension(juce::Component& parent)
    : parent_ { parent }
    , bounds { parent.getBounds() }
{
    bounds.get_observable().distinct_until_changed().subscribe([this](const auto& b) {
        parent_.setBounds(b);
    }) | disposed(bag_);

    parent_.addComponentListener(this);
    parent_.addMouseListener(this, false);
}

ComponentExtension::~ComponentExtension() {
    parent_.removeComponentListener(this);
    parent_.removeMouseListener(this);
}
