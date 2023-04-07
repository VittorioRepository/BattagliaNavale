#include "scelta_nomi.h"

void scelta_nomi(int & numero_giocatori, string &nome, string &nome2 ){
    string s;
    if (numero_giocatori==1){
            system("cls");
            titolo();
            cout << "Hai scelto: Modalita' Giocatore Singolo\n";
            cout << "Nome Giocatore: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, s);
            for (char c : s) {
                nome += std::toupper(c);
            }
            nome2 = "AI";
    }
    else {
        system("cls");
        titolo();
        cout << "Hai scelto: Modalita' 2 Giocatori\n";
        cout << "Nome Giocatore 1: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, s);
        for (char c : s) {
            nome += std::toupper(c);
        }
        cout << "Nome Giocatore 2: ";
        getline(cin, s);
        for (char c : s) {
            nome2 += std::toupper(c);
        }

    }
}
