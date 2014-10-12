/*
 * File:   Map.cpp
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */

#include <sstream>
#include <vector>
#include <math.h>

#include "Map.h"

kmio::Map::Map() {
}

kmio::Map::Map(const Map& orig) {
}

kmio::Map::~Map() {
    for(int i = 0; i < this->rows.size(); i++)
        delete this->rows[i];
}

void kmio::Map::setProperty(std::string key, std::string value){
    this->properties[key] = value;
}

std::string kmio::Map::getProperty(std::string key ) {
    return this->properties[key];
}

std::pair<std::string, std::string> kmio::Map::getProperty(int i){
    std::pair<std::string, std::string> res;

    std::map<std::string, std::string>::iterator it =  this->properties.begin();

    int j = 0;

    while(it != this->properties.end() && j != i)
        it++;

    res = *it;

    return res;
}

int kmio::Map::PropertyCount(){
    return this->properties.size();
}


kmio::Row* kmio::Map::getRow(int i){
    return this->rows[i];
}

kmio::Row* kmio::Map::getRowByY(float Y){
    std::stringstream ss(this->getProperty("row_height"));
    float w;
    ss >> w;
    return this->getRowByNumber(fmod(Y, w));
}

kmio::Row* kmio::Map::getRowByNumber(int number){
    kmio::Row *r = NULL;

    for (int i = 0; i < this->rows.size() && !r; i++) {
        if(this->rows[i]->getNumber() == number )
             r = this->rows[i];
    }

    return r;
}

void kmio::Map::addRow(kmio::Row *row){
    this->rows.push_back(row);
    row->setParent(this);
}

kmio::Row* kmio::Map::removeRow(kmio::Row *row){
    Row* res = NULL;

    std::vector<Row*>::iterator it = this->rows.begin();

    while(it != this->rows.end() && (*it) != row)
        it++;

    res = *it;

    this->rows.erase(it);

    return res;
}

int kmio::Map::getRowsNumber(){
    return this->rows.size();
}