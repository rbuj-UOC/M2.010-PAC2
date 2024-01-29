/*
 * File:   itellis_transmissions.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef ITELLIS_TRANSMISSIONS_H
#define	ITELLIS_TRANSMISSIONS_H

#include "llista_transmissions.h"

using namespace std;

class IteradorLlistaTransmissions {
    LlistaTransmissions* ref;
    NodeTransmissio* ed; // ed apunta al node anterior del que es refereix l'iterador.
public:
    friend class LlistaTransmissions;
    IteradorLlistaTransmissions();
    IteradorLlistaTransmissions(LlistaTransmissions&);
    virtual ~IteradorLlistaTransmissions();
    void situarInici();
    void situarFinal();
    bool fi();
    bool inici();
    IteradorLlistaTransmissions& operator++();
    IteradorLlistaTransmissions& operator++(int i);
    IteradorLlistaTransmissions& operator--();
    IteradorLlistaTransmissions& operator--(int i);
    Transmissio* operator*();
    Llista<Finca>& operator&();
    void assigna(Llista<Finca>&);
    void operator=(IteradorLlistaTransmissions& it2);
private:

};

#endif	/* ITELLIS_TRANSMISSIONS_H */

