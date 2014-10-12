/*
 * File:   Layer.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:03
 */

#ifndef _PLAN_H
#define	_PLAN_H

#include <vector>

#include "Tile.h"

namespace kmio {

    class Plan {
    public:

        Plan();
        Plan(const kmio::Plan& orig);
        virtual ~Plan();

        int getStartZ();
        void setStartZ(int startZ);

        kmio::Tile* getTile(int i);
        void addTile(kmio::Tile *tile);
        kmio::Tile* removeTile(kmio::Tile *tile);
        int getTilesNumber();

    private:

        int startZ;

        std::vector<kmio::Tile*> tiles;

    };

}

#endif	/* _LAYER_H */

