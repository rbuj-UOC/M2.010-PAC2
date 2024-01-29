/*
 * File:   fitxer.cpp
 * Author: robert
 *
 * Created on 22 / novembre / 2011, 10:43
 */

#include "fitxer.h"

Fitxer::Fitxer() {
}

Fitxer::Fitxer(string value)
: nom_fitxer(value) {
}

Fitxer::~Fitxer() {
}

void Fitxer::obrir_lectura() {
    in.open(nom_fitxer.c_str());
    if (!in) {
        throw Fitxer_excepcio("No es pot llegir el fitxer " + nom_fitxer);
    }
}

bool Fitxer::fi_fitxer() {
    return in.eof();
}

string Fitxer::llegir_linia() {
    string str;
    getline(in, str);
    return str;
}

void Fitxer::escriure_linia(string) {
    // @todo
}
