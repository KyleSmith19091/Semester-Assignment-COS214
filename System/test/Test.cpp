#include "../include/Falcon.h"

#include <gtest/gtest.h>

using namespace std;

TEST(FalconLaunchStateTest, initialState) {
    Falcon* falconWithState = new Falcon();
    EXPECT_EQ(falconWithState->getCurrentState(),"Idle");
    delete falconWithState;
}

TEST(FalconLaunchStateTest, stateCycle) {
    Falcon* falconWithState = new Falcon();
    EXPECT_EQ(falconWithState->getCurrentState(),"Idle");
    falconWithState->change();
    EXPECT_EQ(falconWithState->getCurrentState(),"Launched");
    falconWithState->change();
    EXPECT_EQ(falconWithState->getCurrentState(),"Seperated");
    falconWithState->change();
    EXPECT_EQ(falconWithState->getCurrentState(),"Returned");
    falconWithState->change();
    EXPECT_EQ(falconWithState->getCurrentState(),"Idle");
    delete falconWithState;
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
