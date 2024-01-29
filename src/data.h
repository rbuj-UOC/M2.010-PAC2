/*
 * File:   data.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef DATA_H
#define	DATA_H

#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
#include <vector>

// Declaracions forward
#include "util_excepcio.h"
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);
template <class T> void from_string(T& t, const string& s, ios_base& (*f)(ios_base&));
template <class T> string to_string(T value);

using namespace std;

class Data {
    unsigned int dia;
    unsigned int mes;
    unsigned int any;
public:
    Data();
    Data(const Data& orig);
    Data(unsigned int, unsigned int, unsigned int);
    Data(string&);
    virtual ~Data();
    void operator=(Data&);
    bool operator<(Data&);
    friend ostream& operator<<(ostream&, Data&);
private:

};

#endif	/* DATA_H */

