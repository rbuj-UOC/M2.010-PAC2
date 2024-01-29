/*
 * File:   propietat.cpp
 * Author: robert
 *
 * Created on 22 / novembre / 2011, 00:47
 */

#include "propietat.h"

Propietat::Propietat() {
}

Propietat::Propietat(string &str) {
    vector<string> parametres = split(str, ';');
    from_string<unsigned long>(id, parametres[0], dec);

    string::size_type pos = parametres[1].find_last_not_of(' ');
    if (pos != string::npos) {
        parametres[1].erase(pos + 1);
        pos = parametres[1].find_first_not_of(' ');
        if (pos != string::npos) {
            parametres[1].erase(0, pos);
        }
    }
    nom = string(parametres[1]);

    Fraccio f_aux(parametres[2]);
    participacio = f_aux;

    IteradorLlista<Participacio> it(llista_participacions);
    vector<string> v_participacions = split(parametres[3].c_str(), '&');
    for (unsigned int i = 0; i < v_participacions.size(); i++) {
        Participacio p_aux(string(v_participacions[i].c_str()));
        if (llista_participacions.buida()) {
            llista_participacions.inserirFi(p_aux);
        } else {
            it.situarInici();
            while ((&it < p_aux) && !it.fi()) {
                it++;
            }
            llista_participacions.inserir(p_aux, it);
        }
    }
}

Propietat::~Propietat() {
    nom.clear();
}

bool Propietat::operator<(Propietat& p) {
    return id < p.id;
}

void Propietat::operator=(Propietat& p) {
    id = p.id;
    nom = p.nom;
    participacio = p.participacio;
    llista_participacions = p.llista_participacions;
}

bool Propietat::operator!=(unsigned long& p_id) {
    return id != p_id;
}

Fraccio& Propietat::f_participacio_general() {
    return participacio;
}

ostream& operator<<(ostream& s, Propietat& p){
    s << p.id << "; " << p.nom << "; " << p.participacio << "; " << p.llista_participacions << endl;
    return s;
}
