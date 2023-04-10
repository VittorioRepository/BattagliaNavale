#include <iostream>

#include <string>
#include <limits>

#include "funzioni.h"

#include "gameplay.h"

#include "modalita.h"

#include "scelta_nomi.h"




using namespace std;

int main()
{
    srand(time(0));
    
    titolo();

    string nome;
    string nome2;
    int numero_giocatori;

    scelta_modalita(numero_giocatori);

    scelta_nomi(numero_giocatori, nome, nome2);

    gameplay_introduzione(numero_giocatori, nome, nome2);

    gameplay(numero_giocatori, nome, nome2); //POSIZIONAMENTO NAVI E TURNI DI GIOCO


    return 0;
}
