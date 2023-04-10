#include "gameplay.h"

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

    //GAMEPLAY 2 GIOCATORI

    string passo_str;

    if(numero_giocatori==2){
        giocatore giocatore1(nome);
        giocatore giocatore2(nome2);

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
                giocatore2.tabella[y_tiro][x_tiro]='~';
                giocatore2.tabella_nemica[y_tiro][x_tiro]='~';

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore2.visualizzazione_nemica();
                    cout << "\nCasella scelta: " << casella << endl << endl;


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
                giocatore1.tabella[y_tiro][x_tiro]='~';
                giocatore1.tabella_nemica[y_tiro][x_tiro]='~';

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatore1.visualizzazione_nemica();
                    cout << "Casella scelta: " << casella << endl << endl;


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




    //GAMEPLAY 1 GIOCATORE CONTRO AI


    if(numero_giocatori==1){
        giocatore giocatore1(nome);
        ai giocatoreAI(nome2);


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // ******************* SOLO PER PROVA *************** DA TOGLIERE ****************

    giocatoreAI.posizionamento_navi_AI();
    giocatoreAI.visualizzazione_amica();


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!




        //POSIZIONAMENTO NAVI GIOCATORE 1

        giocatore1.posizionamento_navi_giocatore();

        //VISUALIZZAZIONE NAVI POSIZIONATE GIOCATORE 1
        titolo2();
        cout << "\nEcco qua tutte le tue navi!\n";
        giocatore1.visualizzazione_amica();

        //PASSO
        passo();

        //POSIZIONAMENTO NAVI GIOCATORE 2
        giocatoreAI.posizionamento_navi_AI();


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
            giocatoreAI.visualizzazione_nemica();

            cout << "\nInserisci casella: ";
            cin >> casella;
            trasformazione_coordinate_ridotta(casella,x_tiro,y_tiro); //trasformazione da "A7" a (x,y)

            system("cls");

            if(giocatoreAI.tabella[y_tiro][x_tiro]=='O'){
                giocatoreAI.tabella[y_tiro][x_tiro]='X';
                giocatoreAI.tabella_nemica[y_tiro][x_tiro]='X';

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
                giocatoreAI.tabella[y_tiro][x_tiro]='~';
                giocatoreAI.tabella_nemica[y_tiro][x_tiro]='~';

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                    titolo2();
                    giocatoreAI.visualizzazione_nemica();
                    cout << "\nCasella scelta: " << casella << endl << endl;


                cout << "\nACQUA: ~     :(" << endl;
            }

            check = giocatoreAI.controllo_contatore_globale();
            if(check==true){
                cout << "\n\nIL GIOCATORE " << nome2 << " HA VINTO!!!";
                giocatore1.visualizzazione_amica();
                giocatoreAI.visualizzazione_amica();
                cout << "IL GIOCATORE " << nome2 << " HA VINTO!!!";
                break;
            }

            //PASSO TURNO
            passo();






            //TURNO GIOCATORE 2

            x_tiro=giocatoreAI.scelta_x_da_colpire();
            y_tiro=giocatoreAI.scelta_y_da_colpire();
            casella = trasformazione_coordinate_ridotta_inversa(x_tiro,y_tiro);

            if(giocatore1.tabella[y_tiro][x_tiro]=='O'){
                giocatore1.tabella[y_tiro][x_tiro]='X';
                giocatore1.tabella_nemica[y_tiro][x_tiro]='X';

                giocatoreAI.set_memoria(true);
                giocatoreAI.set_colpo_precedente(x_tiro,y_tiro);

                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                titolo2();
                cout << "Casella scelta dall'avversario: " << casella << endl << endl;
                giocatore1.visualizzazione_amica();
                cout << "\nCOLPITO!  X" << endl;

                for(int i=0; i<10; i++){
                    giocatore1.nomi_navi[i].controllo_colpito_o_affondato(x_tiro,y_tiro);

                }


            }

            else{

                giocatore1.tabella[y_tiro][x_tiro]='~';
                giocatore1.tabella_nemica[y_tiro][x_tiro]='~';

                if(giocatoreAI.get_memoria()) giocatoreAI.aumenta_contatore_colpi();


                //Seguenti 3 linee inserite per bellezza per non far vedere lo stacco nel terminale
                titolo2();
                cout << "Casella scelta dall'avversario: " << casella << endl << endl;
                giocatore1.visualizzazione_amica();
                cout << "\nACQUA: ~     :(" << endl;
            }

            check = giocatore1.controllo_contatore_globale();
            if(check==true){
                cout << "\n\nIL GIOCATORE " << nome2 << " HA VINTO!!!";
                giocatore1.visualizzazione_amica();
                giocatoreAI.visualizzazione_amica();
                cout << "IL GIOCATORE " << nome2 << " HA VINTO!!!";
                break;
            }



            //PASSO TURNO
            passo();


        }


    }



}
