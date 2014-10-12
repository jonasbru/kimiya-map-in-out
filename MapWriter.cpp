/* 
 * File:   MapWriter.cpp
 * Author: jonas
 * 
 * Created on 24 novembre 2009, 19:09
 */


#include "MapWriter.h"

kmio::MapWriter::MapWriter() {
}

kmio::MapWriter::MapWriter(std::string filePath) {
    this->mapFile = filePath;
}

kmio::MapWriter::MapWriter(const MapWriter& orig) {
}

kmio::MapWriter::~MapWriter() {
}

std::string kmio::MapWriter::getFilePath(){
    return this->mapFile;
}

void kmio::MapWriter::setFilePath(std::string filepath){
    this->mapFile = filepath;
}

void kmio::MapWriter::save(Map *map){

    TiXmlDocument *doc;

    TiXmlElement *root = new TiXmlElement( "map" );
    doc->LinkEndChild(root);

    //---------- Map properties gestion ----------------------------------------------------------------------------

    TiXmlElement *map_properties = new TiXmlElement("map_properties");
    root->LinkEndChild(map_properties);

    for(int i=0; i < map->PropertyCount(); i++){
        TiXmlElement *property = new TiXmlElement( "property" );
        property->SetAttribute("name", map->getProperty(i).first.c_str());
        property->SetAttribute("value", map->getProperty(i).second.c_str());
        map_properties->LinkEndChild(property);
    }

    //---------- Rows gestion --------------------------------------------------------------------------------------

    TiXmlElement *rows = new TiXmlElement( "rows" );
    root->LinkEndChild( rows );

    for(int i=0; i < map->getRowsNumber(); i++){
        TiXmlElement *row = new TiXmlElement( "row" );
        row->SetAttribute("number", map->getRow(i)->getNumber());
        rows->LinkEndChild( row );

        //---------- parts gestion --------------------------------------------------------------------------------------

        TiXmlElement *parts = new TiXmlElement( "parts" );
        row->LinkEndChild( parts );

        for(int j=0; j < map->getRow(i)->getPartsNumber(); j++){
            TiXmlElement *part = new TiXmlElement( "part" );
            part->SetAttribute("number", map->getRow(i)->getPart(j)->getNumber());
            parts->LinkEndChild( part );

            //---------- Levels gestion ----------------------------------------------------------------------------------

            TiXmlElement *levels = new TiXmlElement( "levels" );
            part->LinkEndChild( levels );

            for(int k=0; k < map->getRow(i)->getPart(j)->getLevelsNumber(); k++){
                TiXmlElement *level = new TiXmlElement( "level" );
                level->SetAttribute("startZ", map->getRow(i)->getPart(j)->getLevel(k)->getStartZ());
                levels->LinkEndChild( level );

                //---------- Layers gestion ------------------------------------------------------------------------------

                TiXmlElement *layers = new TiXmlElement( "layers" );
                level->LinkEndChild( layers );

                for(int l=0; l < map->getRow(i)->getPart(j)->getLevel(k)->getLayersNumber(); l++){
                    TiXmlElement *layer = new TiXmlElement( "layer" );
                    layer->SetAttribute("startZ", map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getStartZ());
                    layers->LinkEndChild( layer );

                    //---------- Tiles gestion ---------------------------------------------------------------------------

                    TiXmlElement *tiles = new TiXmlElement( "tiles" );
                    layer->LinkEndChild( tiles );

                    for(int m=0; m < map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTilesNumber(); m++){
                        TiXmlElement *tile = new TiXmlElement( "tile" );
                        tile->SetAttribute("x", map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getX());
                        tile->SetAttribute("y", map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getY());
                        tile->SetAttribute("z", map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getZ());
                        tile->SetAttribute("path", map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getPath().c_str());
                        tile->SetAttribute("w", map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getW());
                        tile->SetAttribute("h", map->getRow(i)->getPart(j)->getLevel(k)->getLayer(l)->getTile(m)->getH());
                        tiles->LinkEndChild( tile );
                    }
                }
            }
        }
    }
    
    doc->SaveFile( this->mapFile.c_str() );
}

