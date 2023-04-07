#include "board.h"
#include "nave.h"




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



void board::posizionamento_navi_giocatore(){

    // SETTO LA LUNGHEZZA DELLE NAVI (il costruttore mi dava problemi)
    nomi_navi[0].set_lunghezza(2);
    nomi_navi[1].set_lunghezza(2);
    nomi_navi[2].set_lunghezza(2);
    nomi_navi[3].set_lunghezza(2);
    nomi_navi[4].set_lunghezza(3);
    nomi_navi[5].set_lunghezza(3);
    nomi_navi[6].set_lunghezza(3);
    nomi_navi[7].set_lunghezza(4);
    nomi_navi[8].set_lunghezza(4);
    nomi_navi[9].set_lunghezza(6);


    // QUI FACCIAMO INSERIRE DAL GIOCATORE LE COORDINATE ALL'INTERNO DELLE ISTANZE NAVI
    string temporanea;
    int x;
    int y;
    char orientazione;
    int lunghezza;

    for(int i=0; i<10; i++){

        titolo2();
        cout << "\nQui puo' posizionare le proprie navi " << nome_giocatore << ":" << endl;
        cout << "\nPer posizionare le navi devi dirmi le coordinate della casella piu' in alto a sinistra in cui vuoi che si trovi la nave\nE poi devi dirmi se vuoi posizionarla in orizzontale o verticale\n";
        cout << "Ad esempio per una nave posizionata in orizzontale a partire dalla casella B2 dovrai digitare B2O, in verticale B2V.\n";

        visualizzazione_amica();

        cout << "\nPosiziona un " << nomi_navi[i].get_name() << " di lunghezza " << nomi_navi[i].get_lunghezza() << ": ";
        cin >> temporanea;
        nomi_navi[i].set_posizione(temporanea);

        system("cls");


        //QUI DISEGNAMO SUL TABELLONE LE NAVI

        x=nomi_navi[i].get_x();
        y=nomi_navi[i].get_y();
        orientazione=nomi_navi[i].get_orientazione();
        lunghezza=nomi_navi[i].get_lunghezza();


        if(orientazione=='O'){
            for(int k=0; k<lunghezza; k++){
                tabella[y][x+k]='O';
            }
        }
        else if(orientazione=='V'){
            for(int k=0;k<lunghezza; k++){
                tabella[y+k][x]='O';
            }
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




