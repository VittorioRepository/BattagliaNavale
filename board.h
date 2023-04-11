#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <string>

#include <iostream>

#include "nave.h"

#include "funzioni.h"


using namespace std;

class board {

public:
    board();
    board(string);
    void set_board();

    void visualizzazione_amica();
    void visualizzazione_nemica();
    bool controllo_contatore_globale();




    nave d2_1;
    nave d2_2;
    nave d2_3;
    nave d2_4;
    nave d3_1;
    nave d3_2;
    nave d3_3;
    nave d4_1;
    nave d4_2;
    nave d6_1;

    nave nomi_navi[10] = {d2_1, d2_2, d2_3, d2_4, d3_1, d3_2, d3_3, d4_1, d4_2, d6_1};

    char tabella[10][10];
    char tabella_nemica[10][10];

    string nome_giocatore;



private:
    const int num_rows = 10;
    const int num_cols = 10;
    int contatore_globale=0;



};

#endif // BOARD_H_INCLUDED
