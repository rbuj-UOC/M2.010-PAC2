/*
 * File:   transmissio_node.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef TRANSMISSIO_NODE_H
#define	TRANSMISSIO_NODE_H

#include <string>
#include "data.h"
#include "transmissio.h"
#include "herencia.h"
#include "compraventa.h"
#include "donacio.h"
#include "itellis_transmissions.h"

using namespace std;

class Transmissio_node {
    unsigned long id;
    Data data;
    string motiu;
public:
    LlistaTransmissions dades_transmissio;
    Transmissio_node();
    Transmissio_node(string&);
    Transmissio_node(unsigned long, string, string);
    virtual ~Transmissio_node();
    bool operator<(Transmissio_node&);
    bool operator!=(Transmissio_node& nt);
    string get_motiu();
    int get_id_antic_propietari();
    Data& get_data_transmissio();
    friend ostream& operator<<(ostream&, Transmissio_node&);
private:

};

#endif	/* TRANSMISSIO_NODE_H */

