/*
 * File:   compropietaris.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "compropietaris.h"

Compropietaris::Compropietaris() {
}

Compropietaris::Compropietaris(unsigned long value)
: any(value) {
}

Compropietaris::~Compropietaris() {
}

void Compropietaris::llegir_fitxer_propietats() {
    IteradorLlista<Propietari> it_propietari(llista_propietaris);
    IteradorLlista<Propietat> it_propietat(llista_propietats);

    string s = to_string(any) + gettext(FILE_PROPIETATS);
    Fitxer_propietats fitxer_propietats(s);
    fitxer_propietats.obrir_lectura();
    while (!fitxer_propietats.fi_fitxer()) {
        while (!fitxer_propietats.fi_fitxer() &&
                fitxer_propietats.estat_indefinit()) {
            fitxer_propietats.llegir_inici();
        }
        while (fitxer_propietats.estat_propietaris() &&
                !fitxer_propietats.fi_fitxer()) {
            Propietari propietari;
            if (fitxer_propietats.llegir_propietari(propietari)) {
                if (llista_propietaris.buida()) {
                    llista_propietaris.inserirFi(propietari);
                } else {
                    it_propietari.situarInici();
                    while ((&it_propietari < propietari) && !it_propietari.fi()) {
                        it_propietari++;
                    }
                    llista_propietaris.inserir(propietari, it_propietari);
                }
            }
        }
        while (fitxer_propietats.estat_propietats() &&
                !fitxer_propietats.fi_fitxer()) {
            Propietat propietat;
            if (fitxer_propietats.llegir_propietat(propietat)) {
                if (llista_propietats.buida()) {
                    llista_propietats.inserirFi(propietat);
                } else {
                    it_propietat.situarInici();
                    while ((&it_propietat < propietat) && !it_propietat.fi()) {
                        it_propietat++;
                    }
                    llista_propietats.inserir(propietat, it_propietat);
                }
            }
        }
    }
}

void Compropietaris::llegir_fitxer_transmissions() {
    IteradorLlista<Propietari> it_propietari(llista_nous_propietaris);
    IteradorLlista<Transmissio_node> it_llista_transmissions(llista_transmissions);
    IteradorLlistaTransmissions it_detalls_transmissio;
    int etapa = 1;

    string s = to_string(any) + gettext(FILE_TRANSMISSIONS);
    Fitxer_transmissions fitxer_transmissions(s);
    fitxer_transmissions.obrir_lectura();
    while (!fitxer_transmissions.fi_fitxer()) {
        while (!fitxer_transmissions.fi_fitxer() && fitxer_transmissions.estat_indefinit()) {
            fitxer_transmissions.llegir_inici();
        }
        while (fitxer_transmissions.estat_propietaris() && !fitxer_transmissions.fi_fitxer()) {
            Propietari propietari;
            if (fitxer_transmissions.llegir_propietari(propietari)) {
                it_propietari.situarInici();
                if (!llista_nous_propietaris.buida()) {
                    while ((&it_propietari < propietari) && !it_propietari.fi()) {
                        it_propietari++;
                    }
                }
                llista_nous_propietaris.inserir(propietari, it_propietari);
            }
        }
        while (fitxer_transmissions.estat_transmissions() && !fitxer_transmissions.fi_fitxer()) {
            string linia = fitxer_transmissions.llegir_linia();
            if (linia.length() > 0) {
                if (!fitxer_transmissions.es_comentari(linia)) {
                    switch (linia.at(0)) {
                        case '>':
                            if ((etapa == 1) || (etapa == 4)) {
                                Transmissio_node nt(linia);
                                llista_transmissions.inserirFi(nt);
                                it_llista_transmissions.situarFinal();
                                it_llista_transmissions--;
                                etapa = 2;
                            } else {
                                throw eCompropietaris();
                            }
                            break;
                        case '+':
                            if ((etapa == 2) || (etapa == 4)) {
                                string tipus = (&it_llista_transmissions).get_motiu();
                                IteradorLlistaTransmissions it_detalls_transmissio_aux((&it_llista_transmissions).dades_transmissio);
                                it_detalls_transmissio = it_detalls_transmissio_aux;
                                if (tipus.compare(gettext(TYPE_INHERITANCE)) == 0) {
                                    Herencia h(linia);
                                    (&it_llista_transmissions).dades_transmissio.inserirFi(h);
                                } else {
                                    if (tipus.compare(gettext(TYPE_TRADING)) == 0) {
                                        Compraventa c(linia);
                                        (&it_llista_transmissions).dades_transmissio.inserirFi(c);
                                    } else {
                                        if (tipus.compare(gettext(TYPE_DONATIONS)) == 0) {
                                            Donacio d(linia);
                                            (&it_llista_transmissions).dades_transmissio.inserirFi(d);
                                        } else {
                                            throw eCompropietaris();
                                        }
                                    }
                                }
                                it_detalls_transmissio.situarFinal();
                                it_detalls_transmissio--;
                                etapa = 3;
                            } else {
                                throw eCompropietaris();
                            }
                            break;
                        default:
                            if ((etapa == 3) || (etapa == 4)) {
                                Finca finca(linia);
                                Transmissio t;
                                Llista<Finca> lf;
                                lf = (&it_detalls_transmissio);
                                lf.inserirFi(finca);
                                it_detalls_transmissio.assigna(lf);
                                etapa = 4;
                            } else {
                                throw eCompropietaris();
                            }
                            break;
                    }
                }
            }
        }
    }
}

void Compropietaris::verificar_participacions() {
    IteradorLlista<Propietat> it_llista_propietats(llista_propietats);

    // verificació participacions generals
    if (!llista_propietats.buida()) {
        Fraccio f_general;
        it_llista_propietats.situarInici();
        f_general = (&it_llista_propietats).f_participacio_general();
        it_llista_propietats++;
        while (!it_llista_propietats.fi()) {
            f_general += (&it_llista_propietats).f_participacio_general();
            it_llista_propietats++;
        }
        if (!f_general.unitat()) {
            cout << gettext("Error: La suma de las participaciones generales es") << " " << f_general << endl;
        }
    }

    // verificació participacions parcials
    if (!llista_propietats.buida()) {
        it_llista_propietats.situarInici();
        while (!it_llista_propietats.fi()) {
            if (!(&it_llista_propietats).llista_participacions.buida()) {
                IteradorLlista<Participacio> it_llista_participacions((&it_llista_propietats).llista_participacions);
                it_llista_participacions.situarInici();
                Fraccio f_parcial((&it_llista_participacions).f_participacio_parcial());
                it_llista_participacions++;
                while (!it_llista_participacions.fi()) {
                    f_parcial += (&it_llista_participacions).f_participacio_parcial();
                    it_llista_participacions++;
                }
                if (!f_parcial.unitat()) {
                    cout << gettext("Error: La suma de las participaciones parciales es") <<
                            " " << f_parcial << " -> " << (&it_llista_propietats);
                }
            }
            it_llista_propietats++;
        }
    }
}

void Compropietaris::afegir_nous_propietaris() {
    IteradorLlista<Propietari> it_llista_propietaris(llista_propietaris);
    IteradorLlista<Propietari> it_llista_propietaris_nous(llista_nous_propietaris);
    if (!llista_nous_propietaris.buida()) {
        it_llista_propietaris_nous.situarInici();
        while (!it_llista_propietaris_nous.fi()) {
            if (llista_propietaris.buida()) {
                llista_propietaris.inserirFi((&it_llista_propietaris_nous));
            } else {
                it_llista_propietaris.situarInici();
                while ((&it_llista_propietaris < &it_llista_propietaris_nous) && (!it_llista_propietaris.fi())) {
                    it_llista_propietaris++;
                }
                llista_propietaris.inserir((&it_llista_propietaris_nous), it_llista_propietaris);
            }
            it_llista_propietaris_nous++;
        }
    }
}

void Compropietaris::aplicar_llista_transmissions() {
    unsigned long id_antic_propietari;
    unsigned long id_finca;

    if (!llista_transmissions.buida() && !llista_propietats.buida()) {
        IteradorLlista<Transmissio_node> it_llista_transmissions(llista_transmissions);
        IteradorLlista<Propietat> it_llista_propietats(llista_propietats);
        it_llista_transmissions.situarInici();
        while (!it_llista_transmissions.fi()) {
            id_antic_propietari = (&it_llista_transmissions).get_id_antic_propietari();
            if (!(&it_llista_transmissions).dades_transmissio.buida()) {
                IteradorLlistaTransmissions it_detalls_transmissio((&it_llista_transmissions).dades_transmissio);
                /*
                 * (A)fegir nous propietaris amb les seves participacions a la llista de propietats
                 * sense eliminar la participacio de l'antic propietari
                 */
                it_detalls_transmissio.situarInici();
                while (!it_detalls_transmissio.fi()) {
                    Transmissio* transmissio = (*it_detalls_transmissio);
                    if (!(transmissio->llista_finques.buida())) {
                        IteradorLlista<Finca> it_llista_finques(transmissio->llista_finques);
                        it_llista_finques.situarInici();
                        while (!it_llista_finques.fi()) {
                            id_finca = (&it_llista_finques).get_id_finca();
                            if (id_finca == 0) {
                                // (CAS 1-A) Totes les propietats de l'antic propietari amb id_antic_propietari
                                it_llista_propietats.situarInici();
                                while (!it_llista_propietats.fi() && (&it_llista_propietats != id_finca)) {
                                    IteradorLlista<Participacio> it_llista_participacions((&it_llista_propietats).llista_participacions);
                                    it_llista_participacions.situarInici();
                                    while (!it_llista_participacions.fi() && (&it_llista_participacions != id_antic_propietari)) {
                                        it_llista_participacions++;
                                    }
                                    if (!it_llista_participacions.fi()) {
                                        Fraccio f_participacio_antiga = (&it_llista_participacions).f_participacio_parcial();
                                        IteradorLlista<Participacio> it_llista_participacions_t((&it_llista_finques).llista_participacions);
                                        it_llista_participacions_t.situarInici();
                                        while (!it_llista_participacions_t.fi()) {
                                            Fraccio f_participacio_aux = f_participacio_antiga;
                                            f_participacio_aux *= (&it_llista_participacions_t).f_participacio_parcial();
                                            // (CAS 1-A: comprovar) comprovar que no existeixi el nou propietari al llistat de participacions
                                            unsigned long id_nou_propietari = (&it_llista_participacions_t).id_propietari();
                                            IteradorLlista<Participacio> it_llista_participacions_aux((&it_llista_propietats).llista_participacions);
                                            it_llista_participacions_aux.situarInici();
                                            while (!it_llista_participacions_aux.fi() && (&it_llista_participacions_aux != id_nou_propietari)) {
                                                it_llista_participacions_aux++;
                                            }
                                            if (it_llista_participacions_aux.fi()) {
                                                // (CAS 1-A: comprovar: existeix)
                                                // no s'ha trobat l'identificador del nou propietari al llistat de participacions
                                                Participacio participacio(id_nou_propietari, f_participacio_aux);
                                                (&it_llista_propietats).llista_participacions.inserirFi(participacio);
                                            } else {
                                                // (CAS 1-A: comprovar: no existeix)
                                                // s'ha trobat a la llista de participacionsActualitzar la seva participacio
                                                (&it_llista_participacions_aux) += f_participacio_aux;
                                            }
                                            // (CAS 1-A: comprovar)
                                            it_llista_participacions_t++;
                                        }
                                    }
                                    it_llista_propietats++;
                                }
                                // (CAS 1-A)
                            } else {
                                // (CAS 2-A) Una propietat de l'antic propietari amb id_antic_propietari
                                it_llista_propietats.situarInici();
                                while (!it_llista_propietats.fi() && (&it_llista_propietats != id_finca)) {
                                    it_llista_propietats++;
                                }
                                IteradorLlista<Participacio> it_llista_participacions((&it_llista_propietats).llista_participacions);
                                it_llista_participacions.situarInici();
                                while (!it_llista_participacions.fi() && (&it_llista_participacions != id_antic_propietari)) {
                                    it_llista_participacions++;
                                }
                                Fraccio f_participacio_antiga = (&it_llista_participacions).f_participacio_parcial();
                                if (!(&it_llista_finques).llista_participacions.buida()) {
                                    IteradorLlista<Participacio> it_llista_participacions_t((&it_llista_finques).llista_participacions);
                                    it_llista_participacions_t.situarInici();
                                    while (!it_llista_participacions_t.fi()) {
                                        Fraccio f_participacio_aux = f_participacio_antiga;
                                        f_participacio_aux *= (&it_llista_participacions_t).f_participacio_parcial();
                                        // (CAS 2-A: comprovar) comprovar que no existeixi el nou propietari al llistat de participacions
                                        unsigned long id_nou_propietari = (&it_llista_participacions_t).id_propietari();
                                        IteradorLlista<Participacio> it_llista_participacions_aux((&it_llista_propietats).llista_participacions);
                                        it_llista_participacions_aux.situarInici();
                                        while (!it_llista_participacions_aux.fi() && (&it_llista_participacions_aux != id_nou_propietari)) {
                                            it_llista_participacions_aux++;
                                        }
                                        if (it_llista_participacions_aux.fi()) {
                                            // (CAS 2-A: comprovar: existeix)
                                            // no s'ha trobat l'identificador del nou propietari al llistat de participacions
                                            Participacio participacio(id_nou_propietari, f_participacio_aux);
                                            (&it_llista_propietats).llista_participacions.inserirFi(participacio);
                                        } else {
                                            // (CAS 2-A: comprovar: no existeix)
                                            // s'ha trobat a la llista de participacionsActualitzar la seva participacio
                                            (&it_llista_participacions_aux) += f_participacio_aux;
                                        }
                                        // (CAS 2-A: comprovar)
                                        it_llista_participacions_t++;

                                    }
                                }
                                // (CAS 2-A)
                            }
                            it_llista_finques++;
                        }
                    }
                    it_detalls_transmissio++;
                }
                /*
                 * (E)liminar participació de l'antic propietari
                 */
                it_detalls_transmissio.situarInici();
                while (!it_detalls_transmissio.fi()) {
                    Transmissio* transmissio = (*it_detalls_transmissio);
                    if (!(transmissio->llista_finques.buida())) {
                        IteradorLlista<Finca> it_llista_finques(transmissio->llista_finques);
                        it_llista_finques.situarInici();
                        while (!it_llista_finques.fi()) {
                            id_finca = (&it_llista_finques).get_id_finca();
                            if (id_finca == 0) {
                                // (CAS 1-E) Todes les propietats de l'antic propietari amb id_antic_propietari
                                it_llista_propietats.situarInici();
                                while (!it_llista_propietats.fi()) {
                                    if (!(&it_llista_propietats).llista_participacions.buida()) {
                                        IteradorLlista<Participacio> it_llista_participacions((&it_llista_propietats).llista_participacions);
                                        it_llista_participacions.situarInici();
                                        while ((&it_llista_participacions != id_antic_propietari) && !it_llista_participacions.fi()) {
                                            it_llista_participacions++;
                                        }
                                        if (!it_llista_participacions.fi()) {
                                            (&it_llista_propietats).llista_participacions.eliminar(it_llista_participacions);
                                        }
                                    }
                                    it_llista_propietats++;
                                }
                                // (CAS 1-E)
                            } else {
                                // (CAS 2-E) Una propietat de l'antic propietari amb id_antic_propietari
                                it_llista_propietats.situarInici();
                                while (!it_llista_propietats.fi() && (&it_llista_propietats != id_finca)) {
                                    it_llista_propietats++;
                                }
                                IteradorLlista<Participacio> it_llista_participacions((&it_llista_propietats).llista_participacions);
                                it_llista_participacions.situarInici();
                                while (!it_llista_participacions.fi() && (&it_llista_participacions != id_antic_propietari)) {
                                    it_llista_participacions++;
                                }
                                if (!it_llista_participacions.fi()) {
                                    (&it_llista_propietats).llista_participacions.eliminar(it_llista_participacions);
                                }
                                // (CAS 2-E)
                            }
                            it_llista_finques++;
                        }
                    }
                    it_detalls_transmissio++;
                }
                // A+E
            }
            it_llista_transmissions++;
        }
    }
}

