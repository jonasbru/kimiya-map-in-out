/* 
 * File:   MapWriter.h
 * Author: jonas
 *
 * Created on 24 novembre 2009, 19:09
 */

#ifndef _MAPWRITER_H
#define	_MAPWRITER_H

#include <string>
#include <tinyxml.h>

#include "Map.h"

namespace kmio {

    class MapWriter {
    public:

        MapWriter();
        MapWriter(std::string filePath);
        MapWriter(const MapWriter& orig);
        virtual ~MapWriter();

        std::string getFilePath();
        void setFilePath(std::string filepath);

        void save(Map *map);

    private:

        std::string mapFile;

    };
}

#endif	/* _MAPWRITER_H */

