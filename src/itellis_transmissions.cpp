/*
 * File:   itellis_transmissions.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "itellis_transmissions.h"

IteradorLlistaTransmissions::IteradorLlistaTransmissions() {
}

IteradorLlistaTransmissions::IteradorLlistaTransmissions(LlistaTransmissions& l) {
    ref = &l;
    ed = l.primer;
}

IteradorLlistaTransmissions::~IteradorLlistaTransmissions() {
}

void IteradorLlistaTransmissions::situarInici() {
    ed = ref->primer;
}

void IteradorLlistaTransmissions::situarFinal() {
    ed = ref->darrer->ant;
}

bool IteradorLlistaTransmissions::fi() {
    return ed->seg->seg == NULL;
}

bool IteradorLlistaTransmissions::inici() {
    return ed == ref->primer;
}

IteradorLlistaTransmissions& IteradorLlistaTransmissions::operator++() {
    IteradorLlistaTransmissions* aux;
    ed = ed->seg;
    aux = this;
    return *aux;
}

IteradorLlistaTransmissions& IteradorLlistaTransmissions::operator++(int) {
    IteradorLlistaTransmissions* aux;
    aux = this;
    ed = ed->seg;
    return *aux;
}

IteradorLlistaTransmissions& IteradorLlistaTransmissions::operator--() {
    IteradorLlistaTransmissions* aux;
    ed = ed->ant;
    aux = this;
    return *aux;
}

IteradorLlistaTransmissions& IteradorLlistaTransmissions::operator--(int) {
    IteradorLlistaTransmissions* aux;
    aux = this;
    ed = ed->ant;
    return *aux;
}

Transmissio* IteradorLlistaTransmissions::operator*() {
    return ed->seg->valor->clonacio();
}

Llista<Finca>& IteradorLlistaTransmissions::operator&() {
    return ed->seg->valor->llista_finques;
}

void IteradorLlistaTransmissions::operator=(IteradorLlistaTransmissions& it2) {
    ref = it2.ref;
    ed = it2.ed;
}

void IteradorLlistaTransmissions::assigna(Llista<Finca>& l){
    ed->seg->valor->assigna(l);
}
