/*
 * File:   Map.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */

#ifndef _MAP_H
#define	_MAP_H

#include <string>
#include <map>

#include "Row.h"

namespace kmio {

    class Row;

    class Map {
    public:

        Map();
        Map(const Map& orig);
        virtual ~Map();

        void setProperty(std::string key, std::string value);
        std::string getProperty(std::string key);
        std::pair<std::string, std::string> getProperty(int i);
        int PropertyCount();

        kmio::Row* getRow(int i);
        kmio::Row* getRowByY(float Y);
        kmio::Row* getRowByNumber(int number);
        void addRow(kmio::Row *row);
        kmio::Row* removeRow(kmio::Row *row);
        int getRowsNumber();

    private:

        std::map<std::string, std::string> properties;
        std::vector<kmio::Row*> rows;

    };

}

#endif	/* _MAP_H */

