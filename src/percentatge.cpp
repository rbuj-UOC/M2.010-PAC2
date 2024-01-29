/*
 * File:   percentatge.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "percentatge.h"

Percentatge::Percentatge()
: part_entera(0), decimals(0) {
}

Percentatge::Percentatge(Percentatge& orig){
    part_entera = orig.part_entera;
    decimals = orig.decimals;
}

Percentatge::Percentatge(Fraccio &fraccio) {
    float f_enter, f_decimal;
    float percentatge = fraccio.percentatge();
    float f_aux = modf(percentatge, &f_enter);
    percentatge = modf(f_aux * 100, &f_decimal);
    part_entera = long(f_enter);
    decimals = long(f_decimal);
}

Percentatge::~Percentatge() {
}

void Percentatge::operator+=(Percentatge& p) {
    decimals += p.decimals;
    if (decimals > 100) {
        decimals -= 100;
        part_entera++;
    }
    part_entera += p.part_entera;
}

void Percentatge::operator=(Percentatge& p) {
    decimals = p.decimals;
    part_entera = p.part_entera;
}

ostream& operator<<(ostream& s, Percentatge& p) {
    s << p.part_entera << "," << left << setw(2) << setfill('0') << p.decimals << setfill(' ');
    return s;
}
