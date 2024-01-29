/*
 * File:   fitxer_propietatats.cpp
 * Author: robert
 *
 * Created on 22 / novembre / 2011, 13:53
 */

#include "fitxer_propietats.h"

Fitxer_propietats::Fitxer_propietats() {
}

Fitxer_propietats::Fitxer_propietats(string value)
: Fitxer(value), llegint_propietaris(false), llegint_propietats(false)  {
}

Fitxer_propietats::~Fitxer_propietats() {
}

void Fitxer_propietats::llegir_inici() {
    string linia;
    while (!fi_fitxer() && estat_indefinit()) {
        linia = llegir_linia();

        if (linia.length() > 0) {
            if (!es_comentari(linia)) {
                llegint_propietaris = linia.compare(DELIMITADOR_PROPIETARIS) == 0;
                llegint_propietats = linia.compare(DELIMITADOR_PROPIETATS) == 0;
            }
        }
    }
}

bool Fitxer_propietats::llegir_propietat(Propietat& p) {
    bool resposta = false;
    string str = llegir_linia();
    if (str.length() > 0) {
        if (!es_comentari(str)) {
            if (str.compare(DELIMITADOR_PROPIETARIS) == 0) {
                llegint_propietaris = true;
                llegint_propietats = false;
            } else {
                Propietat p_aux(str);
                p = p_aux;
                resposta = true;
            }
        }
    }
    return resposta;
}

bool Fitxer_propietats::llegir_propietari(Propietari& p) {
    bool resposta = false;
    string str = llegir_linia();
    if (str.length() > 0) {
        if (!es_comentari(str)) {
            if (str.compare(DELIMITADOR_PROPIETATS) == 0) {
                llegint_propietaris = false;
                llegint_propietats = true;
            } else {
                Propietari p_aux(str);
                p = p_aux;
                resposta = true;
            }
        }
    }
    return resposta;
}

bool Fitxer_propietats::estat_indefinit() {
    return (llegint_propietaris == llegint_propietats);
}

bool Fitxer_propietats::estat_propietaris() {
    return llegint_propietaris;
}

bool Fitxer_propietats::estat_propietats() {
    return llegint_propietats;
}

bool Fitxer_propietats::es_comentari(string str) {
    return str.at(0) == '.';
}