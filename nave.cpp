#include "nave.h"


nave::nave(){}



void nave::set_lunghezza(int lunghezza){

    lunghezza_nave = lunghezza;

    if (lunghezza_nave==2) nome_nave = "Cacciatorpediniere";
    if (lunghezza_nave==3) nome_nave = "Sottomarino";
    if (lunghezza_nave==4) nome_nave = "Incrociatore";
    if (lunghezza_nave==6) nome_nave = "Corazzata";
}


void nave::set_name(string name){

    nome_nave = name;
}


string nave::get_name(){

    return nome_nave;
}


int nave::get_lunghezza(){

    return lunghezza_nave;

}


//IMPOSTAZIONE X,Y,ORIENTAZIONE DELLA NAVE
void nave::set_posizione(string posizione){
    trasformazione_coordinate(posizione,x,y,orientazione);
    //La numerazione delle caselle va da 0 a 9; in "A3" lettera indica l'asse y, il numero l'asse x

    for(int i=0; i<lunghezza_nave; i++){
        if(orientazione=='O'){
            posizione_completa[i][0]=x+i;
            posizione_completa[i][1]=y;
        }
        else if(orientazione=='V'){
            posizione_completa[i][0]=x;
            posizione_completa[i][1]=y+i;

        }

    }

}

void nave::set_stato(){
    counter++;
    if(counter==lunghezza_nave){
        cout << nome_nave << " e' stata affondata!!\n";
        stato=1;
    }
}

int nave::get_stato(){
    return stato;
}




int nave::get_x(){
    return x;
}

int nave::get_y(){
    return y;
}

char nave::get_orientazione(){
    return orientazione;
}


void nave::controllo_colpito_o_affondato(int x, int y) {
    for (int i = 0; i < lunghezza_nave; i++) {
        if (posizione_completa[i][0] == x && posizione_completa[i][1] == y) {
            set_stato(); // coordinate trovate
        }
    }
}


