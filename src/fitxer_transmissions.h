/*
 * File:   fitxer_transmissions.h
 * Author: robert
 *
 * Created on 2 / desembre / 2011, 13:13
 */

#ifndef FITXER_TRANSMISSIONS_H
#define	FITXER_TRANSMISSIONS_H

#include "fitxer.h"
#include "constants.h"
#include "propietari.h"
#include "transmissio.h"

class Fitxer_transmissions : public Fitxer {
    bool llegint_propietaris;
    bool llegint_transmissions;
public:
    Fitxer_transmissions();
    Fitxer_transmissions(string);
    virtual ~Fitxer_transmissions();

    void llegir_inici();
    bool llegir_propietari(Propietari&);
    bool es_comentari(string);

    bool estat_indefinit();
    bool estat_propietaris();
    bool estat_transmissions();
private:

};

#endif	/* FITXER_TRANSMISSIONS_H */

