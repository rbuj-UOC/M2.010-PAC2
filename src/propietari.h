/*
 * File:   propietari.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef PROPIETARI_H
#define	PROPIETARI_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Declaracions forward
#include "util_excepcio.h"
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
template <class T> void from_string(T& t, const string& s, ios_base& (*f)(ios_base&));
template <class T> string to_string(T value);

class Propietari {
    unsigned long id;
    string nom;
    string email;
public:
    Propietari();
    Propietari(const string&);
    virtual ~Propietari();
    bool operator<(Propietari&);
    void operator=(Propietari&);
    bool operator==(Propietari&);
    unsigned long get_id();
    string get_nom();
    string get_email();
    friend ostream& operator<<(ostream&, Propietari&);
private:

};

#endif	/* PROPIETARI_H */

