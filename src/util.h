/*
 * File:   util.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef UTIL_H
#define	UTIL_H

#include "config.h"
#include "gettext.h"
#include <string>
#include <sstream>
#include <iostream>
#include "util_excepcio.h"

using namespace std;

template <class T>
void from_string(T& t, const string& s, ios_base& (*f)(ios_base&)) {
    try {
        istringstream iss(s);
        if ((iss >> f >> t).fail()) {
            throw Util_excepcio(gettext("Año incorrecto: ") + s);
        }
    } catch (exception e) {
        throw Util_excepcio(e.what());
    }
}

template <class T>
string to_string(T value) {
    stringstream ss;
    string s;
    ss << value;
    s = ss.str();
    return s;
}

#endif	/* UTIL_H */

