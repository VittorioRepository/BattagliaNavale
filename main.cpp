#include <iostream>

#include "nave.h"
#include "board.h"

#include <string>

#include "funzioni.h"

using namespace std;

int main()
{
    titolo();

    string nome;
    string nome2;
    int numero_giocatori;

    do{
        cout << "Modalita' Giocatore Singolo (inserisci 1) o 2 Giocatori (inserisci 2)? ";
        cin >> numero_giocatori;
        if(numero_giocatori!=1 or numero_giocatori!=2){
            cout << "Hai inserito un valore non valido!\n";
        }
    }while(numero_giocatori!=1 or numero_giocatori!=2);

    if (numero_giocatori==1){
        system("cls");
        titolo();
        cout << "\nHai scelto: Modalita' Giocatore Singolo\n";
        cout << "Nome Giocatore: ";
        getline(cin, nome);
    }
    else {
        system("cls");
        titolo();
        cout << "\nHai scelto: Modalita' 2 Giocatori\n";
        cout << "Nome Giocatore 1: ";
        cin >> nome;
        cout << "Nome Giocatore 2: ";
        cin >> nome2;

    }



    system("cls");
    titolo();

    if(numero_giocatori==1) cout << "\n---------------------------- CAPITANO FLOTTA NEMICA ----------------------------";
    if(numero_giocatori==2) cout << "\n----------------------------- CAPITANERIA DI PORTO -----------------------------";

    if(numero_giocatori==1){
        cout << "\nTu devi essere " << nome << ". Preparati a perdere tutte le tue navi!!" << endl;
        cout << "\nLe flotte che avremo a disposizione sono composte da:" << endl;
    }

    if(numero_giocatori==2){
        cout << "\n\nVoi dovete essere " << nome << " e " << nome2 <<". Preparatevi a battervi in mare aperto!!" << endl;
        cout << "\nLe flotte che avrete a disposizione sono composte da:" << endl;
    }
    cout << "   4 cacciatorpedinieri di lunghezza 2" << endl;
    cout << "   3 sottomarini, di lunghezza 3" << endl;
    cout << "   2 incrociatori, di lunghezza 4" << endl;
    cout << "   1 corazzata, di lunghezza 6" << endl;

    if(numero_giocatori==1){
        cout << "\nDecidi dove posizionare la tue navi e riferiscilo al tuo computer di bordo. \nD'ora in poi dialogherai con lui. \nChe vinca il migliore!!" << endl;
    }
    if(numero_giocatori==2){
        cout << "\nDecidete dove posizionare la vostre navi e riferitelo al vostro computer di bordo. \nD'ora in poi dialogherete con lui. \nChe vinca il migliore!!" << endl;

    }

    cout << "\nInserisci un carattere qualunque per cominciare: ";
    string passo_str;
    cin >> passo_str;
    system("cls");




    if(numero_giocatori==2){
        board giocatore1(nome);
        board giocatore2(nome2);

        //POSIZIONAMENTO GIOCATORE 1

        giocatore1.posizionamento_navi_giocatore();

        //VISUALIZZAZIONE NAVI POSIZIONATE GIOCATORE 2
        titolo2();
        cout << "\nEcco qua tutte le tue navi!\n";
        giocatore1.visualizzazione_amica();

        //PASSO
        passo();

        //POSIZIONAMENTO GIOCATORE 2
        giocatore2.posizionamento_navi_giocatore();
        system("cls");

        //VISUALIZZAZIONE NAVI POSIZIONATE GIOCATORE 2
        titolo2();
        cout << "\nEcco qua tutte le tue navi!\n";
        giocatore2.visualizzazione_amica();

        //PASSO
        passo();

        //INIZIO GIOCO

        cout << "IL GIOCO PUO' COMINCIARE!!" << endl;

        cout << "\nInserisci un carattere qualunque per cominciare: ";
        cin >> passo_str;
        system("cls");

        string casella;
        int x_tiro,y_tiro;
        bool check;





        //LOOP TURNI
        while(true){




            //TURNO GIOCATORE 1
            titolo2();
            cout << "\n\n--------------- Turno di " << nome << " ---------------" << endl;
            cout << "Puoi scegliere che casella avversaria colpire." << endl;
            giocatore1.visualizzazione_amica();
            giocatore2.visualizzazione_nemica();

            cout << "\nInserisci casella: ";
            cin >> casella;
            trasformazione_coordinate_ridotta(casella,x_tiro,y_tiro); //trasformazione da "A7" a (x,y)

            system("cls");

            if(giocatore2.tabella[y_tiro][x_tiro]=='O'){
                giocatore2.tabella[y_tiro][x_tiro]='X';
                giocatore2.tabella_nemica[y_tiro][x_tiro]='X';
                for(int i=0; i<10; i++){
                    giocatore2.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro);
                }

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    cout << "\nCasella scelta: " << casella << endl << endl;
                    giocatore2.visualizzazione_nemica();

                cout << "\nCOLPITO!  X" << endl;
            }


            else{
                giocatore2.tabella[y_tiro][x_tiro]='~';
                giocatore2.tabella_nemica[y_tiro][x_tiro]='~';

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    cout << "\nCasella scelta: " << casella << endl << endl;
                    giocatore2.visualizzazione_nemica();

                cout << "\nACQUA: ~     :(" << endl;
            }

            check = giocatore2.controllo_contatore_globale();
            if(check==true){
                cout << "\n\nIL GIOCATORE " << nome2 << " HA VINTO!!!";
                giocatore1.visualizzazione_amica();
                giocatore2.visualizzazione_amica();
                cout << "IL GIOCATORE " << nome2 << " HA VINTO!!!";
                break;
            }

            //PASSO TURNO
            passo();






            //TURNO GIOCATORE 2
            titolo2();
            cout << "\n\n--------------- Turno di " << nome2 << " ---------------" << endl;
            cout << "Puoi scegliere che casella avversaria colpire." << endl;
            giocatore2.visualizzazione_amica();
            giocatore1.visualizzazione_nemica();
            cout << "\nInserisci casella: ";
            cin >> casella;
            trasformazione_coordinate_ridotta(casella,x_tiro,y_tiro);

            system("cls");

            if(giocatore1.tabella[y_tiro][x_tiro]=='O'){
                giocatore1.tabella[y_tiro][x_tiro]='X';
                giocatore1.tabella_nemica[y_tiro][x_tiro]='X';
                for(int i=0; i<10; i++){
                    giocatore1.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro);
                }

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    cout << "Casella scelta: " << casella << endl << endl;
                    giocatore1.visualizzazione_nemica();

                cout << "\nCOLPITO!  X" << endl;
            }


            else{
                giocatore1.tabella[y_tiro][x_tiro]='~';
                giocatore1.tabella_nemica[y_tiro][x_tiro]='~';

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    cout << "Casella scelta: " << casella << endl << endl;
                    giocatore1.visualizzazione_nemica();

                cout << "\nACQUA: ~     :(" << endl;
            }

            check = giocatore1.controllo_contatore_globale();
            if(check==true){
                cout << "\n\nIL GIOCATORE " << nome2 << " HA VINTO!!!";
                giocatore1.visualizzazione_amica();
                giocatore2.visualizzazione_amica();
                cout << "IL GIOCATORE " << nome2 << " HA VINTO!!!";
                break;
            }

            //PASSO TURNO
            passo();


        }


    }






    return 0;
}
