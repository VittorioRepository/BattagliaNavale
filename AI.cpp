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
    
    int i=0;
    int x;
    int y;
    int lunghezza;
    string direzione;
    string posizione;
    

    while(i<10){

        lunghezza=nomi_navi[i].get_lunghezza();
        x=coordinata_random();
        y=coordinata_random();
        if(coordinata_random()%2==0) direzione="O";
        else direzione="V";        

        if (direzione=="O"){   //Caso orizzontale

            if(casella_partenza(lunghezza,x,y,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y][x+k]='O';                
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x,y).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x+1,y+1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y][x+k]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x+1,y+1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x-1,y-1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y][x+k]='O';   
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x-1,y-1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x-1,y+1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y][x+k]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x-1,y+1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x+1,y-1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y][x+k]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x+1,y-1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else ;
        }


        else {  //Caso verticale 
        

            if(casella_partenza(lunghezza,x,y,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y+k][x]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x,y).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x+1,y+1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y+k][x]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x+1,y+1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x-1,y-1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y+k][x]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x-1,y-1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x-1,y+1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y+k][x]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x-1,y+1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x+1,y-1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y+k][x]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x+1,y-1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else ;

        }

    }

}




int ai::scelta_casella_da_colpire(){
    return coordinata_random();
}


int ai::coordinata_random(){

    return rand()%10;

}

bool ai::casella_partenza(int lunghezza, int x, int y, string direzione){

    if (direzione=="o"){

        if(x+lunghezza<11){ //controllo dimensioni board
                for(int k=0; k<lunghezza; k++){
                    if(tabella[y][x+k]=='O'){ //controllo se � gia' presente una nave
                        
                        return false; //fermo il ciclo
                        
                    };
                }
                
                
            }
        if (x+lunghezza>10){ //la nave esce dalla board
                
            return false;
        }
    }

    if (direzione=="v"){

        if(y+lunghezza<11){ //controllo dimensioni board
                for(int k=0; k<lunghezza; k++){
                    if(tabella[y+k][x]=='O'){ //controllo se � gia' presente una nave
                        
                        return false; //fermo il ciclo
                        
                    };
                }
                
                
            }
        if (y+lunghezza>10){ //la nave esce dalla board
                
            return false;
        }

    }  

    return true;  

}