#include "funzioni.h"

void trasformazione_coordinate(string s, int &x, int&y, char& orientazione){
    if (s.length()==3){
        x = int(s[0])-65;
        y = stoi(s.substr(1,1))-1;
        orientazione = s[2]; //O: orizzontale, V: verticale
    }
    else if (s.length()==4){
        x = int(s[0])-65;
        y = stoi(s.substr(1,2))-1;
        orientazione = s[3]; //O: orizzontale, V: verticale
    }
}


void trasformazione_coordinate_ridotta(string s, int &x, int &y){ //SENZA ORIENTAZIONE
    if (s.length()==2){
        x = int(s[0])-65;
        y = stoi(s.substr(1,1))-1;
    }
    else if (s.length()==3){
        x = int(s[0])-65;
        y = stoi(s.substr(1,2))-1;
    }
}


string trasformazione_coordinate_ridotta_inversa(int x, int y){
    char c = static_cast<char>('A' + x);
    string s = "";
    s += c;
    s += to_string(y+1);
    return s;
}



void titolo(){
    cout << "------------------------------ BATTAGLIA NAVALE --------------------------------" << endl << endl;
}

void titolo2(){
    cout << "------------------------------  COMPUTER DI BORDO ------------------------------" << endl;
}


void passo(){
    cout << "\nInserisci un carattere qualunque per passare il turno al tuo avversario: ";
    string  passo_str;
    cin >> passo_str;
    system("cls");
}



