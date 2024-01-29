/*
 * File:   herencia.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "herencia.h"

Herencia::Herencia() {
}

Herencia::Herencia(string p_parentesc, Data p_data_acceptacio)
: parentesc(p_parentesc), data_acceptacio(p_data_acceptacio) {
}

Herencia::Herencia(string& str) {
    str.erase(str.begin());
    vector<string> parametres = split(str, ';');

    string::size_type pos = parametres[0].find_last_not_of(' ');
    if (pos != string::npos) {
        parametres[0].erase(pos + 1);
        pos = parametres[0].find_first_not_of(' ');
        if (pos != string::npos) {
            parametres[0].erase(0, pos);
        }
    }
    parentesc = string(parametres[0]);

    Data data_aux(parametres[1]);
    data_acceptacio = data_aux;
}

Herencia::~Herencia() {
    parentesc.clear();
}

ostream& Herencia::llistat(ostream& o) {
    //    Transmissio t = *dynamic_cast<Transmissio*> (this);
    o << gettext("Parentesco") << ": " << parentesc << " (" <<
            gettext("F.Ac") << ": " << data_acceptacio << ")";
    return o;
}

ostream& operator<<(ostream& s, Herencia& h) {
    s << "+" << h.parentesc << "; " << h.data_acceptacio << endl;
    return s;
}
