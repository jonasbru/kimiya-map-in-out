/*
 * File:   Part.h
 * Author: jonas
 *
 * Created on 7 novembre 2009, 15:02
 */

#ifndef _PART_H
#define	_PART_H

#include "Level.h"

namespace kmio {

    class Part {
    public:

        Part();
        Part(const kmio::Part& orig);
        virtual ~Part();

        int getNumber();
        void setNumber(int number);

        kmio::Level* getLevel(int i);
        void addLevel(kmio::Level *level);
        kmio::Level* removeLevel(kmio::Level *level);
        int getLevelsNumber();

    private:

        float number;

        std::vector<kmio::Level*> levels;

    };

}

#endif	/* _PART_H */

