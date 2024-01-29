/*
 * File:   g_compropietarios2.cpp
 * Author: Robert Antoni Buj Gelonch
 *
 * Introducció al desenvolupament de programari
 * Màster programari lliure - UOC - PAC2
 */

#include "config.h"
#include <locale.h>
#include "gettext.h"
#include "compropietaris.h"
#include "split.h"

using namespace std;

/*
 * Programa principal
 */
int main(int argc, char** argv) {
    setlocale(LC_ALL, "");
    bindtextdomain("GETTEXT_PACKAGE", ".");
    textdomain("GETTEXT_PACKAGE");

    unsigned long any;
    if (argc != 2) {
        cout << "usage: " << argv[0] << gettext("ano") << endl;
        exit(1);
    }
    try {
        from_string<unsigned long>(any, string(argv[1]), dec);
        Compropietaris o_compropietaris(any);
        cout << o_compropietaris;

        // Punt 1: Llegir dades
        o_compropietaris.llegir_fitxer_propietats();
        o_compropietaris.llegir_fitxer_transmissions();
        cout << o_compropietaris;

        // Punt 2: Verificar dades participacions
        o_compropietaris.verificar_participacions();

        // Punt 3: Generar fitxer de propietaris de l'any en curs
        o_compropietaris.afegir_nous_propietaris();
        o_compropietaris.aplicar_llista_transmissions();
        o_compropietaris.treure_propietaris_sense_propietats();
        o_compropietaris.escriure_nou_fitxer_propietats();

        // Punt 4: Generar el llistat de propietaris amb les participacions globals de la comunitat
        o_compropietaris.escriure_fitxer_participacions_globals();

        // Punt 5: Generar informe de transmissions
        o_compropietaris.llistat_transmissions();
    } catch (Fitxer_excepcio e) {
        cout << e.what() << endl;
    } catch (Util_excepcio u) {
        cout << u.what() << endl;
    }
    return (EXIT_SUCCESS);
}

