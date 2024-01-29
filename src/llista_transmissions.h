/*
 * File:   llista_transmissions.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef LLISTA_TRANSMISSIONS_H
#define	LLISTA_TRANSMISSIONS_H

#include <cstdlib>
#include <iostream>
#include "ed.h"
#include "transmissio.h"

using namespace std;

// Declaració forward de la classe IteradorLlista. No fem un #include
// doncs com IteradorLlistaTransmissions.h ja inclou a llista.h, tindrem circularitat.
class IteradorLlistaTransmissions;

// Declaració dels nodes de la llista.
class NodeTransmissio {
public:
    Transmissio* valor;
    NodeTransmissio* seg;
    NodeTransmissio* ant;
};

class LlistaTransmissions : public ED {
    NodeTransmissio* primer;
    NodeTransmissio* darrer;
    void buidar();
public:
    friend class IteradorLlistaTransmissions;

    class noMem {
    };

    // Constructor i constructor copia.
    LlistaTransmissions();
    LlistaTransmissions(LlistaTransmissions&);

    // Destructor
    ~LlistaTransmissions();

    // Assignacio
    void operator=(LlistaTransmissions&);

    // Grup inserir
    void inserirCap(Transmissio&);
    void inserir(Transmissio&, IteradorLlistaTransmissions&);
    void inserirFi(Transmissio&);

    // Grup eliminar
    void eliminarCap();
    void eliminar(IteradorLlistaTransmissions&);
    void eliminarFi();

    // Grup consultar
    Transmissio* consultarCap();
    Transmissio* consultarFi();
    Transmissio* consultar(IteradorLlistaTransmissions&);

    friend ostream& operator<<(ostream&, LlistaTransmissions&);
};

#endif	/* LLISTA_TRANSMISSIONS_H */
