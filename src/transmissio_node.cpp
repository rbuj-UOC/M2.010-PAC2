/*
 * File:   transmissio_node.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "transmissio_node.h"

Transmissio_node::Transmissio_node() {
}

Transmissio_node::Transmissio_node(string &str) {
    str.erase(str.begin());
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
    Data data_aux(parametres[1]);
    data = data_aux;

    pos = parametres[2].find_last_not_of(' ');
    if (pos != string::npos) {
        parametres[2].erase(pos + 1);
        pos = parametres[2].find_first_not_of(' ');
        if (pos != string::npos) {
            parametres[2].erase(0, pos);
        }
    }
    motiu = string(parametres[2]);
}

Transmissio_node::Transmissio_node(unsigned long p_id, string p_data, string p_motiu)
: id(p_id), data(p_data), motiu(p_motiu) {
}

Transmissio_node::~Transmissio_node() {
    motiu.clear();
}

bool Transmissio_node::operator<(Transmissio_node& nt) {
    return (id < nt.id) && (data < nt.data);
}

bool Transmissio_node::operator!=(Transmissio_node& nt) {
    return (id != nt.id);
}

string Transmissio_node::get_motiu() {
    return motiu;
}

int Transmissio_node::get_id_antic_propietari() {
    return id;
}

Data& Transmissio_node::get_data_transmissio() {
    return data;
}

ostream& operator<<(ostream& s, Transmissio_node& nt) {
    //    s << "< " << nt.id << "; " << nt.data << "; " << nt.motiu << endl;
    IteradorLlistaTransmissions it_detalls_transmissio(nt.dades_transmissio);
    it_detalls_transmissio.situarInici();
    while (!it_detalls_transmissio.fi()) {
        Transmissio* transmissio = (*it_detalls_transmissio);
        IteradorLlista<Finca> it_llista_finques(transmissio->llista_finques);
        it_llista_finques.situarInici();
        while (!it_llista_finques.fi()) {
            IteradorLlista<Participacio> it_llista_participacions((&it_llista_finques).llista_participacions);
            it_llista_participacions.situarInici();
            while (!it_llista_participacions.fi()) {
                s << (&it_llista_finques).get_id_finca() << " " <<
                        nt.get_data_transmissio() << " " <<
                        nt.get_id_antic_propietari() << " " <<
                        (&it_llista_participacions).id_propietari() << " " <<
                        nt.get_motiu(); /* FIXME */
                it_llista_participacions++;
            }
            it_llista_finques++;
        }
        it_detalls_transmissio++;
    }
    return s;
}
