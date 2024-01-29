/*
 * File:   comunitat.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "comunitat.h"

Comunitat::Comunitat() {
}

Comunitat::Comunitat(Propietari& p)
: propietari(p) {
}

Comunitat::Comunitat(Propietari& p, Fraccio& f)
: propietari(p), fraccio(f) {
}

Comunitat::Comunitat(Propietari& p, Fraccio& f, unsigned long& num)
: propietari(p), fraccio(f), finques(num) {
}

Comunitat::Comunitat(Propietari& p, Fraccio& f, unsigned long& num, Percentatge& per)
: propietari(p), fraccio(f), finques(num), percentatge(per) {
}

Comunitat::~Comunitat() {
}

ostream& operator<<(ostream& s, Comunitat& c) {
    s <<
            right << setw(5) << c.propietari.get_id() << "   " <<
            left << setw(27) << c.propietari.get_nom() <<
            left << setw(25) << c.propietari.get_email() <<
            left << setw(3) << c.finques << "    " <<
            left << c.fraccio << " " <<
            left << "(" << c.percentatge << ")" <<endl;
    return s;
}