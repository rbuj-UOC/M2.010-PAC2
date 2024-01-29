/*
 * File:   propietari.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "propietari.h"

Propietari::Propietari() {
}

Propietari::Propietari(const string& str) {
    vector<string> parametres = split(str, ';');
    from_string<unsigned long>(id, parametres[0], dec);

    string::size_type pos = parametres[1].find_last_not_of(' ');
    if (pos != string::npos) {
        parametres[1].erase(pos + 1);
        pos = parametres[1].find_first_not_of(' ');
        if (pos != string::npos) {
            parametres[1].erase(0, pos);
        }
    }
    nom = string(parametres[1]);

    pos = parametres[2].find_last_not_of(' ');
    if (pos != string::npos) {
        parametres[2].erase(pos + 1);
        pos = parametres[2].find_first_not_of(' ');
        if (pos != string::npos) {
            parametres[2].erase(0, pos);
        }
    }
    email = string(parametres[2]);
}

Propietari::~Propietari() {
    nom.clear();
    email.clear();
}

bool Propietari::operator<(Propietari& p) {
    return id < p.id;
}

bool Propietari::operator==(Propietari& p) {
    return id == p.id;
}

void Propietari::operator=(Propietari& p) {
    id = p.id;
    nom = p.nom;
    email = p.email;
}

unsigned long Propietari::get_id() {
    return id;
}

string Propietari::get_nom() {
    return nom;
}

string Propietari::get_email() {
    return email;
}

ostream& operator<<(ostream& s, Propietari& p) {
    s << p.id << "; " << p.nom << "; " << p.email << endl;
    return s;
}
