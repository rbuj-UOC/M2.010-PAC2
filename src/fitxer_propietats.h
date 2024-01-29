/*
 * File:   fitxer_propietatats.h
 * Author: robert
 *
 * Created on 22 / novembre / 2011, 13:53
 */

#ifndef FITXER_PROPIETATATS_H
#define	FITXER_PROPIETATATS_H

#include "fitxer.h"
#include "propietari.h"
#include "propietat.h"
#include "constants.h"

using namespace std;

class Fitxer_propietats : public Fitxer {
    bool llegint_propietaris;
    bool llegint_propietats;
public:
    Fitxer_propietats();
    Fitxer_propietats(string);
    virtual ~Fitxer_propietats();

    void llegir_inici();
    bool llegir_propietat(Propietat&);
    bool llegir_propietari(Propietari&);
    bool es_comentari(string);

    bool estat_indefinit();
    bool estat_propietaris();
    bool estat_propietats();
private:

};

#endif	/* FITXER_PROPIETATATS_H */

