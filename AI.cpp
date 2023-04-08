#include "ai.h"


ai::ai():board(){}

ai::ai(string nome):board(nome){}


void ai::posizionamento_navi_AI(){

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

    // AI POSIZIONA LE NAVI COME GIOCATORE (INVECE DI INPUT DA TASTIERA USO RANDOM)
    string temporanea;
    int i=0;
    int x;
    int y;
    int lunghezza;
    int controllo_compenetrazione_e_dimensioni = 0;

    while(i<10){

        lunghezza=nomi_navi[i].get_lunghezza();
        x=coordinata_random();
        y=coordinata_random();
        temporanea=trasformazione_coordinate_ridotta_inversa(x,y);
        controllo_compenetrazione_e_dimensioni=0;

        if (coordinata_random()%2==0){   //Caso orizzontale

             if(x+lunghezza<11){ //controllo dimensioni board
                for(int k=0; k<lunghezza; k++){
                    if(tabella[y][x+k]=='O'){ //controllo se � gia' presente una nave
                        i--; //se e' presente, abbasso l'indice di 1
                        controllo_compenetrazione_e_dimensioni = 1; //compenetrazione
                        // fermo il ciclo
                    };
                }
                if(controllo_compenetrazione_e_dimensioni==0){
                    for(int k=0; k<lunghezza; k++){
                    tabella[y][x+k]='O'; //indicatore presenza nave "O"
                    }
                    i++;
                }
            }
            else if (x+lunghezza>10){ //la nave esce dalla board
                i--;
                controllo_compenetrazione_e_dimensioni = 1;
            }

        } 

        else {  //Caso verticale 
        
            if(y+lunghezza<11){ //controllo dimensioni board
                    for(int k=0; k<lunghezza; k++){
                        if(tabella[y+k][x]=='O'){ //controllo se � gia' presente una nave
                            i--; //se e' presente, abbasso l'indice di 1
                            controllo_compenetrazione_e_dimensioni = 1; //compenetrazione
                            //fermo il ciclo 
                        };
                    }
                    if(controllo_compenetrazione_e_dimensioni==0){
                        for(int k=0; k<lunghezza; k++){
                        tabella[y+k][x]='O'; //indicatore presenza nave "O"
                        }
                        i++;
                    }
                }
                else if (y+lunghezza>10){
                    i--;
                    controllo_compenetrazione_e_dimensioni = 1;
                }
        
        
        
        }


    }


}



void ai::scelta_casella_da_colpire( int &x, int &y){
    x=0;
    y=0;
}


int ai::coordinata_random(){

    srand(time(0));
    return rand()%10;

}