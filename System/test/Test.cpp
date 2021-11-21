#include "../include/Falcon.h"
#include "../include/Falcon9Creator.h"
#include "../include/FalconHeavyCreator.h"
#include "../include/Cluster.h"
#include "../include/VectorOfCargo.h"
#include "../include/Cargo.h"
#include "../include/LinkedListOfCrew.h"
#include "../include/Crew.h"
#include "../include/Satelite.h"
#include "../include/SatelliteCreator.h"

#include <gtest/gtest.h>

using namespace std;

TEST(FalconLaunchStateTest, initialState) {
    Falcon* falconWithState = new Falcon("falcon-heavy");
    EXPECT_EQ(falconWithState->getCurrentState(),"Idle");
    delete falconWithState;
}

TEST(FalconLaunchStateTest, stateCycle) {
    Falcon* falconWithState = new Falcon("falcon-9");
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

TEST(FalconCreation, checkAmountOfCores) {
    Falcon* falcon9 = new Falcon("falcon-9");
    EXPECT_EQ(falcon9->getCoreList().size(),1);
    Falcon* falconHeavy = new Falcon("falcon-heavy");
    EXPECT_EQ(falconHeavy->getCoreList().size(),3);
}

TEST(FalconCreation, checkAmountOfCoresWithFactory) {
    SpacecraftCreator* falcon9Creator = new Falcon9Creator();
    Falcon* falcon9 = (Falcon*)falcon9Creator->createSpacecraft(); 
    EXPECT_EQ(falcon9->getCoreList().size(),1);

    SpacecraftCreator* falconHeavyCreator = new FalconHeavyCreator();
    Falcon* falconHeavy = (Falcon*)falconHeavyCreator->createSpacecraft(); 
    EXPECT_EQ(falconHeavy->getCoreList().size(),3);
}

TEST(ClusterCreation, edgeAmountOfSatellites) {
    SpacecraftCreator* falcon9Creator = new Falcon9Creator();
    Falcon* falcon9 = (Falcon*)falcon9Creator->createSpacecraft(); 
    Cluster* cluster = new Cluster(falcon9);
    MissionControl* missionControl = new MissionControl();

    EXPECT_ANY_THROW(cluster->generateSatellites(missionControl, -1));
    EXPECT_ANY_THROW(cluster->generateSatellites(missionControl, -60));
    EXPECT_ANY_THROW(cluster->generateSatellites(missionControl, 61));
    EXPECT_ANY_THROW(cluster->generateSatellites(missionControl, 100));
}

TEST(CargoIteration, checkEmptyState) {
    VectorOfCargo* cargoList = new VectorOfCargo();
    Iterator* cargoListIterator = cargoList->createIterator();
    EXPECT_TRUE(cargoListIterator->isDone());
}

TEST(CargoIteration, removingFromEmptyList) {
    VectorOfCargo* cargoList = new VectorOfCargo();
    EXPECT_ANY_THROW(cargoList->removeCargo(new Cargo("REMOVE-ME", 0)));
}

TEST(CrewIteration, checkEmptyState) {
    LinkedListOfCrew* crewList = new LinkedListOfCrew();
    Iterator* cargoListIterator = crewList->createIterator();
    EXPECT_TRUE(cargoListIterator->isDone());
}

TEST(CrewIteration, removingFromEmptyList) {
    LinkedListOfCrew* crewList = new LinkedListOfCrew();
    EXPECT_ANY_THROW(crewList->removeCrewMember(new Crew("REMOVE-ME", "REMOVE-ME")));
}

TEST(SpacecraftCreation, typeChecking) {
    SpacecraftCreator* creator = new Falcon9Creator();
    Spacecraft* falcon9 = creator->createSpacecraft();
    EXPECT_EQ(falcon9->getType(),"falcon-9");

    creator = new FalconHeavyCreator();
    Spacecraft* falconHeavy = creator->createSpacecraft();
    EXPECT_EQ(falconHeavy->getType(),"falcon-heavy");

    creator = new SatelliteCreator();
    Spacecraft* satelite = creator->createSpacecraft();
    EXPECT_EQ(satelite->getType(),"Satelite");
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
