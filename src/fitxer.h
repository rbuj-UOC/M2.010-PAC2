/*
 * File:   fitxer.h
 * Author: robert
 *
 * Created on 22 / novembre / 2011, 10:43
 */

#ifndef FITXER_H
#define	FITXER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "fitxer_excepcio.h"

using namespace std;

class Fitxer {
public:
    string nom_fitxer;
    ifstream in;
    ifstream out;

    Fitxer();
    Fitxer(string);
    virtual ~Fitxer();

    void obrir_lectura();
    bool fi_fitxer();

    string llegir_linia();
    void escriure_linia(string);
private:

};

#endif	/* FITXER_H */

