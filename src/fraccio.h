/*
 * File:   fraccio.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef FRACCIO_H
#define	FRACCIO_H

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Declaracions forward
#include "util_excepcio.h"
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
template <class T> void from_string(T& t, const string& s, ios_base& (*f)(ios_base&));
template <class T> string to_string(T value);

class Fraccio {
    unsigned long numerador;
    unsigned long denominador;
public:
    // Constructors i constructor copia.
    Fraccio();
    Fraccio(unsigned long, unsigned long);
    Fraccio(const Fraccio&);
    Fraccio(string);

    // Destructor
    virtual ~Fraccio();

    // Assignacio
    void operator=(Fraccio&);

    // Operacions aritmètiques
    void operator+(Fraccio&);
    void operator*(Fraccio&);

    // Assignacio i operació aritmètica
    void operator+=(Fraccio&);
    void operator*=(Fraccio&);

    // Utilitats
    void simplifica();
    bool unitat();
    float percentatge();
    friend ostream& operator<<(ostream&, Fraccio&);
};

#endif	/* FRACCIO_H */