void Compropietaris::treure_propietaris_sense_propietats() {
    IteradorLlista<Propietari> it_llista_propietari(llista_propietaris);
    IteradorLlista<Propietat> it_llista_propietats(llista_propietats);
    unsigned long id_propietari;
    bool trobat;

    llista_nous_propietaris = llista_propietaris; // salvaguarda
    it_llista_propietari.situarInici();
    while (!it_llista_propietari.fi()) {
        trobat = false;
        id_propietari = (&it_llista_propietari).get_id();
        it_llista_propietats.situarInici();
        while (!trobat && !it_llista_propietats.fi()) {
            IteradorLlista<Participacio> it_llista_participacions((&it_llista_propietats).llista_participacions);
            it_llista_participacions.situarInici();
            while (!trobat && !it_llista_participacions.fi()) {
                trobat = (&it_llista_participacions) == id_propietari;
                it_llista_participacions++;
            }
            it_llista_propietats++;
        }
        if (!trobat) {
            llista_propietaris.eliminar(it_llista_propietari);
        } else {
            it_llista_propietari++;
        }
    }
}

void Compropietaris::escriure_nou_fitxer_propietats() {
    string s = to_string(any + 1) + gettext(FILE_PROPIETATS);
    ofstream outfile(s.c_str(), ofstream::out);
    outfile << "#propietarios" << endl;
    outfile << llista_propietaris;
    outfile << "#propiedades" << endl;
    outfile << llista_propietats;
}

