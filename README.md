# jx
![Test Linux](https://github.com/SachiSakurane/jx/workflows/Test%20Linux/badge.svg)
![Test OSX](https://github.com/SachiSakurane/jx/workflows/Test%20OSX/badge.svg)
![Test Windows](https://github.com/SachiSakurane/jx/workflows/Test%20Windows/badge.svg)
![C++ 17](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B)
![BSL](http://img.shields.io/:license-BSL-blue.svg)

jx is a C++ header-only library that brings RX(Reactive Extensions) to JUCE.


## Requirements
- C++17 or higher
- [RxCpp](https://github.com/ReactiveX/RxCpp)
- [JUCE](https://github.com/juce-framework/JUCE)

## Installation
### JUCE5
Add this repository to your `Header Seatch Path` on Projucer.

### JUCE6
Add this repository to the `target_include_directories` in CmakeLists.txt.
```cmake
target_include_directories(PROJECT_NAME PRIVATE "path/to/jx")
```

## Getting Started
By inserting your own COMPONENT into jx::\<COMPONENT>, (If it is a type that jx can identify)`rx` extension is generated.
Let's actually add RX to the `Component`.
```c++
jx::RX<Component> rxComponent;

// It'll be called if the mouse down.
rxComponent.rx.mouse(jx::MouseEventType::kDown).subscribe([](const auto& enent){
    // on your lovely code...
});
```

## Getting Started
### Component
```c++
jx::RX<Component> rxComponent;

// It'll be called if the mouse down.
rxComponent.rx.mouse(jx::MouseEventType::kDown).subscribe([](const auto& enent){
    // on your lovely code...
});

// You can also get bounds events.
rxComponent.rx.boundsChanged().subscribe([this](const auto& b) {    
    // You can also write code here that you would normally write in resized().
}); 

```
### RXTimer
The timer callback is old, so let's subscribe to it in a nice way.
Keep the RXTimer variable, it does not need to be inherited.
```c++
class NiceClass : public Component {
public:
    NiceClass() 
        : ultimate_timer {30} // start at 30Hz
    {
        ultimate_timer.subscribe([]() {
            // on your hopefully code...
        });
        // Of course you can do it with Start() and Stop()!
    }

private:
    RXTimer ultimate_timer;

};
```

## Usage

## Author
[SachiSakurane](https://twitter.com/sakurane_sachi)

## License
[BSL](https://www.boost.org/users/license.html)
