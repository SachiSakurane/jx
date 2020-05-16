/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>

#include "Tests/component.hpp"

//==============================================================================
class TestApplication  : public JUCEApplication
{
public:
    //==============================================================================
    TestApplication() = default;

    const String getApplicationName() override       { return ProjectInfo::projectName; }
    const String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override       { return true; }

    //==============================================================================
    void initialise (const String& commandLine) override
    {
        UnitTestRunner runner_;
        runner_.runAllTests();

        quit();
    }

    void shutdown() override {}

    //==============================================================================
    void systemRequestedQuit() override
    {
        quit();
    }
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (TestApplication)