void Compropietaris::escriure_fitxer_participacions_globals() {
    Llista<Comunitat> llista_participacions_comunitat;
    IteradorLlista<Propietari> it_llista_propietaris(llista_propietaris);
    Fraccio fraccio_resultat, fraccio_general, fraccio_parcial, fraccio_total;
    Percentatge percentatge_resultat;
    unsigned long num_finques;
    unsigned long id_propietari;
    unsigned long num_propietaris;
    bool estableix;

    estableix = true;
    it_llista_propietaris.situarInici();
    while (!it_llista_propietaris.fi()) {
        num_finques = 0;
        num_propietaris = 0;
        id_propietari = (&it_llista_propietaris).get_id();
        IteradorLlista<Propietat> it_llista_propietats(llista_propietats);
        it_llista_propietats.situarInici();
        while (!it_llista_propietats.fi()) {
            fraccio_general = (&it_llista_propietats).f_participacio_general();
            IteradorLlista<Participacio> it_llista_participacions((&it_llista_propietats).llista_participacions);
            it_llista_participacions.situarInici();
            while (!it_llista_participacions.fi() && (&it_llista_participacions != id_propietari)) {
                it_llista_participacions++;
            }
            if (!it_llista_participacions.fi()) {
                fraccio_parcial = (&it_llista_participacions).f_participacio_parcial();
                if (num_finques == 0) {
                    fraccio_parcial *= fraccio_general;
                    fraccio_total = fraccio_parcial;
                } else {
                    fraccio_parcial *= fraccio_general;
                    fraccio_total += fraccio_parcial;
                }
                num_finques++;
            }
            it_llista_propietats++;
        }
        Percentatge percentatge_parcial(fraccio_total);

        Comunitat c(&it_llista_propietaris, fraccio_total, num_finques, percentatge_parcial);
        llista_participacions_comunitat.inserirFi(c);
        if (estableix) {
            fraccio_resultat = fraccio_total;
            percentatge_resultat = percentatge_parcial;
            estableix = false;
        } else {
            fraccio_resultat += fraccio_total;
            percentatge_resultat += percentatge_parcial;
        }
        num_propietaris++;
        it_llista_propietaris++;
    }

    string s = to_string(any + 1) + gettext(FILE_PARTS);
    ofstream outfile(s.c_str(), ofstream::out);
    outfile << left << setw(8) << gettext("idProp") <<
            left << setw(27) << gettext("Nombre") <<
            left << setw(20) << gettext("Email") <<
            left << setw(10) << gettext("NumFincas") <<
            left << setw(10) << gettext("PartFracc") <<
            " " << gettext("(%)") << endl;
    outfile << setw(79) << setfill('-') << "" << setfill(' ') << endl;
    outfile << llista_participacions_comunitat;
    outfile << setw(79) << setfill('-') << "" << setfill(' ') << endl;
    outfile << right << setw(5) << num_propietaris << " " <<
            left << setw(34) << gettext("propietarios") <<
            right << setw(25) << gettext("TOTAL") << ": " <<
            fraccio_resultat << " (" <<
            percentatge_resultat << ")" << endl;
}

