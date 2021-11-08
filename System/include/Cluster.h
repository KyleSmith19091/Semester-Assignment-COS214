/****************************************************************************************************
 *  @file Cluster.h 
 *  @brief The header file for the Cluster class.
 ***************************************************************************************************/

#ifndef CLUSTER_H 
#define CLUSTER_H

/****************************************************************************************************
 *  @class Cluster
 *  @brief "Container for starlink satelites"
 ***************************************************************************************************/

#include "Satelite.h"
#include "Falcon.h"

using namespace std;

class Cluster {
    private:
        Satelite sateliteList[60];
        Falcon* falcon9;

    public:
        /**
         *  @fn Cluster()
         *  @brief        The constructor for the class.
         *  @param[in]    Satelite*     Satelite list
         *  @param[in]    Falcon* Falcon carrying satelite
         */
        Cluster(Satelite*, Falcon*);

        /**
         *  @fn ~Cluster()
         *  @brief The destructor for the class.
         */
        ~Cluster();
};	
#endif
