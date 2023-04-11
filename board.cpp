#include "board.h"





board::board(){
    set_board();
}


board::board(string nome){
    nome_giocatore = nome;
    set_board();
}

void board::set_board(){
    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_cols; j++) {
        tabella[i][j] = '-';
      }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabella_nemica[i][j] = tabella[i][j];
        }
    }
}




void board::visualizzazione_amica(){
    cout << endl;
    cout << "------" << "LA TUA FLOTTA" <<"------" << endl;
    cout << "------" << nome_giocatore << "------" << endl;
    cout << "    ";
        for(int i = 0; i < num_cols; i++) {
          cout << char(i+'A') << " ";
    }
    cout << endl;

    for(int i = 0; i < num_rows; i++) {
        if(i<9){
            cout << i+1 << "   ";
        }
        else if(i==9){
            cout << i+1 << "  ";
        }
        for(int j = 0; j < num_cols; j++) {
            cout << tabella[i][j] << " ";
        }
        cout << endl;
    }
}

void board::visualizzazione_nemica(){
    cout << endl;
    cout << "------" << "LA FLOTTA AVVERSARIA" <<"------" << endl;
    cout << "------" << nome_giocatore << "------" << endl;
    cout << "    ";
        for(int i = 0; i < num_cols; i++) {
          cout << char(i+'A') << " ";
    }
    cout << endl;

    for(int i = 0; i < num_rows; i++) {
        if(i<9){
            cout << i+1 << "   ";
        }
        else if(i==9){
            cout << i+1 << "  ";
        }
        for(int j = 0; j < num_cols; j++) {
            cout << tabella_nemica[i][j] << " ";
        }
        cout << endl;
    }
}


bool board::controllo_contatore_globale(){
    contatore_globale=0;
    for(int i=0; i<10; i++){
        int j=nomi_navi[i].get_stato();
        if(j==1) contatore_globale++;
    }

    if(contatore_globale<10) return false;
    else return true;
}






