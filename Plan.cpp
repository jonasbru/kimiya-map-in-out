/*
 * File:   Layer.cpp
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:03
 */

#include "Plan.h"

kmio::Plan::Plan() {

}

kmio::Plan::Plan(const kmio::Plan& orig) {
}

kmio::Plan::~Plan() {
    for(int i = 0; i < this->tiles.size(); i++)
        delete this->tiles[i];
}

int kmio::Plan::getStartZ(){
    return this->startZ;
}

void kmio::Plan::setStartZ(int startZ){
    this->startZ = startZ;
}

kmio::Tile* kmio::Plan::getTile(int i){
    return this->tiles[i];
}

void kmio::Plan::addTile(kmio::Tile *tile){
    this->tiles.push_back(tile);
}

kmio::Tile* kmio::Plan::removeTile(kmio::Tile *tile){
    kmio::Tile* res = NULL;

    std::vector<kmio::Tile*>::iterator it = this->tiles.begin();

    while(it != this->tiles.end() && (*it) != tile)
        it++;

    res = *it;

    this->tiles.erase(it);

    return res;
}

int kmio::Plan::getTilesNumber(){
    return this->tiles.size();
}
