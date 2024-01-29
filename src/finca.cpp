/*
 * File:   finca.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "finca.h"

Finca::Finca() {
}

Finca::Finca(string& str) {
    vector<string> parametres = split(str, ';');
    from_string<unsigned long>(id, parametres[0], dec);

    vector<string> parametres_participacions = split(parametres[1], '&');
    for (unsigned int i = 0; i < parametres_participacions.size(); i++) {
        Participacio p(parametres_participacions[i]);
        llista_participacions.inserirFi(p);
    }
}

Finca::~Finca() {
}

void Finca::operator=(Finca& f) {
    id = f.id;
    llista_participacions = f.llista_participacions;
}

bool Finca::operator<(Finca& f) {
    return id < f.id;
}

unsigned long Finca::get_id_finca() {
    return id;
}

ostream& operator<<(ostream& s, Finca& f){
    s << f.id << "; " << f.llista_participacions << endl;
    return s;
}
