/*
 * File:   util_excepcio.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef UTIL_EXCEPCIO_H
#define	UTIL_EXCEPCIO_H

#include <string>
#include <exception>

using namespace std;

class Util_excepcio : public exception {
private:
    string msg_;
public:

    Util_excepcio(string msg)
    : msg_(msg) {
    }

    virtual ~Util_excepcio() throw () {
    }

    virtual const char* what() const throw () {
        return msg_.c_str();
    }
};

#endif	/* UTIL_EXCEPCIO_H */

