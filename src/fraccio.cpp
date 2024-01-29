/*
 * File:   fraccio.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "fraccio.h"

Fraccio::Fraccio() {
}

Fraccio::Fraccio(unsigned long num, unsigned long den)
: numerador(num), denominador(den) {
}

Fraccio::Fraccio(const Fraccio& orig) {
    numerador = orig.numerador;
    denominador = orig.denominador;
}

Fraccio::Fraccio(string s) {
    int pos = s.find('/');
    if (pos == 0) {
        numerador = 1;
        denominador = 1;
    } else {
        unsigned long aux;
        from_string<unsigned long>(aux, s.substr(0, pos), dec);
        numerador = aux;
        from_string<unsigned long>(aux, s.substr(pos + 1), dec);
        denominador = aux;
    }
}

Fraccio::~Fraccio() {
}

void Fraccio::operator =(Fraccio& f) {
    numerador = f.numerador;
    denominador = f.denominador;
}

void Fraccio::operator +(Fraccio& f) {
    Fraccio aux(*this);
    numerador = (f.numerador * aux.denominador) + (f.denominador * aux.numerador);
    denominador = f.denominador * aux.denominador;
    simplifica();
}

void Fraccio::operator +=(Fraccio& f) {
    Fraccio aux(*this);
    numerador = (f.numerador * aux.denominador) + (f.denominador * aux.numerador);
    denominador = f.denominador * aux.denominador;
    simplifica();
}

void Fraccio::operator *(Fraccio& f) {
    Fraccio aux(*this);
    numerador = f.numerador * aux.numerador;
    denominador = f.denominador * aux.denominador;
    simplifica();
}

void Fraccio::operator *=(Fraccio& f) {
    Fraccio aux(*this);
    numerador = f.numerador * aux.numerador;
    denominador = f.denominador * aux.denominador;
    simplifica();
}

void Fraccio::simplifica() {
    unsigned long factors[22] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
        37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
    int i;
    if (numerador != denominador) {
        for (i = 0; i < 22; i++) {
            while (((numerador % factors[i]) == 0) &&
                    ((denominador % factors[i]) == 0)) {
                numerador = numerador / factors[i];
                denominador = denominador / factors[i];
            }
        }
    } else {
        numerador = 1;
        denominador = 1;
    }
}

bool Fraccio::unitat() {
    return (numerador == denominador);
}

float Fraccio::percentatge() {
    return float(floor((float((numerador * 10000) / denominador))) / 100);
}

ostream& operator<<(ostream& s, Fraccio& fraccio) {
    if (fraccio.numerador != fraccio.denominador) {
        s << fraccio.numerador << "/" << fraccio.denominador;
    }
    else{
        s << "1";
    }
    return s;
}
