#include "ai.h"


ai::ai():board(){}

ai::ai(string nome):board(nome){}


void ai::posizionamento_navi_AI(){

    // SETTO LA LUNGHEZZA DELLE NAVI (il costruttore mi dava problemi)
    nomi_navi[0].set_lunghezza(6);
    nomi_navi[1].set_lunghezza(4);
    nomi_navi[2].set_lunghezza(4);
    nomi_navi[3].set_lunghezza(3);
    nomi_navi[4].set_lunghezza(3);
    nomi_navi[5].set_lunghezza(3);
    nomi_navi[6].set_lunghezza(2);
    nomi_navi[7].set_lunghezza(2);
    nomi_navi[8].set_lunghezza(2);
    nomi_navi[9].set_lunghezza(2);

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
        if(rand()%2==0) direzione="O";
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
                    tabella[y+1][x+1+k]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x+1,y+1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x-1,y-1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y-1][x-1+k]='O';   
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x-1,y-1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x-1,y+1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y+1][x-1+k]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x-1,y+1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x+1,y-1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y-1][x+1+k]='O';
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
                    tabella[y+1+k][x+1]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x+1,y+1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x-1,y-1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y-1+k][x-1]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x-1,y-1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x-1,y+1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y+1+k][x-1]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x-1,y+1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else if(casella_partenza(lunghezza,x+1,y-1,direzione)){
                for(int k=0; k<lunghezza; k++){
                    tabella[y-1+k][x+1]='O';
                }
                posizione=trasformazione_coordinate_ridotta_inversa(x+1,y-1).append(direzione);
                nomi_navi[i].set_posizione(posizione);
                i++;
            }
            else ;

        }

    }

}




int ai::scelta_x_da_colpire(){
    if(!memoria) return coordinata_random();

    else{
        spostamenti[0]=1;
        spostamenti[1]=-1;
        direzione_colpo=rand()%2;
        if(direzione_colpo==0){

            if(colpo_precedente[0]==0) return 1;
            else if(colpo_precedente[0]==9) return 8;
            else return colpo_precedente[0]+spostamenti[rand()%2];
        }   
        else return colpo_precedente[0];
    
    }
    
    }


int ai::scelta_y_da_colpire(){

    if(!memoria) return coordinata_random();

    else{
        spostamenti[0]=1;
        spostamenti[1]=-1;
        if(direzione_colpo==1){

            if(colpo_precedente[1]==0) return 1;
            else if(colpo_precedente[1]==9) return 8;
            else return colpo_precedente[1]+spostamenti[rand()%2];
        }   
        else return colpo_precedente[1];
    
    }
}


int ai::coordinata_random(){

    return rand()%10;

}

bool ai::casella_partenza(int lunghezza, int x, int y, string direzione){

    if (direzione=="O"){

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

    if (direzione=="V"){

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

void ai::set_memoria(bool x){
    memoria=x;
}

void ai::set_colpo_precedente(int x, int y){
    colpo_precedente[0]=x;
    colpo_precedente[1]=y;
}

bool ai::get_memoria(){
    return memoria;
}

void ai::aumenta_contatore_colpi(){
    if(contatore_colpi<4) contatore_colpi+=1;
    else {
        contatore_colpi=0;
        memoria=false;
    }
}

bool ai::controllo_ripetizioni(string casella){
    int lunghezza=mosse_precedenti.size();
    for(int i=0;i<lunghezza;i++){
        if (mosse_precedenti[i]==casella) return false;
    }
    return true;
}

void ai::aggiungi_mossa_giocata(string casella){
    mosse_precedenti.push_back(casella);
}