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

    void scelta_casella_da_colpire( int &, int &);

    int coordinata_random();

};




#endif // AI_H_INCLUDED




