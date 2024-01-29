/*
 * File:   fitxer_excepcio.h
 * Author: robert
 *
 * Created on 23 / novembre / 2011, 21:48
 */

#ifndef FITXER_EXCEPCIO_H
#define	FITXER_EXCEPCIO_H

#include <string>
#include <exception>

using namespace std;

class Fitxer_excepcio : public exception {
private:
    string msg_;
public:

    Fitxer_excepcio(string msg)
    : msg_(msg) {
    }

    virtual ~Fitxer_excepcio() throw () {
    }

    virtual const char* what() const throw () {
        return msg_.c_str();
    }
};

#endif	/* FITXER_EXCEPCIO_H */

