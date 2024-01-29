/*
 * File:   transmissio.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "transmissio.h"

Transmissio::Transmissio() {
}

Transmissio::Transmissio(Transmissio& orig) {
    llista_finques = orig.llista_finques;
}

Transmissio::Transmissio(Llista<Finca>& l){
    llista_finques = l;
}

Transmissio::~Transmissio() {
}

void Transmissio::inserirFinca(string& str){
    Finca finca(str);
    llista_finques.inserirFi(finca);
}

ostream& Transmissio::llistat(ostream& o) {
    o << 0;
    return o;
}

ostream& operator<<(ostream& s, Transmissio& t) {
    s << t.llista_finques;
    return s;
}
