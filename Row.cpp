/*
 * File:   Row.cpp
 * Author: jonas
 *
 * Created on 13 novembre 2009, 23:17
 */

#include <sstream>
#include <math.h>
#include <vector>

#include "Row.h"
#include "Map.h"

kmio::Row::Row() {
}

kmio::Row::Row(const kmio::Row& orig) {
}

kmio::Row::~Row() {
}

int kmio::Row::getNumber(){
    return this->number;
}

void kmio::Row::setNumber(int number){
    this->number = number;
}

kmio::Map* kmio::Row::getParent(){
    return this->parent;
}

void kmio::Row::setParent(kmio::Map *parent){
    this->parent = parent;
}

kmio::Part* kmio::Row::getPart(int i){
    return this->parts[i];
}

kmio::Part* kmio::Row::getPartByX(float X){
    float w;
    std::istringstream iss;
    iss.str(this->parent->getProperty("part_width"));
    iss >> w;

    return this->getPartByNumber(fmod(X, w));
}

kmio::Part* kmio::Row::getPartByNumber(int number){
    kmio::Part *p = NULL;

    for (int i = 0; i < this->parts.size() && !p; i++) {
        if(this->parts[i]->getNumber() == number )
             p = this->parts[i];
    }

    return p;
}

void kmio::Row::addPart(kmio::Part *part){
    this->parts.push_back(part);
}

//void Row::replacePart(Part *part, int index){
//    // Be carefull, this line can add a Part at the index, and not replace the old index part
//    std::vector<Part>::iterator it = this->parts.begin();
//
//    while(it != this->parts.end() && (*it) != part)
//        it++;
//
//    this->parts.replace(it);
//}

kmio::Part* kmio::Row::removePart(kmio::Part *part){
    Part* res = NULL;

    std::vector<kmio::Part*>::iterator it = this->parts.begin();

    while(it != this->parts.end() && (*it) != part)
        it++;

    res = *it;

    this->parts.erase(it);

    return res;
}

int kmio::Row::getPartsNumber(){
    return this->parts.size();
}