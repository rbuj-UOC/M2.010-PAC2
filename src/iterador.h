/*
 * File:   iterador.h
 * Author: Robert Antoni Buj Gelonch
 *
 * CLASSE Iterador<T>
 * Implementa una classe dels objectes Iterador sobre una classe contenidor
 * qualsevol amb elements components de classe T.
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef ITERADOR_H
#define	ITERADOR_H

#include <cstdlib>

using namespace std;

template<class T>
class Iterador {
public:
    // Totes les funcion són virtuals pures.
    virtual void situarInici() = 0;
    virtual void situarFinal() = 0;
    virtual Iterador<T>& operator++() = 0;
    virtual Iterador<T>& operator++(int) = 0;
    virtual T& operator&() = 0;
    virtual T* operator*() = 0;
    virtual bool fi() = 0;
    virtual bool inici() = 0;
};

#endif	/* ITERADOR_H */

