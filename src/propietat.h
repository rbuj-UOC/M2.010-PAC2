/*
 * File:   propietat.h
 * Author: robert
 *
 * Created on 22 / novembre / 2011, 00:47
 */

#ifndef PROPIETAT_H
#define	PROPIETAT_H

#include <iostream>
#include <string>
#include <vector>
#include "fraccio.h"
#include "participacio.h"
#include "itellis.h"

using namespace std;

// Declaracions forward
#include "util_excepcio.h"
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
template <class T> void from_string(T& t, const string& s, ios_base& (*f)(ios_base&));
template <class T> string to_string(T value);

class Propietat {
    unsigned long id;
    string nom;
    Fraccio participacio;
public:
    Llista<Participacio> llista_participacions;
    Propietat();
    Propietat(string&);
    virtual ~Propietat();
    bool operator<(Propietat&);
    void operator=(Propietat&);
    bool operator!=(unsigned long&);
    Fraccio& f_participacio_general();
    friend ostream& operator<<(ostream&, Propietat&);
private:

};

#endif	/* PROPIETAT_H */

