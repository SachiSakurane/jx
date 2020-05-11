/** BEGIN_JUCE_MODULE_DECLARATION

    ID: jx
    vendor: SachiSakurane
    version: 0.0.0
    name: jx
    description: RX for JUCE
    website: https://github.com/SachiSakurane/jx
    license: MIT

    dependencies:

    END_JUCE_MODULE_DECLARATION
*/

#pragma once

#include <type_traits>
#include <utility>

#include <juce_core/juce_core.h>
#include <juce_data_structures/juce_data_structures.h>
#include <juce_events/juce_events.h>
#include <juce_graphics/juce_graphics.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <mk2/rx.hpp>
#include <rxcpp/rx.hpp>

namespace jx {
#include "extension/component.hpp"

#include "reactive/component.hpp"

#include "reactive/rx.hpp"
}