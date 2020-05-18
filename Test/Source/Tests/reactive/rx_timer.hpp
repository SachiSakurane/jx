//
// Created by Himatya on 2020/05/18.
//

#pragma once

class RXTimerTest : public UnitTest {
public:
    RXTimerTest() : UnitTest("RXTimerTest") {}

private:
    void runTest() override {
        beginTest("Timer Toggle Test");
        {
            mk2::rx::dispose_bag bag;
            jx::RXTimer timer;

            timer.activity.get_observable().subscribe([this](bool flag){
                logMessage("Timer toggled: " + std::to_string(flag));
            }) | mk2::rx::disposed(bag);

            timer.start(60);
            timer.stop();
            timer.stop();
            timer.start(60);
            timer.start(60);
            timer.stop();
        }
    }
};

static RXTimerTest rxTimerTest;
