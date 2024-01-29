/*
 * File:   ed.h
 * Author: Robert Antoni Buj Gelonch
 *
 * Classe base que compta el nombre d'elements que conté una estructura de de dades.
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#ifndef ED_H
#define	ED_H

using namespace std;

class ED {
protected:
    int nElems;
public:

    ED() {
        nElems = 0;
    };

    ~ED() {
    };

    bool buida() {
        return this->nElems == 0;
    }

    int mida() {
        return this->nElems;
    }
};


#endif	/* ED_H */

