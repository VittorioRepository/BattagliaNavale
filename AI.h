#ifndef AI_H_INCLUDED
#define AI

#include <string>

#include <iostream>

#include "nave.h"

#include "funzioni.h"

#include "board.h"

#include <time.h>


using namespace std;


class ai : public board {
public:
    ai();
    ai(string);
    void posizionamento_navi_AI(); // DA SCRIVERE PER LA MODALITA' GIOCATORE SINGOLO;
    int scelta_x_da_colpire();
    int scelta_y_da_colpire();
    int coordinata_random();
    bool casella_partenza(int, int, int, string);
    void set_memoria(bool);
    bool get_memoria();
    void set_colpo_precedente(int, int);
    void aumenta_contatore_colpi();

private:
    bool memoria=false;
    int colpo_precedente [2]; // [x,y]
    int spostamenti [2]; // [+1,-1]
    int contatore_colpi=0;
    int direzione_colpo;
};


#endif // AI_H_INCLUDED




