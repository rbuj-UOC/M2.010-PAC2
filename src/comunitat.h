/*
 * File:   comunitat.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef COMUNITAT_H
#define	COMUNITAT_H

#include "config.h"
#include "gettext.h"
#include <string>
#include <ostream>
#include <iomanip>
#include <sstream>
#include "propietari.h"
#include "fraccio.h"
#include "percentatge.h"

using namespace std;

class Comunitat {
    Propietari propietari;
    Fraccio fraccio;
    unsigned long finques;
    Percentatge percentatge;
public:
    Comunitat();
    Comunitat(Propietari&);
    Comunitat(Propietari&, Fraccio&);
    Comunitat(Propietari&, Fraccio&, unsigned long&);
    Comunitat(Propietari&, Fraccio&, unsigned long&, Percentatge&);
    virtual ~Comunitat();

friend ostream& operator<<(ostream&, Comunitat&);

private:

};

#endif	/* COMUNITAT_H */

