#include "gameplay.h"
#include <stdlib.h>
#include <time.h>

void gameplay_introduzione(int & numero_giocatori, string &nome, string &nome2){
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
}






void gameplay(int &numero_giocatori, string & nome, string & nome2){

    string passo_str;
    srand(time(NULL));     //COMPLETARE PER RANDOMIZZARE CHI COMINCIA LA PARTITA!!
    int a=rand()%2;

    //GAMEPLAY 2 GIOCATORI

    if(numero_giocatori==2){

        giocatore giocatore1;
        giocatore giocatore2;

        if(a==0){
            giocatore1.set_nome_giocatore(nome);
            giocatore2.set_nome_giocatore(nome2);
        }
        else if(a==1){
            giocatore1.set_nome_giocatore(nome2);
            giocatore2.set_nome_giocatore(nome);
        }

        cout << "Giochera' per primo: " << giocatore1.get_nome_giocatore() << endl;

        //POSIZIONAMENTO NAVI GIOCATORE 1

        giocatore1.posizionamento_navi_giocatore();

        //VISUALIZZAZIONE NAVI POSIZIONATE GIOCATORE 1
        titolo2();
        cout << "\nEcco qua tutte le tue navi!\n";
        giocatore1.visualizzazione_amica();

        //PASSO
        passo();

        //POSIZIONAMENTO NAVI GIOCATORE 2
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
            cout << "\n\n--------------- Turno di " << giocatore1.get_nome_giocatore() << " ---------------" << endl;
            cout << "Puoi scegliere che casella avversaria colpire." << endl;
            giocatore1.visualizzazione_amica();
            giocatore2.visualizzazione_nemica();

            do{
                cout << "\nInserisci casella: ";
                cin >> casella;
            }while(!giocatore1.controllo_ripetizioni(casella));

            giocatore1.aggiungi_mossa_giocata(casella);
            trasformazione_coordinate_ridotta(casella,x_tiro,y_tiro); //trasformazione da "A7" a (x,y)


            system("cls");

            if(giocatore2.get_casella_tabella(x_tiro,y_tiro)=='O'){
                giocatore2.set_casella_tabella_amica(x_tiro,y_tiro,'X');
                giocatore2.set_casella_tabella_nemica(x_tiro,y_tiro,'X');

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore2.visualizzazione_nemica();
                    cout << "\nCasella scelta: " << casella << endl << endl;


                cout << "\nCOLPITO!  X" << endl;

                for(int i=0; i<10; i++){
                    giocatore2.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro);
                }


            }


            else{
                giocatore2.set_casella_tabella_amica(x_tiro,y_tiro,'~');
                giocatore2.set_casella_tabella_nemica(x_tiro,y_tiro,'~');

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore2.visualizzazione_nemica();
                    cout << "\nCasella scelta: " << casella << endl << endl;


                cout << "\nACQUA: ~     :(" << endl;
            }

            check = giocatore2.controllo_contatore_globale();
            if(check==true){
                cout << "\n\nIL GIOCATORE " << giocatore1.get_nome_giocatore() << " HA VINTO!!!";
                giocatore1.visualizzazione_amica();
                giocatore2.visualizzazione_amica();
                cout << "IL GIOCATORE " << giocatore1.get_nome_giocatore() << " HA VINTO!!!";
                break;
            }

            //PASSO TURNO
            passo();






            //TURNO GIOCATORE 2
            titolo2();
            cout << "\n\n--------------- Turno di " << giocatore2.get_nome_giocatore() << " ---------------" << endl;
            cout << "Puoi scegliere che casella avversaria colpire." << endl;
            giocatore2.visualizzazione_amica();
            giocatore1.visualizzazione_nemica();

            do{
                cout << "\nInserisci casella: ";
                cin >> casella;
            }while(!giocatore2.controllo_ripetizioni(casella));

            giocatore2.aggiungi_mossa_giocata(casella);
            trasformazione_coordinate_ridotta(casella,x_tiro,y_tiro); //trasformazione da "A7" a (x,y)

            system("cls");

            if(giocatore1.get_casella_tabella(x_tiro,y_tiro)=='O'){
                giocatore1.set_casella_tabella_amica(x_tiro,y_tiro,'X');
                giocatore1.set_casella_tabella_nemica(x_tiro,y_tiro,'X');

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore1.visualizzazione_nemica();
                    cout << "Casella scelta: " << casella << endl << endl;


                cout << "\nCOLPITO!  X" << endl;

                for(int i=0; i<10; i++){
                    giocatore1.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro);
                }


            }


            else{
                giocatore1.set_casella_tabella_amica(x_tiro,y_tiro,'~');
                giocatore1.set_casella_tabella_nemica(x_tiro,y_tiro,'~');

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore1.visualizzazione_nemica();
                    cout << "Casella scelta: " << casella << endl << endl;


                cout << "\nACQUA: ~     :(" << endl;
            }

            check = giocatore1.controllo_contatore_globale();
            if(check==true){
                cout << "\n\nIL GIOCATORE " << giocatore2.get_nome_giocatore() << " HA VINTO!!!";
                giocatore1.visualizzazione_amica();
                giocatore2.visualizzazione_amica();
                cout << "IL GIOCATORE " << giocatore2.get_nome_giocatore() << " HA VINTO!!!";
                break;
            }

            //PASSO TURNO
            passo2();

        }

    }




    //GAMEPLAY 1 GIOCATORE CONTRO AI

    if(numero_giocatori==1){

        giocatore giocatore1(nome);
        ai giocatoreAI(nome2);



        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        // ******************* SOLO PER PROVA *************** DA TOGLIERE ****************

        //do{
        //    giocatoreAI.set_board();
        //    giocatoreAI.posizionamento_navi_AI();
        //}while(giocatoreAI.controllo_numero_navi_posizionate()!=31);

        //giocatoreAI.visualizzazione_amica();


        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




        //POSIZIONAMENTO NAVI GIOCATORE 1

        giocatore1.posizionamento_navi_giocatore();

        //VISUALIZZAZIONE NAVI POSIZIONATE GIOCATORE 1
        titolo2();
        cout << "\nEcco qua tutte le tue navi!\n";
        giocatore1.visualizzazione_amica();

        //POSIZIONAMENTO NAVI GIOCATORE 2
        do{
            giocatoreAI.set_board();
            giocatoreAI.posizionamento_navi_AI();
        }while(giocatoreAI.controllo_numero_navi_posizionate()!=31);


        if(a==0){

            //INIZIO GIOCO

            cout << "\nIL GIOCO PUO' COMINCIARE!!" << endl;

            cout << "\nGiochera' per primo: " << giocatore1.get_nome_giocatore() << "\n\nInserisci un carattere qualunque per cominciare: ";
            cin >> passo_str;
            system("cls");

            string casella;
            int x_tiro,y_tiro;
            bool check;





            //LOOP TURNI
            while(true){


                //TURNO GIOCATORE 1
                titolo2();
                cout << "\n\n--------------- Turno di " << giocatore1.get_nome_giocatore() << " ---------------" << endl;
                cout << "Puoi scegliere che casella avversaria colpire." << endl;
                giocatore1.visualizzazione_amica();
                giocatoreAI.visualizzazione_nemica();

                do{
                    cout << "\nInserisci casella: ";
                    cin >> casella;
                }while(!giocatore1.controllo_ripetizioni(casella));

                giocatore1.aggiungi_mossa_giocata(casella);
                trasformazione_coordinate_ridotta(casella,x_tiro,y_tiro); //trasformazione da "A7" a (x,y)

                system("cls");

                if(giocatoreAI.get_casella_tabella(x_tiro,y_tiro)=='O'){
                    giocatoreAI.set_casella_tabella_amica(x_tiro,y_tiro,'X');
                    giocatoreAI.set_casella_tabella_nemica(x_tiro,y_tiro,'X');

                    //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                        titolo2();
                        giocatoreAI.visualizzazione_nemica();
                        cout << "\nCasella scelta: " << casella << endl << endl;

                    cout << "\nCOLPITO!  X" << endl;

                    for(int i=0; i<10; i++){
                        giocatoreAI.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro); //Controllo quale nave e' stata colpita e agisco di conseguenza
                    }

                }


                else{
                    giocatoreAI.set_casella_tabella_amica(x_tiro,y_tiro,'~');
                    giocatoreAI.set_casella_tabella_nemica(x_tiro,y_tiro,'~');

                    //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                        titolo2();
                        giocatoreAI.visualizzazione_nemica();
                        cout << "\nCasella scelta: " << casella << endl << endl;


                    cout << "\nACQUA: ~     :(" << endl;
                }

                check = giocatoreAI.controllo_contatore_globale();
                if(check==true){
                    cout << "\n\nIL GIOCATORE " << giocatore1.get_nome_giocatore() << " HA VINTO!!!";
                    giocatore1.visualizzazione_amica();
                    giocatoreAI.visualizzazione_amica();
                    cout << "\nIL GIOCATORE " << giocatore1.get_nome_giocatore() << " HA VINTO!!!";
                    break;
                }

                //PASSO TURNO
                passo();






                //TURNO GIOCATORE 2: AI


                do{
                    x_tiro=giocatoreAI.scelta_x_da_colpire();
                    y_tiro=giocatoreAI.scelta_y_da_colpire();
                    casella = trasformazione_coordinate_ridotta_inversa(x_tiro,y_tiro);
                }while(!giocatoreAI.controllo_ripetizioni(casella));

                giocatoreAI.aggiungi_mossa_giocata(casella);

                if(giocatore1.get_casella_tabella(x_tiro,y_tiro)=='O'){
                    giocatore1.set_casella_tabella_amica(x_tiro,y_tiro,'X');
                    giocatore1.set_casella_tabella_nemica(x_tiro,y_tiro,'X');

                    giocatoreAI.set_memoria(true);
                    giocatoreAI.set_colpo_precedente(x_tiro,y_tiro);

                    //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore1.visualizzazione_amica();
                    cout << "\nCasella scelta dall'avversario: " << casella << endl << endl;
                    cout << "\nCOLPITO!  X" << endl;

                    for(int i=0; i<10; i++){
                        giocatore1.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro);

                    }


                }

                else{
                    giocatore1.set_casella_tabella_amica(x_tiro,y_tiro,'~');
                    giocatore1.set_casella_tabella_nemica(x_tiro,y_tiro,'~');

                    if(giocatoreAI.get_memoria()) giocatoreAI.aumenta_contatore_colpi();


                    //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore1.visualizzazione_amica();
                    cout << "Casella scelta dall'avversario: " << casella << endl;
                    cout << "\nACQUA: ~     :(" << endl;
                }

                check = giocatore1.controllo_contatore_globale();
                if(check==true){
                    cout << "\n\nIL GIOCATORE " << giocatoreAI.get_nome_giocatore() << " HA VINTO!!!";
                    giocatore1.visualizzazione_amica();
                    giocatoreAI.visualizzazione_amica();
                    cout << "IL GIOCATORE " << giocatoreAI.get_nome_giocatore() << " HA VINTO!!!";
                    break;
                }


                //PASSO TURNO
                passo2();


            }


        }


        else if (a==1){

            //INIZIO GIOCO

            cout << "\nIL GIOCO PUO' COMINCIARE!!" << endl;

            cout << "\nGiochera' per primo l' AI:\n\nInserisci un carattere qualunque per cominciare: ";
            cin >> passo_str;
            system("cls");

            string casella;
            int x_tiro,y_tiro;
            bool check;



            //LOOP TURNI
            while(true){

                //TURNO GIOCATORE 2: AI

                do{
                    x_tiro=giocatoreAI.scelta_x_da_colpire();
                    y_tiro=giocatoreAI.scelta_y_da_colpire();
                    casella = trasformazione_coordinate_ridotta_inversa(x_tiro,y_tiro);
                }while(!giocatoreAI.controllo_ripetizioni(casella));

                giocatoreAI.aggiungi_mossa_giocata(casella);


                if(giocatore1.get_casella_tabella(x_tiro,y_tiro)=='O'){
                    giocatore1.set_casella_tabella_amica(x_tiro,y_tiro,'X');
                    giocatore1.set_casella_tabella_nemica(x_tiro,y_tiro,'X');

                    giocatoreAI.set_memoria(true);
                    giocatoreAI.set_colpo_precedente(x_tiro,y_tiro);

                    //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore1.visualizzazione_amica();
                    cout << "\nCasella scelta dall'avversario: " << casella << endl;
                    cout << "\nCOLPITO!  X" << endl;

                    for(int i=0; i<10; i++){
                        giocatore1.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro);

                    }


                }

                else{
                    giocatore1.set_casella_tabella_amica(x_tiro,y_tiro,'~');
                    giocatore1.set_casella_tabella_nemica(x_tiro,y_tiro,'~');

                    if(giocatoreAI.get_memoria()) giocatoreAI.aumenta_contatore_colpi();


                    //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore1.visualizzazione_amica();
                    cout << "\nCasella scelta dall'avversario: " << casella << endl;
                    cout << "\nACQUA: ~     :(" << endl;
                }

                check = giocatore1.controllo_contatore_globale();
                if(check==true){
                    cout << "\n\nIL GIOCATORE " << giocatoreAI.get_nome_giocatore() << " HA VINTO!!!";
                    giocatore1.visualizzazione_amica();
                    giocatoreAI.visualizzazione_amica();
                    cout << "\nIL GIOCATORE " << giocatoreAI.get_nome_giocatore() << " HA VINTO!!!";
                    break;
                }


                //PASSO TURNO
                passo2();

                //TURNO GIOCATORE 1
                titolo2();
                cout << "\n\n--------------- Turno di " << giocatore1.get_nome_giocatore() << " ---------------" << endl;
                cout << "Puoi scegliere che casella avversaria colpire." << endl;
                giocatore1.visualizzazione_amica();
                giocatoreAI.visualizzazione_nemica();



                do{
                    cout << "\nInserisci casella: ";
                    cin >> casella;
                }while(!giocatore1.controllo_ripetizioni(casella));

                giocatore1.aggiungi_mossa_giocata(casella);
                trasformazione_coordinate_ridotta(casella,x_tiro,y_tiro); //trasformazione da "A7" a (x,y)

                system("cls");

                if(giocatoreAI.get_casella_tabella(x_tiro,y_tiro)=='O'){
                    giocatoreAI.set_casella_tabella_amica(x_tiro,y_tiro,'X');
                    giocatoreAI.set_casella_tabella_nemica(x_tiro,y_tiro,'X');

                    //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                        titolo2();
                        giocatoreAI.visualizzazione_nemica();
                        cout << "\nCasella scelta: " << casella << endl;

                    cout << "\nCOLPITO!  X" << endl;

                    for(int i=0; i<10; i++){
                        giocatoreAI.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro); //Controllo quale nave e' stata colpita e agisco di conseguenza
                    }

                }


                else{
                    giocatoreAI.set_casella_tabella_amica(x_tiro,y_tiro,'~');
                    giocatoreAI.set_casella_tabella_nemica(x_tiro,y_tiro,'~');

                    //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                        titolo2();
                        giocatoreAI.visualizzazione_nemica();
                        cout << "\nCasella scelta: " << casella << endl;


                    cout << "\nACQUA: ~     :(" << endl;
                }

                check = giocatoreAI.controllo_contatore_globale();
                if(check==true){
                    cout << "\n\nIL GIOCATORE " << giocatore1.get_nome_giocatore() << " HA VINTO!!!";
                    giocatore1.visualizzazione_amica();
                    giocatoreAI.visualizzazione_amica();
                    cout << "IL GIOCATORE " << giocatore1.get_nome_giocatore() << " HA VINTO!!!";
                    break;
                }

                //PASSO TURNO
                passo();



            }


        }


    }



}


