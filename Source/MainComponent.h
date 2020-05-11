/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public jx::RX<Component>
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;

    class TestComponent : public Component {
    private:
        void paint (Graphics& g) override {
            g.fillAll(Colour::fromRGB(0, 0, 0));
        }
    };

private:
    //==============================================================================
    // Your private member variables go here...
    mk2::rx::dispose_bag bag_;

    jx::RX<TestComponent> test_component_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
