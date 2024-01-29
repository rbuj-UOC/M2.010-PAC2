/*
 * File:   donacio.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef DONACIO_H
#define	DONACIO_H

#include "config.h"
#include "gettext.h"
#include <string>
#include <ostream>
#include <iostream>
#include "transmissio.h"
#include "constants.h"

using namespace std;

class Donacio : public Transmissio {
    bool amb_obligacions;
    string descripcio;
public:
    Donacio();
    Donacio(bool, string);
    Donacio(string&);

    virtual ~Donacio();

    virtual Transmissio* clonacio() {
        Donacio* aux;
        aux = new Donacio();
        Transmissio::copia(*aux);
        aux->amb_obligacions = amb_obligacions;
        aux->descripcio = descripcio;
        return aux;
    }

    void copia(Donacio &d) {
        Transmissio::copia(d);
        d.amb_obligacions = amb_obligacions;
        d.descripcio = descripcio;
    }

    virtual ostream& llistat(ostream&);
    friend ostream& operator<<(ostream&, Donacio&);

private:

};

#endif	/* DONACIO_H */

