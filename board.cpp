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


int board::controllo_numero_navi_posizionate(){
    int numero_navi_posizionate = 0;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(tabella[i][j]=='O') numero_navi_posizionate++;
        }
    }
    return numero_navi_posizionate;
}



char board::get_casella_tabella(int x, int y){
    return tabella[y][x];
}


void board::set_casella_tabella_amica(int x, int y, char c){
    tabella[y][x]=c;
}

void board::set_casella_tabella_nemica(int x, int y, char c){
    tabella_nemica[y][x]=c;
}


string board::get_nome_giocatore(){
    return nome_giocatore;
}



void board::set_nome_giocatore(string name){
    nome_giocatore=name;
}


bool board::controllo_ripetizioni(string casella){
    int lunghezza=mosse_precedenti.size();
    for(int i=0;i<lunghezza;i++){
        if (mosse_precedenti[i]==casella) return false;
    }
    return true;
}

void board::aggiungi_mossa_giocata(string casella){
    mosse_precedenti.push_back(casella);
}


