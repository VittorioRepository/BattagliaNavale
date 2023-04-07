#include "modalita.h"

void scelta_modalita(int & numero_giocatori){

    do{
        cout << "Modalita' Giocatore Singolo (inserisci 1) o 2 Giocatori (inserisci 2)? ";
        cin >> numero_giocatori;
        if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Hai inserito un valore non valido!\n";
        }
        else{
            if(numero_giocatori==1 or numero_giocatori==2) break;
        }

    }while(true);

}
