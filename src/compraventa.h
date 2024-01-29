/*
 * File:   compraventa.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef COMPRAVENTA_H
#define	COMPRAVENTA_H

#include "config.h"
#include "gettext.h"
#include <string>
#include <ostream>
#include <sstream>
#include "transmissio.h"

using namespace std;

class Compraventa : public Transmissio {
    float preu;
    string mode_pagament;
public:
    Compraventa();
    Compraventa(float, string);
    Compraventa(string&);
    ~Compraventa();

    virtual Transmissio* clonacio() {
        Compraventa* aux;
        aux = new Compraventa();
        Transmissio::copia(*aux);
        aux->preu = preu;
        aux->mode_pagament = mode_pagament;
        return aux;
    }

    void copia(Compraventa &c) {
        Transmissio::copia(c);
        c.preu = preu;
        c.mode_pagament = mode_pagament;
    }

    virtual ostream& llistat(ostream&);
    friend ostream& operator<<(ostream&, Compraventa&);

private:

};

#endif	/* COMPRAVENTA_H */

