#ifndef GIOCATORE_H_INCLUDED
#define GIOCATORE

#include <string>

#include <iostream>

#include "nave.h"

#include "funzioni.h"

#include "board.h"

using namespace std;


class giocatore : public board {
public:
    giocatore();
    giocatore(string);
    void posizionamento_navi_giocatore();
    bool controllo_ripetizioni(string);

};




#endif // GIOCATORE_H_INCLUDED
