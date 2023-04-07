#include "giocatore.h"

giocatore::giocatore():board(){}

giocatore::giocatore(string nome):board(nome){}


void giocatore::posizionamento_navi_giocatore(){

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
    int controllo_compenetrazione_e_dimensioni = 0;

    for(int i=0; i<10; i++){

        titolo2();
        cout << "\nQui " << nome_giocatore << " puo' posizionare le proprie navi: " << endl;
        cout << "\nPer posizionare le navi devi dirmi le coordinate della casella piu' in alto a sinistra in cui vuoi che si trovi la nave\nE poi devi dirmi se vuoi posizionarla in orizzontale o verticale\n";
        cout << "Ad esempio per una nave posizionata in orizzontale a partire dalla casella B2 dovrai digitare B2O, in verticale B2V.\n";

        visualizzazione_amica();

        if(controllo_compenetrazione_e_dimensioni==1){
            cout << "\nHai inserito una casella non adatta, attento a non sovrapporre altre tue navi e a non uscire dal campo di battaglia!\n"; //faccio un cout di avviso
        }
        cout << "\nPosiziona un " << nomi_navi[i].get_name() << " di lunghezza " << nomi_navi[i].get_lunghezza() << ": ";
        cin >> temporanea;
        nomi_navi[i].set_posizione(temporanea);

        system("cls");


        //QUI DISEGNAMO SUL TABELLONE LE NAVI

        x=nomi_navi[i].get_x();
        y=nomi_navi[i].get_y();
        orientazione=nomi_navi[i].get_orientazione();
        lunghezza=nomi_navi[i].get_lunghezza();

        controllo_compenetrazione_e_dimensioni = 0;

        if(orientazione=='O'){ //Caso orizzontale

            if(x+lunghezza<11){ //controllo dimensioni board
                for(int k=0; k<lunghezza; k++){
                    if(tabella[y][x+k]=='O'){ //controllo se è gia' presente una nave
                        i--; //se e' presente, abbasso l'indice di 1
                        controllo_compenetrazione_e_dimensioni = 1; //compenetrazione
                        break; //fermo il ciclo for
                    };
                }
                if(controllo_compenetrazione_e_dimensioni==0){
                    for(int k=0; k<lunghezza; k++){
                    tabella[y][x+k]='O'; //indicatore presenza nave "O"
                    }
                }
            }
            else if (x+lunghezza>10){ //la nave esce dalla board
                i--;
                controllo_compenetrazione_e_dimensioni = 1;
            }
        }


        else if(orientazione=='V'){ //Caso verticale

            if(y+lunghezza<11){ //controllo dimensioni board
                for(int k=0; k<lunghezza; k++){
                    if(tabella[y+k][x]=='O'){ //controllo se è gia' presente una nave
                        i--; //se e' presente, abbasso l'indice di 1
                        controllo_compenetrazione_e_dimensioni = 1; //compenetrazione
                        break; //fermo il ciclo for
                    };
                }
                if(controllo_compenetrazione_e_dimensioni==0){
                    for(int k=0; k<lunghezza; k++){
                    tabella[y+k][x]='O'; //indicatore presenza nave "O"
                    }
                }
            }
            else if (y+lunghezza>10){
                i--;
                controllo_compenetrazione_e_dimensioni = 1;
            }
        }

    }
}
