//
// Created by Himatya on 2020/05/11.
//

ComponentExtension::ComponentExtension(juce::Component& parent) : parent_ { parent }
{
    parent_.addComponentListener(this);
    parent_.addMouseListener(this, false);
}

ComponentExtension::~ComponentExtension() {
    parent_.removeComponentListener(this);
    parent_.removeMouseListener(this);
}
