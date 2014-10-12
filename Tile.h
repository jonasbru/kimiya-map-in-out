/*
 * File:   Tile.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:03
 */

#ifndef _TILE_H
#define	_TILE_H

#include <string>

namespace kmio {

    class Tile {
    public:
        Tile();
        Tile(const kmio::Tile& orig);
        virtual ~Tile();

        std::string getPath();
        void setPath(std::string p);

        int getX();
        void setX(int x);

        int getY();
        void setY(int y);

        int getZ();
        void setZ(int z);

        int getW();
        void setW(int w);

        int getH();
        void setH(int h);

    private:

        int x;
        int y;
        int z;
        std::string path;
        int w;
        int h;

    };

}

#endif	/* _TILE_H */

