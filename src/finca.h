/*
 * File:   finca.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef FINCA_H
#define	FINCA_H

#include <vector>
#include "itellis.h"
#include "participacio.h"

// Declaracions forward
#include "util_excepcio.h"
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
template <class T> void from_string(T& t, const string& s, ios_base& (*f)(ios_base&));
template <class T> string to_string(T value);

using namespace std;

class Finca {
    unsigned long id;
public:
    Llista<Participacio> llista_participacions;
    Finca();
    Finca(string&);
    virtual ~Finca();
    void operator=(Finca&);
    bool operator<(Finca&);
    unsigned long get_id_finca();
    friend ostream& operator<<(ostream&, Finca&);
private:

};

#endif	/* FINCA_H */

