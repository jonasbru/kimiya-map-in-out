/*
 * File:   Part.cpp
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */

#include "Part.h"

kmio::Part::Part() {
}

kmio::Part::Part(const kmio::Part& orig) {
}

kmio::Part::~Part() {
    for(int i = 0; i < this->levels.size(); i++)
        delete this->levels[i];
}

int kmio::Part::getNumber(){
    return this->number;
}

void kmio::Part::setNumber(int number){
    this->number = number;
}

kmio::Level* kmio::Part::getLevel(int i){
    return this->levels[i];
}

void kmio::Part::addLevel(kmio::Level *level){
    this->levels.push_back(level);
}

kmio::Level* kmio::Part::removeLevel(kmio::Level *level){
    kmio::Level* res = NULL;

    std::vector<kmio::Level*>::iterator it = this->levels.begin();

    while(it != this->levels.end() && (*it) != level)
        it++;

    res = *it;

    this->levels.erase(it);

    return res;
}

int kmio::Part::getLevelsNumber(){
    return this->levels.size();
}