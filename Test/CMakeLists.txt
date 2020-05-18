cmake_minimum_required(VERSION 3.15)

project(JX_TEST VERSION 0.0.1)

juce_add_gui_app(Test
        # VERSION ...                       # Set this if the app version is different to the project version
        # ICON_BIG ...                      # ICON_* arguments specify a path to an image file to use as an icon
        # ICON_SMALL ...
        # DOCUMENT_EXTENSIONS ...           # Specify file extensions that should be associated with this app
        # COMPANY_NAME ...                  # Specify the name of the app's author
        PRODUCT_NAME "Test")                  # The name of the final executable, which can differ from the target name

juce_generate_juce_header(Test)
target_include_directories(Test PRIVATE
        "../lib/libmk2/include"
        "../lib/RxCpp/Rx/v2/src"
        "../../jx")

target_sources(Test PRIVATE
        Source/Main.cpp)

target_compile_definitions(Test
        PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_DISPLAY_SPLASH_SCREEN=0)

target_link_libraries(Test PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_gui_basics)

set_target_properties (Test PROPERTIES
        CXX_STANDARD 17)