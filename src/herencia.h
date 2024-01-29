/*
 * File:   herencia.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef HERENCIA_H
#define	HERENCIA_H

#include "config.h"
#include "gettext.h"
#include <string>
#include <ostream>
#include <iostream>
#include "transmissio.h"
#include "data.h"

using namespace std;

class Herencia : public Transmissio {
    string parentesc;
    Data data_acceptacio;
public:
    Herencia();
    Herencia(string, Data);
    Herencia(string& str);

    virtual ~Herencia();

    virtual Transmissio* clonacio() {
        Herencia* aux;
        aux = new Herencia();
        Transmissio::copia(*aux);
        aux->data_acceptacio = data_acceptacio;
        aux->parentesc = parentesc;
        return aux;
    }

    void copia(Herencia &h) {
        Transmissio::copia(h);
        h.data_acceptacio = data_acceptacio;
        h.parentesc = parentesc;
    }

    virtual ostream& llistat(ostream&);
    friend ostream& operator<<(ostream&, Herencia&);

private:

};

#endif	/* HERENCIA_H */

