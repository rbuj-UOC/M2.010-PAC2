/*
 * File:   donacio.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "donacio.h"

Donacio::Donacio() {
}

Donacio::Donacio(bool p_amb_obligacions, string p_descripcio)
: amb_obligacions(p_amb_obligacions), descripcio(p_descripcio) {
}

Donacio::Donacio(string& str) {
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
    amb_obligacions = (parametres[0].compare(TYPE_DONATIONS_Y) == 0) ? true : false;

    if (amb_obligacions) {
        pos = parametres[1].find_last_not_of(' ');
        if (pos != string::npos) {
            parametres[1].erase(pos + 1);
            pos = parametres[1].find_first_not_of(' ');
            if (pos != string::npos) {
                parametres[1].erase(0, pos);
            }
        }
        descripcio = string(parametres[1]);
    }
}

Donacio::~Donacio() {
    descripcio.clear();
}

ostream& Donacio::llistat(ostream& o) {
    if (amb_obligacions) {
        //        Transmissio t = *dynamic_cast<Transmissio*> (this);
        //        t.llistat(lp);
        o << gettext("Tipo") << ": " << gettext("Con obligaciones") << " (" << descripcio << ")";
    } else {
        //        Transmissio t = *dynamic_cast<Transmissio*> (this);
        //        t.llistat(lp);
        o << gettext("Tipo") << ": " << gettext("Simple");
    }
    return o;
}

ostream& operator<<(ostream& s, Donacio& d) {
    if (d.amb_obligacions) {
        s << "+" << TYPE_DONATIONS_Y << " " << d.descripcio << endl;
    } else {
        s << TYPE_DONATIONS_N << endl;
    }
    return s;
}
