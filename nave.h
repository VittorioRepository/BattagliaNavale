#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED

#include <string>
#include <iostream>
#include "funzioni.h"
using namespace std;

class nave{

public:
    nave();
    nave(int);

    void set_lunghezza(int);
    int get_lunghezza();

    void set_name(string);
    string get_name();

    void set_posizione(string);

    void set_stato();
    int get_stato();

    int get_x();
    int get_y();
    char get_orientazione();

    void controllo_colpito_o_affondato( int x_tiro, int y_tiro);




private:
    int lunghezza_nave;
    string nome_nave;

    int x;
    int y;
    char orientazione;

    int counter = 0;
    int stato=0; //affondata (1) o meno (0);
    int posizione_completa[6][2]; //ATTENZIONE: 6 e' la lunghezza massima delle navi, ma alcune sono piu' corte. 2 sta per (x,y)
};

#endif // NAVE_H_INCLUDED
