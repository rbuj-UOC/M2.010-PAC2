/*
 * File:   transmissio.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef TRANSMISSIO_H
#define	TRANSMISSIO_H

#include <string>
#include <ostream>
#include <iostream>
#include "propietari.h"
#include "finca.h"
#include "itellis.h"

using namespace std;

class Transmissio {
public:
    Llista<Finca> llista_finques;

    Transmissio();
    Transmissio(Transmissio&);
    Transmissio(Llista<Finca>&);
    Transmissio(unsigned long, string, string);
    virtual ~Transmissio();

    virtual Transmissio* clonacio() {
        Transmissio* aux;
        aux = new Transmissio(llista_finques);
        return aux;
    }

    void copia(Transmissio& t) {
        t.llista_finques = llista_finques;
    }

    void assigna(Llista<Finca>& l) {
        llista_finques = l;
    }

    void inserirFinca(string&);
    virtual ostream& llistat(ostream&);
    friend ostream& operator<<(ostream&, Transmissio&);

private:

};

#endif	/* TRANSMISSIO_H */

