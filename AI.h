#ifndef AI_H_INCLUDED
#define AI

#include <string>

#include <iostream>

#include "nave.h"

#include "funzioni.h"

#include "board.h"

#include <algorithm>






using namespace std;


class ai : public board {
public:
    ai();
    ai(string);
    void posizionamento_navi_AI(); 
    int scelta_x_da_colpire();
    int scelta_y_da_colpire();
    int coordinata_random() const;
    bool casella_partenza(int, int, int, string) const;
    void set_memoria(bool);
    bool get_memoria() const;
    void set_colpo_precedente(int, int);
    void aumenta_contatore_colpi();
    bool tutte_caselle_adiacenti_gia_sparate(string) const;
    void set_casella_centrale(string);
    string get_casella_centrale() const;
    




private:
    bool memoria=false;
    int colpo_precedente [2]; // [x,y]
    int spostamenti [2]; // [+1,-1]
    int contatore_colpi=0;
    int direzione_colpo;
    string casella_centrale;

};


#endif // AI_H_INCLUDED




