/*
 * File:   llista.h
 * Author: Robert Antoni Buj Gelonch
 *
 * CLASSE Llista
 * Implementada en memòria dinàmica amb encadenaments dobles, els fantasmes
 * apunten, un a l'inici i l'altre al final.
 *
 * L'iterador apunta a l'anterior.
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef LLISTA_H
#define	LLISTA_H

#include <cstdlib>
#include <iostream>
#include "ed.h"

using namespace std;

// Declaració forward de la classe IteradorLlista. No fem un #include
// doncs com itellis.h ja inclou a llista.h, tindrem circularitat.
template <class T> class IteradorLlista;

// Declaració dels nodes de la llista.

template <class T> class Node {
public:
    T valor;
    Node<T>* seg;
    Node<T>* ant;
};

template <class T> class Llista;

// Declaració forward de la funció operator<< de la plantilla
template <class T> ostream& operator<<(ostream&, Llista<T>&);

// Declaració forward de la funció operator== de la plantilla
template <class T> bool operator==(Llista<T>&, Llista<T>&);

template <class T> class Llista : public ED {
    Node<T>* primer;
    Node<T>* darrer;
    void buidar();

public:

    // Definim la classe IteradorLlista<T> com a friend per a que, dins de la
    // classe IteradorLLista, poguem accedir a la part privada de la classe
    // Llista.
    friend class IteradorLlista<T>;

    // Definim l'excepció que llençarem si tenim problemes en reservar memoria
    // dinamica.

    class noMem {
    };

    // Constructor i constructor copia.
    Llista();
    Llista(Llista<T>&);

    // Destructor
    ~Llista();

    // Assignacio
    void operator=(Llista<T>&);

    // Grup inserir
    void inserirCap(T&);
    void inserir(T&, IteradorLlista<T>&);
    void inserirFi(T&);

    // Grup eliminar
    void eliminarCap();
    void eliminar(IteradorLlista<T>&);
    void eliminarFi();

    // Grup consultar
    void consultarCap(T& t);
    void consultarFi(T& t);
    void consultar(T& t, IteradorLlista<T>&);

    // friend
    friend bool operator==<T>(Llista<T>&, Llista<T>&);
    friend ostream& operator<<<T>(ostream&, Llista<T>&);

};

template <class T>
void Llista<T>::buidar() {
    // Esborra els elements de la llista i la deixa buida
    Node<T>* aux;
    while (primer->seg != darrer) {
        aux = primer->seg;
        primer->seg = primer->seg->seg;
        delete aux;
    }
    nElems = 0;
    darrer->ant = primer;
}

template <class T>
Llista<T>::Llista() {
    // Crea el node fantasma de la llista
    primer = new Node<T>;
    if (primer == NULL) throw noMem();
    primer->ant = NULL;

    darrer = new Node<T>;
    if (darrer == NULL) throw noMem();
    darrer->seg = NULL;

    darrer->ant = primer;
    primer->seg = darrer;
}

template <class T>
Llista<T>::Llista(Llista<T>& l2) {
    primer = new Node<T>;
    if (primer == NULL) throw noMem();
    primer->ant = NULL;

    darrer = new Node<T>;
    if (darrer == NULL) throw noMem();
    darrer->seg = NULL;

    // Crida a l'assignacio entre llistes, per tant, copia els elements
    // de l2 sobre la llista actual (la que estem construint).
    *(this) = l2;
}

template <class T>
Llista<T>::~Llista() {
    // Esborra tots els nodes dels que consta la llista.
    Node<T>* aux;
    while (primer->seg != darrer) {
        aux = primer;
        primer = primer->seg;
        delete aux;
    }
    delete darrer;
    delete primer;
    darrer = NULL;
    primer = NULL;
}

template <class T>
void Llista<T>::inserirCap(T& t) {
    Node<T>* aux;
    aux = new Node<T>;
    if (aux == NULL) throw noMem();
    aux->valor = t;
    aux->seg = primer->seg;
    aux->ant = primer;
    primer->seg = aux;
    aux->seg->ant = aux;
    nElems++;
}

template <class T>
void Llista<T>::inserirFi(T& t) {
    Node<T>* aux;
    aux = new Node<T>;
    if (aux == NULL) throw noMem();
    aux->valor = t;
    darrer->ant->seg = aux;
    aux->seg = darrer;
    aux->ant = darrer->ant;
    darrer->ant = aux;
    nElems++;
}

template <class T>
void Llista<T>::inserir(T& t, IteradorLlista<T>& ite) {
    Node<T>* aux;
    aux = new Node<T>;
    if (aux == NULL) throw noMem();
    aux->valor = t;
    aux->seg = ite.ed->seg;
    ite.ed->seg = aux;
    aux->ant = ite.ed;
    aux->seg->ant = aux;
    ite.ed = aux;
    nElems++;
}

template <class T>
void Llista<T>::eliminarCap() {
    Node<T>* aux;
    aux = primer->seg;
    primer->seg = aux->seg;
    aux->seg->ant = primer;
    nElems--;
    delete aux;
}

template <class T>
void Llista<T>::eliminarFi() {
    Node<T>* aux;
    aux = darrer->ant;
    aux->ant->seg = darrer;
    darrer->ant = aux->ant;
    nElems--;
    delete aux;
}

template <class T>
void Llista<T>::eliminar(IteradorLlista<T>& ite) {
    Node<T>* aux;
    aux = ite.ed->seg;
    ite.ed->seg = ite.ed->seg->seg;
    ite.ed->seg->ant = ite.ed;
    nElems--;
    delete aux;
}

template <class T>
void Llista<T>::consultarCap(T& t) {
    t = primer->seg->valor;
}

template <class T>
void Llista<T>::consultarFi(T& t) {
    t = darrer->ant->valor;
}

template <class T>
void Llista<T>::consultar(T& t, IteradorLlista<T>& ite) {
    t = ite.ed->seg->valor;
}

template <class T>
void Llista<T>::operator=(Llista<T>& l2) {
    IteradorLlista<T> ite1(*this), ite2(l2);
    T t;
    buidar();
    ite1.situarInici();
    ite2.situarInici();
    while (!ite2.fi()) {
        t = &ite2;
        inserir(t, ite1);
        ite2++;
    }
}

template <class T>
bool operator==(Llista<T>& l1, Llista<T>& l2) {
    bool iguals = true;
    Node<int>* node1 = l1.primer;
    Node<int>* node2 = l2.primer;
    while (iguals && node1 != NULL && node2 != NULL) {
        iguals = (node1->valor == node2->valor);
        node1 = node1->seg;
        node2 = node2->seg;
    }
    return iguals && node1 == node2;
}

template <class T>
ostream& operator<<(ostream& s, Llista<T>& l) {
    Node<T>* aux = l.primer;
    while (aux->seg != l.darrer) {
        s << aux->seg->valor;
        aux = aux->seg;
    }
    return s;
}

#endif	/* LLISTA_H */

