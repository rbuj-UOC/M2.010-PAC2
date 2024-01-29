/*
 * File:   compraventa.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "compraventa.h"

Compraventa::Compraventa() {
}

Compraventa::Compraventa(float p_preu, string p_mode_pagament)
: preu(p_preu), mode_pagament(p_mode_pagament) {
}

Compraventa::Compraventa(string& str) {
    str.erase(str.begin());
    vector<string> parametres = split(str, ';');
    std::istringstream ss(parametres[0]);
    ss >> preu;

    string::size_type pos = parametres[1].find_last_not_of(' ');
    if (pos != string::npos) {
        parametres[1].erase(pos + 1);
        pos = parametres[1].find_first_not_of(' ');
        if (pos != string::npos) {
            parametres[1].erase(0, pos);
        }
    }
    mode_pagament = string(parametres[1]);
}

Compraventa::~Compraventa() {
    mode_pagament.clear();
}

ostream& Compraventa::llistat(ostream& o) {
//    Transmissio t = *dynamic_cast<Transmissio*> (this);
//    t.llistat(lp);
    o << gettext("Precio") << ": " << preu << " EUR (" << mode_pagament << ")";
    return o;
}

ostream& operator<<(ostream& s, Compraventa& c) {
    s << c.preu << "; " << c.mode_pagament << endl;
    return s;
}
