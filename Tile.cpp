/*
 * File:   Tile.cpp
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:03
 */

#include "Tile.h"

kmio::Tile::Tile() {
}

kmio::Tile::Tile(const kmio::Tile& orig) {
}

kmio::Tile::~Tile() {
}

std::string kmio::Tile::getPath() {
    return this->path;
}

void kmio::Tile::setPath(std::string p) {
    this->path = p;
}

int kmio::Tile::getX(){
    return this->x;
}
void kmio::Tile::setX(int x){
    this->x = x;
}

int kmio::Tile::getY(){
    return this->y;
}
void kmio::Tile::setY(int y){
    this->y = y;
}

int kmio::Tile::getZ(){
    return this->z;
}
void kmio::Tile::setZ(int z){
    this->z = z;
}

int kmio::Tile::getW(){
    return this->w;
}
void kmio::Tile::setW(int w){
    this->w = w;
}

int kmio::Tile::getH(){
    return this->h;
}
void kmio::Tile::setH(int h){
    this->h = h;
}