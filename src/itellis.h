/*
 * File:   itellis.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Classe IteradorLlista
 * Subclasse de Iterador<T>. Permet fer iteracions sobre llistes.
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef ITELLIS_H
#define	ITELLIS_H

#include <cstdlib>
#include <iostream>
#include "iterador.h"
#include "llista.h"

using namespace std;

template<class T>
class IteradorLlista : public Iterador<T> {
    Llista<T>* ref;
    Node<T>* ed; // ed apunta al node anterior del que es refereix l'iterador.

public:

    friend class Llista<T>;

    IteradorLlista(Llista<T>& l);
    void situarInici();
    void situarFinal();
    IteradorLlista<T>& operator++();
    IteradorLlista<T>& operator++(int i);
    IteradorLlista<T>& operator--();
    IteradorLlista<T>& operator--(int i);
    T& operator&();
    T* operator*();
    bool fi();
    bool inici();
    void operator=(IteradorLlista<T>& it2);
};

template<class T>
IteradorLlista<T>::IteradorLlista(Llista<T>& l) {
    ref = &l;
    ed = l.primer;
}

template<class T>
void IteradorLlista<T>::situarInici() {
    ed = ref->primer;
}

template<class T>
void IteradorLlista<T>::situarFinal() {
    ed = ref->darrer->ant;
}

template<class T>
IteradorLlista<T>& IteradorLlista<T>::operator++() // ++it
{
    IteradorLlista<T>* aux;
    ed = ed->seg;
    aux = this;
    return *aux;
}

template<class T>
IteradorLlista<T>& IteradorLlista<T>::operator++(int) // it++
{
    IteradorLlista<T>* aux;
    aux = this;
    ed = ed->seg;
    return *aux;
}

template<class T>
IteradorLlista<T>& IteradorLlista<T>::operator--() // --it
{
    IteradorLlista<T>* aux;
    ed = ed->ant;
    aux = this;
    return *aux;
}

template<class T>
IteradorLlista<T>& IteradorLlista<T>::operator--(int) // it--
{
    IteradorLlista<T>* aux;
    aux = this;
    ed = ed->ant;
    return *aux;
}

template<class T>
T& IteradorLlista<T>::operator&() {
    return ed->seg->valor;
}

template<class T>
T* IteradorLlista<T>::operator*() {
    return &(ed->seg->valor);
}

template<class T>
bool IteradorLlista<T>::fi() {
    return ed->seg->seg == NULL;
}

template<class T>
bool IteradorLlista<T>::inici() {
    return ed == ref->primer;
}

template<class T>
void IteradorLlista<T>::operator=(IteradorLlista<T>& it2) {
    ref = it2.ref;
    ed = it2.ed;
}

#endif	/* ITELLIS_H */

