/*
 * File:   MapLoader.cpp
 * Author: arnaudboeglin
 *
 * Created on August 5, 2009, 8:22 PM
 */

#include "MapLoader.h"

#include <sstream>
#include <iostream>

kmio::MapLoader::MapLoader(std::string mapFile) {
    this->mapFile = mapFile;
    this->document.LoadFile(this->mapFile.c_str());
    //    this->loadHeader();
}

kmio::MapLoader::MapLoader() {
}

kmio::MapLoader::MapLoader(const kmio::MapLoader& orig) {
}

kmio::MapLoader::~MapLoader() {
}

TiXmlDocument kmio::MapLoader::getDocument() {
    return this->document;
}

void kmio::MapLoader::setDocument(TiXmlDocument t) {
    this->document = t;
}

kmio::Map* kmio::MapLoader::load(float x, float y, float w, float h) {
    kmio::Map *res = NULL;

    //TODO :

    return res;
}

kmio::Map* kmio::MapLoader::loadPartAt(float x, float y) {
    kmio::Map *res = NULL;

    //TODO :

    return res;
}

//ke::Layer* MapLoader::loadAll(){
//    ke::Layer *res = new ke::Layer();
//    ke::Sprite *spTile = NULL;
//    std::istringstream iss;
//    std::string path;
//    float x = 0;
//    float y = 0;
//    float z = 0;
//
//
//    TiXmlElement *root = this->document.RootElement();
//
//    TiXmlElement *levels = root->FirstChildElement("levels")->ToElement();
//    TiXmlElement *level = NULL;
//
//    while(level = levels->IterateChildren("level", level)->ToElement()){
//        iss.str(std::string(level->Attribute("startZ")));
//        iss >> z;
//
//        ke::Layer *currentLevel = new ke::Layer();
//        currentLevel->setZIndex(z);
//        res->add(currentLevel);
//
//        TiXmlElement *layers = level->FirstChildElement("layers")->ToElement();
//        TiXmlElement *layer = NULL;
//
//        while(layer = layers->IterateChildren("layer", layer)->ToElement()){
//            iss.str(std::string(layer->Attribute("startZ")));
//            iss >> z;
//
//            ke::Layer *currentLayer = new ke::Layer();
//            currentLayer->setZIndex(z);
//            currentLevel->add(currentLayer);
//
//            TiXmlElement *part = NULL;
//
//            while(part = layer->IterateChildren("part", layer)->ToElement()){
//                TiXmlElement *tiles = part->FirstChildElement("layers")->ToElement();
//                TiXmlElement *tile = NULL;
//
//                while(tile = tiles->IterateChildren("tile", tile)->ToElement()){
//                    path = tile->Attribute("path");
//                    iss.str(std::string(tile->Attribute("x")));
//                    iss >> x;
//                    iss.str(std::string(tile->Attribute("y")));
//                    iss >> y;
//                    iss.str(std::string(tile->Attribute("z")));
//                    iss >> z;
//
//                    spTile = new ke::Sprite(path);
//                    spTile->setPosition(x, y);
//                    spTile->setZIndex(z);
//                    currentLayer->add(spTile);
//                }
//            }
//        }
//    }
//
//    return res;
//}

kmio::Map* kmio::MapLoader::loadAll() {
    kmio::Map *res = new kmio::Map();
    kmio::Tile *currentTile = NULL;

    std::string s;

    std::string p1;
    std::string p2;


    TiXmlElement *root = this->document.RootElement();

    //---------- Map properties gestion ----------------------------------------------------------------------------

    TiXmlElement *map_properties = root->FirstChildElement("map_properties")->ToElement();
    TiXmlNode *property = NULL;

    while (property = map_properties->IterateChildren("property", property)) {
        p1 = std::string(property->ToElement()->Attribute("name"));

        p2 = std::string(property->ToElement()->Attribute("value"));

        res->setProperty(p1, p2);
    }


    //---------- Rows gestion --------------------------------------------------------------------------------------

    TiXmlElement *rows = root->FirstChildElement("rows")->ToElement();
    TiXmlNode *row = NULL;

    while (row = rows->IterateChildren("row", row)) {
        kmio::Row *currentRow = new kmio::Row();

        s = row->ToElement()->Attribute("number");
        currentRow->setNumber(atoi(s.c_str()));

        res->addRow(currentRow);

        //---------- Parts gestion --------------------------------------------------------------------------------------

        TiXmlElement *parts = row->FirstChildElement("parts")->ToElement();
        TiXmlNode *part = NULL;

        while (part = parts->IterateChildren("part", part)) {
            kmio::Part *currentPart = new kmio::Part();

            s = part->ToElement()->Attribute("number");
            currentPart->setNumber(atoi(s.c_str()));

            currentRow->addPart(currentPart);

            //---------- Levels gestion ----------------------------------------------------------------------------------

            TiXmlElement *levels = part->FirstChildElement("levels")->ToElement();
            TiXmlNode *level = NULL;

            while (level = levels->IterateChildren("level", level)) {
                kmio::Level *currentLevel = new kmio::Level;

                s = level->ToElement()->Attribute("startZ");
                currentLevel->setStartZ(atoi(s.c_str()));

                currentPart->addLevel(currentLevel);

                //---------- Layers gestion ------------------------------------------------------------------------------

                TiXmlElement *layers = level->FirstChildElement("layers")->ToElement();
                TiXmlNode *layer = NULL;

                while (layer = layers->IterateChildren("layer", layer)) {
                    kmio::Plan *currentLayer = new kmio::Plan;

                    s = layer->ToElement()->Attribute("startZ");
                    currentLayer->setStartZ(atoi(s.c_str()));

                    currentLevel->addLayer(currentLayer);

                    //---------- Tiles gestion ---------------------------------------------------------------------------

                    TiXmlElement *tiles = layer->FirstChildElement("tiles")->ToElement();
                    TiXmlNode *tile = NULL;

                    while (tile = tiles->IterateChildren("tile", tile)) {
                        currentTile = new kmio::Tile();
                        
                        s = tile->ToElement()->Attribute("path");
                        currentTile->setPath(s);

                        s = tile->ToElement()->Attribute("x");
                        currentTile->setX(atoi(s.c_str()));

                        s = tile->ToElement()->Attribute("y");
                        currentTile->setY(atoi(s.c_str()));

                        s = tile->ToElement()->Attribute("z");
                        currentTile->setZ(atoi(s.c_str()));

                        s = tile->ToElement()->Attribute("w");
                        currentTile->setW(atoi(s.c_str()));

                        s = tile->ToElement()->Attribute("h");
                        currentTile->setH(atoi(s.c_str()));

                        currentLayer->addTile(currentTile);
                    }
                }
            }
        }
    }
    return res;
}

inline void kmio::MapLoader::loadHeader() {
    TiXmlElement *root = this->document.RootElement();

    TiXmlElement *map_properties = root->FirstChildElement("map_properties")->ToElement();
    TiXmlElement *prop = NULL;

    while (prop = map_properties->IterateChildren(prop)->ToElement()) {
        std::istringstream iss(std::string(prop->Attribute("value")));

        if (std::string(prop->Attribute("name")) == "part_width") {
            iss >> this->partWidth;
        } else if (std::string(prop->Attribute("name")) == "part_height") {
            iss >> this->partHeight;
        } else if (std::string(prop->Attribute("name")) == "map_width") {
            iss >> this->mapWidth;
        } else if (std::string(prop->Attribute("name")) == "map_height") {
            iss >> this->mapHeight;
        } else {
            //ERROR :
        }
    }
}
