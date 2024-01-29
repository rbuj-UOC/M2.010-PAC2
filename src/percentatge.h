/*
 * File:   percentatge.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef PERCENTATGE_H
#define	PERCENTATGE_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include "fraccio.h"

using namespace std;

class Percentatge {
    unsigned long part_entera;
    unsigned long decimals;
public:
    Percentatge();
    Percentatge(Percentatge&);
    Percentatge(Fraccio&);
    virtual ~Percentatge();
    void operator+=(Percentatge&);
    void operator=(Percentatge&);
    friend ostream& operator<<(ostream&, Percentatge&);
private:

};

#endif	/* PERCENTATGE_H */

