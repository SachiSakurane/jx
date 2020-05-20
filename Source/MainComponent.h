/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <jx/jx.hpp>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public jx::RX<Component>, private jx::has_dispose_bag<MainComponent>
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    void paint(Graphics&) override;

private:
    //==============================================================================
    // Your private member variables go here...
    jx::RX<Component> component_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
