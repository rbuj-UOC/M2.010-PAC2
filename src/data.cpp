/*
 * File:   data.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "data.h"

Data::Data() {
}

Data::Data(const Data& orig) {
    dia = orig.dia;
    mes = orig.mes;
    any = orig.any;
}

Data::Data(unsigned int p_dia, unsigned int p_mes, unsigned int p_any)
: dia(p_dia), mes(p_mes), any(p_any) {
}

Data::Data(string& str) {
    unsigned long temp;
    vector<string> parametres = split(str, '-');
    from_string<unsigned long>(temp, parametres[0], dec);
    dia=temp;
    from_string<unsigned long>(temp, parametres[1], dec);
    mes=temp;
    from_string<unsigned long>(temp, parametres[2], dec);
    any=temp;
}

Data::~Data() {
}

void Data::operator=(Data& orig) {
    dia = orig.dia;
    mes = orig.mes;
    any = orig.any;
}

bool Data::operator<(Data& d) {
    return (any < d.any ? true : mes < d.mes ? true : dia < d.dia);
}

ostream& operator<<(ostream& s, Data& d) {
    s << setfill('0') << setw(2) << d.dia << "-" << setw(2) << d.mes << "-" << setw(4) << d.any << setfill(' ');
    return s;
}
