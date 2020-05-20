/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

using namespace jx;

//==============================================================================
MainComponent::MainComponent()
{
    rx.resized().subscribe([this](const auto& bounds) {
        component_.setBounds(0, 0, bounds.getWidth() * 0.2, bounds.getHeight() * 0.2);
    }) | disposed(bag);

    component_.rx.paint().subscribe([](Graphics& g) {
        g.fillAll(Colour::fromRGB(0,0,0));
    }) | disposed(bag);

    // mouse
    rx.mouse(jx::MouseEventType::kDown).subscribe([](const auto&) {
        std::cout << "Mouse Down!" << std::endl;
    }) | disposed(bag);

    component_.rx.mouse(jx::MouseEventType::kDown).subscribe([](const auto&) {
        std::cout << "Sub Component Mouse Down!" << std::endl;
    }) | disposed(bag);

    addAndMakeVisible(component_);

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
