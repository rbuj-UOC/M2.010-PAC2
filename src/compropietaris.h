/*
 * File:   compropietaris.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef COMPROPIETARIS_H
#define	COMPROPIETARIS_H

#include <string>
#include "config.h"
#include "gettext.h"
#include "constants.h"
#include "util.h"
#include "percentatge.h"
#include "propietari.h"
#include "propietat.h"
#include "transmissio.h"
#include "transmissio_node.h"
#include "comunitat.h"
#include "fitxer_propietats.h"
#include "fitxer_transmissions.h"
#include "itellis.h"
#include "itellis_transmissions.h"

using namespace std;

class Compropietaris {
    Llista<Propietari> llista_propietaris;
    Llista<Propietat> llista_propietats;
    Llista<Propietari> llista_nous_propietaris;
    Llista<Transmissio_node> llista_transmissions;
    unsigned long any;
public:

    class eCompropietaris {
    };
    Compropietaris();
    Compropietaris(unsigned long);
    virtual ~Compropietaris();

    void llegir_fitxer_propietats();
    void llegir_fitxer_transmissions();
    void verificar_participacions();
    void afegir_nous_propietaris();
    void aplicar_llista_transmissions();
    void treure_propietaris_sense_propietats();
    void escriure_nou_fitxer_propietats();
    void escriure_fitxer_participacions_globals();
    void llistat_transmissions();

    friend ostream& operator<<(ostream&, Compropietaris&);
};


#endif	/* COMPROPIETARIS_H */