void Compropietaris::llistat_transmissions() {
    string s = to_string(any + 1) + gettext(FILE_REPORT);
    unsigned long num_transmissions = 0;
    ofstream outfile(s.c_str(), ofstream::out);
    bool primer;

    outfile << "[" << right << setw(3) << gettext("NF") << "][" <<
            setw(10) << gettext("Fecha Tr") << "][" <<
            left << setw(27) << gettext("Prop.Anterior") << "][" <<
            left << setw(27) << gettext("Prop.Nuevo") << "][" <<
            left << setw(12) << gettext("Motivo") << "][" << gettext("Datos adicionales") << endl;
    outfile << " ---  ----------  ---------------------------  ---------------------------  ------------  -----------------------------------------" << endl;

    IteradorLlista<Transmissio_node> it_llista_transmissions(llista_transmissions);
    it_llista_transmissions.situarInici();
    while (!it_llista_transmissions.fi()) {
        IteradorLlistaTransmissions it_detalls_transmissio((&it_llista_transmissions).dades_transmissio);
        it_detalls_transmissio.situarInici();
        primer = true;
        while (!it_detalls_transmissio.fi()) {
            Transmissio* transmissio = (*it_detalls_transmissio);
            IteradorLlista<Finca> it_llista_finques(transmissio->llista_finques);
            it_llista_finques.situarInici();
            while (!it_llista_finques.fi()) {
                IteradorLlista<Participacio> it_llista_participacions((&it_llista_finques).llista_participacions);
                it_llista_participacions.situarInici();
                while (!it_llista_participacions.fi()) {

                    unsigned long id_nou_propietari = (&it_llista_participacions).id_propietari();
                    IteradorLlista<Propietari> it_nou_propietari(llista_nous_propietaris);
                    it_nou_propietari.situarInici();
                    while (!it_nou_propietari.fi() && ((&it_nou_propietari).get_id() != id_nou_propietari)) {
                        it_nou_propietari++;
                    }

                    unsigned long id_antic_propietari = (&it_llista_transmissions).get_id_antic_propietari();
                    IteradorLlista<Propietari> it_antic_propietari(llista_nous_propietaris);
                    it_antic_propietari.situarInici();
                    while (!it_nou_propietari.fi() && ((&it_antic_propietari).get_id() != id_antic_propietari)) {
                        it_antic_propietari++;
                    }

                    if (primer) {
                        outfile << "[" << right << setw(3) << (&it_llista_finques).get_id_finca() << "][" <<
                                (&it_llista_transmissions).get_data_transmissio() << "][" <<
                                left << setw(27) << (&it_antic_propietari).get_nom() << "][" <<
                                left << setw(27) << (&it_nou_propietari).get_nom() << "][" <<
                                left << setw(12) << (&it_llista_transmissions).get_motiu() << "][";
                        transmissio->llistat(outfile) << endl;
                        primer = false;
                    } else {
                        outfile << "[" << right << setw(3) << (&it_llista_finques).get_id_finca() << "][" <<
                                setw(10) << " " << "][" <<
                                left << setw(27) << " " << "][" <<
                                left << setw(27) << (&it_nou_propietari).get_nom() << "][" <<
                                left << setw(12) << (&it_llista_transmissions).get_motiu() << "][";
                        transmissio->llistat(outfile) << endl;
                    }
                    it_llista_participacions++;
                }
                it_llista_finques++;
            }
            it_detalls_transmissio++;
        }
        num_transmissions++;
        outfile << " ---  ----------  ---------------------------  ---------------------------  ------------  -----------------------------------------" << endl;
        it_llista_transmissions++;
    }
    outfile << " " << num_transmissions << gettext(" transmisiones") << endl;
}

ostream& operator<<(ostream& s, Compropietaris& c) {
    if ((c.llista_propietaris.mida() == 0) &&
            (c.llista_propietats.mida() == 0) &&
            (c.llista_nous_propietaris.mida() == 0) &&
            (c.llista_transmissions.mida() == 0)) {
        s << gettext("Procesando ano") << " " << c.any + 1 << "..." << endl << endl;
    } else {
        string str;
        stringstream ss;
        ss << c.any;
        str = ss.str();
        s << gettext("Registros leidos:") << endl <<
                left << setw(22) << gettext("propietarios") + string(" ") + str << " : " << right << setw(3) << c.llista_propietaris.mida() << endl <<
                left << setw(22) << gettext("propiedades") << " : " << right << setw(3) << c.llista_propietats.mida() << endl <<
                left << setw(22) << gettext("propietarios nuevos") << " : " << right << setw(3) << c.llista_nous_propietaris.mida() << endl <<
                left << setw(22) << gettext("transmisiones") << " : " << right << setw(3) << c.llista_transmissions.mida() << endl;
    }
    return s;
}
