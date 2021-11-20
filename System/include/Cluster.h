/****************************************************************************************************
 *  @file ./include/Cluster.h
 *  @brief The header file for the Cluster class.
 ***************************************************************************************************/

#ifndef CLUSTER_H
#define CLUSTER_H

#include "Satelite.h"
#include "MissionControl.h"
#include "Falcon.h"

#include <vector>

/****************************************************************************************************
 *  @class Cluster
 *  @brief "Represents a cluster of satellite"
 ***************************************************************************************************/
class Cluster {
    public:
        /**
         *  @fn Cluster()
         *  @brief The constructor for the class.
         */
        Cluster(Falcon*);

        /**
         *  @fn ~Cluster()
         *  @brief The destructor for the class.
         */
        ~Cluster();

        /**
         * @fn addSatellite(Satellite*)
         * @brief Add a satellite to a cluster
         * @param[in] Satellite* Pointer to satellite that will be added to cluster
         * @return void
         */
        void addSatellite(Satelite*);

        /**
         * @fn generateSatellites()
         * @brief Generate 60 satellites and populate cluster
         * @return void
         */
        void generateSatellites(MissionControl*,int);

        /**
         * @fn spreadOutSatellites(Satellite*)
         * @brief Spread out the satellites
         * @return void
         */
        void spreadOutSatellites();

    private:
        Falcon* falcon;
        std::vector<Satelite*> clusterSatellites;
};

#endif  //CLUSTER_H
