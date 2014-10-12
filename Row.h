/*
 * File:   Row.h
 * Author: jonas
 *
 * Created on 13 novembre 2009, 23:17
 */

#ifndef _ROW_H
#define	_ROW_H

#include <string>

#include "Part.h"
#include "Map.h"

namespace kmio {

    class Map;

    class Row {
    public:
        Row();
        Row(const kmio::Row& orig);
        virtual ~Row();

        int getNumber();
        void setNumber(int number);

        kmio::Map* getParent();
        void setParent(kmio::Map *parent);

        kmio::Part* getPart(int i);
        kmio::Part* getPartByX(float X);
        kmio::Part* getPartByNumber(int number);
        void addPart(kmio::Part *part);
        kmio::Part* removePart(kmio::Part *part);
        int getPartsNumber();

    private:

        std::vector<kmio::Part*> parts;

        kmio::Map* parent;

        int number;

    };

}

#endif	/* _ROW_H */

