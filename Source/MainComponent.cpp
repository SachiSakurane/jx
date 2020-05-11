/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

using namespace mk2::rx;

//==============================================================================
MainComponent::MainComponent()
{
    rx.mouse(jx::MouseEventType::kDown).subscribe([](const auto&) {
        std::cout << "test" << std::endl;
    }) | disposed(bag_);

    rx.bounds.get_observable().subscribe([this](const auto& bounds) {
        test_component_.setBounds(0, 0, bounds.getWidth() * 0.2, bounds.getHeight() * 0.2);
    }) | disposed(bag_);

    addAndMakeVisible(test_component_);

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}
