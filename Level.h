/*
 * File:   Level.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */

#ifndef _LEVEL_H
#define	_LEVEL_H

#include <vector>

#include "Plan.h"

namespace kmio {

    class Level {
    public:

        Level();
        Level(const kmio::Level& orig);
        virtual ~Level();

        int getStartZ();
        void setStartZ(int startZ);

        kmio::Plan* getLayer(int i);
        void addLayer(kmio::Plan *layer);
        kmio::Plan* removeLayer(kmio::Plan *layer);
        int getLayersNumber();

    private:

        int startZ;

        std::vector<kmio::Plan*> layers;

    };

}
#endif	/* _LEVEL_H */

