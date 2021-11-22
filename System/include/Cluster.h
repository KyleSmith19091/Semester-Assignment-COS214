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
         *  @param[in] Falcon* The falcon used to to determine where the cluster is loaded.
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
         * @brief Generate a variable amount of satellites and populate cluster.
         * @param[in] MissionControl* The mission control used to communicate with the satellites.
         * @param[in] int The number of satellites to be generated.
         * @return void
         */
        void generateSatellites(MissionControl*,int);

        /**
         * @fn spreadOutSatellites()
         * @brief Spread out the satellites
         * @return void
         */
        void spreadOutSatellites();

        /**
         * @fn checkCollisions()
         * @brief Check the whole cluster for any collisions.
         * @return void
         */
        void checkCollisions();

        /**
         * @fn getCraft()
         * @brief Return the registered spacecraft
         * @return Falcon*
         */
        Falcon* getCraft();

        /**
         * @fn getSize()
         * @brief Return the size of cluster
         * @return int
         */
        int getSize();

    private:
        Falcon* falcon; /**< The falcon on which the satellites are loaded. */
        std::vector<Satelite*> clusterSatellites; /**< The vector containing all the satellites in the cluster. */
};

#endif  //CLUSTER_H
