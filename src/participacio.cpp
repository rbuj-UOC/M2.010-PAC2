/*
 * File:   participacions.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "participacio.h"
#include "itellis.h"

Participacio::Participacio() {
}

Participacio::Participacio(const string &s) {
    int pos = s.find(':');
    unsigned long ul_aux;
    from_string<unsigned long>(ul_aux, s.substr(0, pos), dec);
    id = ul_aux;
    Fraccio f_aux(s.substr(pos + 1));
    f_participacio = f_aux;
}

Participacio::Participacio(unsigned long& p_id, Fraccio& fraccio) {
    id = p_id;
    f_participacio = fraccio;
}

Participacio::~Participacio() {
}

bool Participacio::operator<(Participacio& p) {
    return id < p.id;
}

bool Participacio::operator!=(unsigned long& p_id) {
    return id != p_id;
}

bool Participacio::operator==(unsigned long& p_id) {
    return id == p_id;
}

void Participacio::operator=(Participacio& p) {
    id = p.id;
    f_participacio = p.f_participacio;
}

void Participacio::operator+=(Fraccio& fraccio) {
    f_participacio += fraccio;
}

Fraccio& Participacio::f_participacio_parcial() {
    return f_participacio;
}

unsigned long& Participacio::id_propietari() {
    return id;
}

ostream& operator<<(ostream& s, Participacio& p) {
    s << p.id << " : " << p.f_participacio;
    return s;
}

template <>
ostream& operator<<(ostream& s, Llista<Participacio>& l) {
    IteradorLlista<Participacio> it_llista_participacions(l);
    IteradorLlista<Participacio> it_llista_participacions_aux(l);
    it_llista_participacions.situarInici();
    it_llista_participacions_aux.situarFinal();
    it_llista_participacions_aux--;
    while (!it_llista_participacions.fi()) {
        if ((&it_llista_participacions) == (&it_llista_participacions_aux).id_propietari()) {
            s << (&it_llista_participacions);
        } else {
            s << (&it_llista_participacions) << " & ";
        }
        it_llista_participacions++;
    }
    return s;
}
