/*
 * File:   llista_transmissions.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "itellis_transmissions.h"

void LlistaTransmissions::buidar() {
    // Esborra els elements de la llista i la deixa buida
    NodeTransmissio* aux;
    while (primer->seg != darrer) {
        aux = primer->seg;
        primer->seg = primer->seg->seg;
        delete aux;
    }
    nElems = 0;
    darrer->ant = primer;
}

LlistaTransmissions::LlistaTransmissions() {
    // Crea el node fantasma de la llista
    primer = new NodeTransmissio;
    if (primer == NULL) throw noMem();
    primer->ant = NULL;

    darrer = new NodeTransmissio;
    if (darrer == NULL) throw noMem();
    darrer->seg = NULL;

    darrer->ant = primer;
    primer->seg = darrer;
}

LlistaTransmissions::LlistaTransmissions(LlistaTransmissions& l2) {
    primer = new NodeTransmissio;
    if (primer == NULL) throw noMem();
    primer->ant = NULL;

    darrer = new NodeTransmissio;
    if (darrer == NULL) throw noMem();
    darrer->seg = NULL;

    nElems = 0;
    // Crida a l'assignacio entre llistes, per tant, copia els elements
    // de l2 sobre la llista actual (la que estem construint).
    *(this) = l2;
}

LlistaTransmissions::~LlistaTransmissions() {
    // Esborra tots els nodes dels que consta la llista.
    NodeTransmissio* aux;
    while (primer->seg != darrer) {
        aux = primer;
        primer = primer->seg;
        delete aux;
    }
    delete primer;
    delete darrer;
    primer = NULL;
    darrer = NULL;
}

void LlistaTransmissions::inserirCap(Transmissio& t) {
    NodeTransmissio* aux;
    aux = new NodeTransmissio;
    if (aux == NULL) throw noMem();
    aux->valor = t.clonacio();
    aux->seg = primer->seg;
    aux->ant = primer;
    primer->seg = aux;
    aux->seg->ant = aux;
    nElems++;
}

void LlistaTransmissions::inserirFi(Transmissio& t) {
    NodeTransmissio* aux;
    aux = new NodeTransmissio;
    if (aux == NULL) throw noMem();
    aux->valor = t.clonacio();
    darrer->ant->seg = aux;
    aux->seg = darrer;
    aux->ant = darrer->ant;
    darrer->ant = aux;
    nElems++;
}

void LlistaTransmissions::inserir(Transmissio& t, IteradorLlistaTransmissions& ite) {
    NodeTransmissio* aux;
    aux = new NodeTransmissio;
    if (aux == NULL) throw noMem();
    aux->valor = t.clonacio();
    aux->seg = ite.ed->seg;
    ite.ed->seg = aux;
    aux->ant = ite.ed;
    aux->seg->ant = aux;
    ite.ed = aux;
    nElems++;
}

void LlistaTransmissions::eliminarCap() {
    NodeTransmissio* aux;
    aux = primer->seg;
    primer->seg = aux->seg;
    aux->seg->ant = primer;
    nElems--;
    delete aux;
}

void LlistaTransmissions::eliminarFi() {
    NodeTransmissio* aux;
    aux = darrer->ant;
    aux->ant->seg = darrer;
    darrer->ant = aux->ant;
    nElems--;
    delete aux;
}

void LlistaTransmissions::eliminar(IteradorLlistaTransmissions& ite) {
    NodeTransmissio* aux;
    aux = ite.ed->seg;
    ite.ed->seg = ite.ed->seg->seg;
    ite.ed->seg->ant = ite.ed;
    nElems--;
    delete aux;
}

Transmissio* LlistaTransmissions::consultarCap() {
    return primer->seg->valor->clonacio();
}

Transmissio* LlistaTransmissions::consultarFi() {
    return darrer->ant->valor->clonacio();
}

Transmissio* LlistaTransmissions::consultar(IteradorLlistaTransmissions& ite) {
    return ite.ed->seg->valor->clonacio();
}

void LlistaTransmissions::operator=(LlistaTransmissions& l2) {
    IteradorLlistaTransmissions ite1(*this), ite2(l2);
    Transmissio t;
    buidar();
    ite1.situarInici();
    ite2.situarInici();
    while (!ite2.fi()) {
        (*ite2)->copia(t);
        inserir(t, ite1);
        ite2++;
    }
}

ostream& operator<<(ostream& s, LlistaTransmissions& l) {
    NodeTransmissio* aux = l.primer;
    while (aux->seg != l.darrer) {
        s << aux->seg->valor->clonacio();
        aux = aux->seg;
    }
    return s;
}
