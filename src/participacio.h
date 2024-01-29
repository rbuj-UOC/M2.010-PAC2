/*
 * File:   participacions.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef PARTICIPACIONS_H
#define	PARTICIPACIONS_H

#include <iostream>
#include <string>
#include <vector>
#include "fraccio.h"

using namespace std;

// Declaracions forward
#include "util_excepcio.h"
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
template <class T> void from_string(T& t, const string& s, ios_base& (*f)(ios_base&));
template <class T> string to_string(T value);

class Participacio {
    unsigned long id;
    Fraccio f_participacio;
public:
    Participacio();
    Participacio(const string& s);
    Participacio(unsigned long&, Fraccio&);
    virtual ~Participacio();
    bool operator<(Participacio&);
    bool operator!=(unsigned long&);
    bool operator==(unsigned long&);
    void operator=(Participacio&);
    void operator+=(Fraccio&);
    Fraccio& f_participacio_parcial();
    unsigned long& id_propietari();
    friend ostream& operator<<(ostream&, Participacio&);
private:

};

#endif	/* PARTICIPACIONS_H */

