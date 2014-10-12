/*
 * File:   Level.cpp
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */


#include "Level.h"

kmio::Level::Level() {
}

kmio::Level::Level(const kmio::Level& orig) {
}

kmio::Level::~Level() {
    for(int i = 0; i < this->layers.size(); i++)
        delete this->layers[i];
}

int kmio::Level::getStartZ(){
    return this->startZ;
}

void kmio::Level::setStartZ(int startZ){
    this->startZ = startZ;
}

kmio::Plan* kmio::Level::getLayer(int i){
    return this->layers[i];
}

void kmio::Level::addLayer(kmio::Plan *layer){
    this->layers.push_back(layer);
}

kmio::Plan* kmio::Level::removeLayer(kmio::Plan *layer){
    Plan* res = NULL;

    std::vector<kmio::Plan*>::iterator it = this->layers.begin();

    while(it != this->layers.end() && (*it) != layer)
        it++;

    res = *it;

    this->layers.erase(it);

    return res;
}

int kmio::Level::getLayersNumber(){
    return this->layers.size();
}
