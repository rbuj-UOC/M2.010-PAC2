/*
 * File:   fitxer_transmissions.cpp
 * Author: robert
 *
 * Created on 2 / desembre / 2011, 13:13
 */

#include "fitxer_transmissions.h"

Fitxer_transmissions::Fitxer_transmissions() {
}

Fitxer_transmissions::Fitxer_transmissions(string value)
: Fitxer(value), llegint_propietaris(false), llegint_transmissions(false) {
}

Fitxer_transmissions::~Fitxer_transmissions() {
}

void Fitxer_transmissions::llegir_inici() {
    string linia;
    while (!fi_fitxer() && estat_indefinit()) {
        linia = llegir_linia();

        if (linia.length() > 0) {
            if (!es_comentari(linia)) {
                llegint_propietaris = linia.compare(DELIMITADOR_NOUS_PROPIETARIS) == 0;
                llegint_transmissions = linia.compare(DELIMITADOR_TRANSMISSIONS) == 0;
            }
        }
    }
}

bool Fitxer_transmissions::llegir_propietari(Propietari& p) {
    bool resposta = false;
    string str = llegir_linia();
    if (str.length() > 0) {
        if (!es_comentari(str)) {
            if (str.compare(DELIMITADOR_TRANSMISSIONS) == 0) {
                llegint_propietaris = false;
                llegint_transmissions = true;
            } else {
                Propietari p_aux(str);
                p = p_aux;
                resposta = true;
            }
        }
    }
    return resposta;
}

bool Fitxer_transmissions::es_comentari(string str) {
    return str.at(0) == '.';
}

bool Fitxer_transmissions::estat_indefinit() {
    return (llegint_propietaris == llegint_transmissions);
}

bool Fitxer_transmissions::estat_propietaris() {
    return llegint_propietaris;
}

bool Fitxer_transmissions::estat_transmissions() {
    return llegint_transmissions;
}
