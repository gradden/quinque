//
//  main.cpp
//  Quinque
//
//  Created by Tóth Gergő on 2019. 04. 26..
//  Copyright © 2019. Tóth Gergő. All rights reserved.
//
//  --Készítette: Tóth Gergő, Mérnökinformatika - SZE
//  --Neptun kód: IRIE5X
//  --Email cím: tgery3@gmail.com
//

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))

using namespace std;

struct lap{
    short *jel = new short[4];
    bool elet = false;
    bool mozgatva = false;
};


float jatekvege = 0;
float playersorszam = 0;
int ossz = 99;
int player1sim = 18;
int player2sim = 18;
int fuggpontszam1jobb = 0;
int fuggpontszam1bal = 0;
int fuggpontszam2jobb = 0;
int fuggpontszam2bal = 0;
int vizpontszam1fent = 0;
int vizpontszam1lent = 0;
int vizpontszam2fent = 0;
int vizpontszam2lent = 0;
int atlopont1_1 = 0;
int atlopont2_1 = 0;

//Ez vizsgálja a játék jelenlegi állapotát, és állítja le, ha valaki nyert vagy döntetlen lett.
void vizsgalat(lap* lapvaltozo[]){
    //Döntetlen-e?
    if(player1sim == 0 && player2sim == 0){
        jatekvege = 1;
        cout << "Mindket jatekos jelolesi szama elfogyott, ezaltal a jatek dontetlen lett!";
    }
    
    //Függőleges lap és szimbólumvizsgálás PLAYER 1NEK!!!!!!
    for(int i=0; i<=99; i++){
        for (int a=0; a<=99; a++) {
            //PLAYER1
            //Függőleges bal
            if(*&lapvaltozo[a][i].jel[0] == 1){
                fuggpontszam1bal +=1;
                if(fuggpontszam1bal >= 5){
                    cout << "Nyert az 1. jatekos, fuggoleges szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                fuggpontszam1bal = 0;
            }
            if(*&lapvaltozo[a][i].jel[2] == 1){
                fuggpontszam1bal +=1;
                if(fuggpontszam1bal >= 5){
                    cout << "Nyert az 1. jatekos, fuggoleges szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                fuggpontszam1bal = 0;
            }
            
            //Függőleges jobb
            if(*&lapvaltozo[a][i].jel[1] == 1){
                fuggpontszam1jobb +=1;
                if(fuggpontszam1jobb >= 5){
                    cout << "Nyert az 1. jatekos, fuggoleges szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                fuggpontszam1jobb = 0;
            }
            if(*&lapvaltozo[a][i].jel[3] == 1){
                fuggpontszam1jobb +=1;
                if(fuggpontszam1jobb >= 5){
                    cout << "Nyert az 1. jatekos, fuggoleges szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                fuggpontszam1jobb = 0;
            }
            
            //Vízszintes fent
            if(*&lapvaltozo[i][a].jel[0] == 1){
                vizpontszam1fent +=1;
                if(vizpontszam1fent >= 5){
                    cout << "Nyert az 1. jatekos, vizszintes szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                vizpontszam1fent = 0;
            }
            if(*&lapvaltozo[i][a].jel[1] == 1){
                vizpontszam1fent +=1;
                if(vizpontszam1fent >= 5){
                    cout << "Nyert az 1. jatekos, vizszintes szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                vizpontszam1fent = 0;
            }
            
            //Vízszintes lent
            if(*&lapvaltozo[i][a].jel[2] == 1){
                vizpontszam1lent +=1;
                if(vizpontszam1lent >= 5){
                    cout << "Nyert az 1. jatekos, vizszintes szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                vizpontszam1lent = 0;
            }
            if(*&lapvaltozo[i][a].jel[3] == 1){
                vizpontszam1lent +=1;
                if(vizpontszam1lent >= 5){
                    cout << "Nyert az 1. jatekos, vizszintes szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                vizpontszam1lent = 0;
            }
        }
    }
    
    //Átlós vizsgálat
    int pos1;
    int pos1ures = false;
    for(int a = 0; a<=99; a++){
        for(int i =0; i<=99; i++) {
            if(*&lapvaltozo[a][i].jel[0] == 1 || *&lapvaltozo[a][i].jel[3] == 1 ){
                if(pos1ures == false){
                    atlopont1_1 = 0;
                }
                pos1 = i;
                pos1ures = false;
                
                //cout << "pos: "<< pos1 << "\n";
                for(int j=0; j<=99; j++){
                    if((j+pos1) < 99 && (j+pos1) < 99){
                        if(*&lapvaltozo[(j+pos1)][(j+pos1)].jel[0] == 1) {
                            atlopont1_1 +=1;
                            if(atlopont1_1 == 5){
                                if(j==pos1){
                                    cout << "Nyert az 1. jatekos!";
                                }
                                jatekvege = 1;
                            }
                        }else{
                            atlopont1_1 = 0;
                        }
                        if(*&lapvaltozo[(j+pos1)][(j+pos1)].jel[3] == 1) {
                            atlopont1_1 +=1;
                            if(atlopont1_1 == 5){
                                if(j==pos1){
                                    cout << "Nyert az 1. jatekos!";
                                }
                                jatekvege = 1;
                            }
                        }else{
                            atlopont1_1 = 0;
                        }
                    }
                }
                
            }
        }
    }
    
    //Átlós vizsgálat
    for(int a = 0; a<=99; a++){
        for(int i =0; i<=99; i++) {
            if(*&lapvaltozo[a][i].jel[1] == 1 || *&lapvaltozo[a][i].jel[2] == 1 ){
                if(pos1ures == false){
                    atlopont1_1 = 0;
                }
                pos1 = i;
                pos1ures = false;
                
                //cout << "pos: "<< pos1 << "\n";
                for(int j=0; j<=99; j++){
                    if((pos1-j) >=0){
                        if(*&lapvaltozo[j][(pos1-j)].jel[1] == 1) {
                            atlopont1_1 +=1;
                            if(atlopont1_1 == 5){
                                if(j==pos1){
                                    cout << "Nyert az 1. jatekos!";
                                }
                                jatekvege = 1;
                            }
                        }else{
                            atlopont1_1 = 0;
                        }
                        if(*&lapvaltozo[j][(pos1-j)].jel[2] == 1) {
                            atlopont1_1 +=1;
                            if(atlopont1_1 == 5){
                                if(j==pos1){
                                    cout << "Nyert az 1. jatekos!";
                                }
                                jatekvege = 1;
                            }
                        }else{
                            atlopont1_1 = 0;
                        }
                    }
                }
                
            }
        }
    }
    
    
    //Függőleges lap és szimbólumvizsgálás PLAYER2NEK!!!!!!
    for(int i=0; i<=99; i++){
        for (int a=0; a<=99; a++) {
            //PLAYER1
            //Függőleges bal
            if(*&lapvaltozo[a][i].jel[0] == 2){
                fuggpontszam2bal +=1;
                if(fuggpontszam2bal >= 5){
                    cout << "Nyert a 2. jatekos, fuggoleges szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                fuggpontszam2bal = 0;
            }
            if(*&lapvaltozo[a][i].jel[2] == 2){
                fuggpontszam2bal +=1;
                if(fuggpontszam2bal >= 5){
                    cout << "Nyert a 2. jatekos, fuggoleges szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                fuggpontszam2bal = 0;
            }
            
            //Függőleges jobb
            if(*&lapvaltozo[a][i].jel[1] == 2){
                fuggpontszam2jobb +=1;
                if(fuggpontszam2jobb >= 5){
                    cout << "Nyert a 2. jatekos, fuggoleges szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                fuggpontszam2jobb = 0;
            }
            if(*&lapvaltozo[a][i].jel[3] == 2){
                fuggpontszam2jobb +=1;
                if(fuggpontszam2jobb >= 5){
                    cout << "Nyert a 2. jatekos, fuggoleges szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                fuggpontszam2jobb = 0;
            }
            
            //Vízszintes fent
            if(*&lapvaltozo[i][a].jel[0] == 2){
                vizpontszam2fent +=1;
                if(vizpontszam2fent >= 5){
                    cout << "Nyert a 2. jatekos, vizszintes szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                vizpontszam2fent = 0;
            }
            if(*&lapvaltozo[i][a].jel[1] == 2){
                vizpontszam2fent +=1;
                if(vizpontszam2fent >= 5){
                    cout << "Nyert a 2. jatekos, vizszintes szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                vizpontszam2fent = 0;
            }
            
            //Vízszintes lent
            if(*&lapvaltozo[i][a].jel[2] == 2){
                vizpontszam2lent +=1;
                if(vizpontszam2lent >= 5){
                    cout << "Nyert a 2. jatekos, vizszintes szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                vizpontszam2lent = 0;
            }
            if(*&lapvaltozo[i][a].jel[3] == 2){
                vizpontszam2lent +=1;
                if(vizpontszam2lent >= 5){
                    cout << "Nyert a 2. jatekos, vizszintes szimbolumkirakassal!\n";
                    jatekvege = 1;
                }
            }else{
                vizpontszam2lent = 0;
            }
        }
    }
    
    //Átlós vizsgálat
    for(int a = 0; a<=99; a++){
        for(int i =0; i<=99; i++) {
            if(*&lapvaltozo[a][i].jel[0] == 2 || *&lapvaltozo[a][i].jel[3] == 2 ){
                if(pos1ures == false){
                    atlopont2_1 = 0;
                }
                pos1 = i;
                pos1ures = false;
                
                //cout << "pos: "<< pos1 << "\n";
                for(int j=0; j<=99; j++){
                    if((j+pos1) < 99 && (j+pos1) < 99){
                        if(*&lapvaltozo[(j+pos1)][(j+pos1)].jel[0] == 2) {
                            atlopont2_1 +=1;
                            if(atlopont2_1 == 5){
                                if(j==pos1){
                                    cout << "Nyert a 2. jatekos!";
                                }
                                jatekvege = 1;
                            }
                        }else{
                            atlopont2_1 = 0;
                        }
                        if(*&lapvaltozo[(j+pos1)][(j+pos1)].jel[3] == 2) {
                            atlopont2_1 +=1;
                            if(atlopont2_1 == 5){
                                if(j==pos1){
                                    cout << "Nyert a 2. jatekos!";
                                }
                                jatekvege = 1;
                            }
                        }else{
                            atlopont2_1 = 0;
                        }
                    }
                }
                
            }
        }
    }
    
    //Átlós vizsgálat
    for(int a = 0; a<=99; a++){
        for(int i =0; i<=99; i++) {
            if(*&lapvaltozo[a][i].jel[1] == 2 || *&lapvaltozo[a][i].jel[2] == 2 ){
                if(pos1ures == false){
                    atlopont2_1 = 0;
                }
                pos1 = i;
                pos1ures = false;
                
                //cout << "pos: "<< pos1 << "\n";
                for(int j=0; j<=99; j++){
                    if((pos1-j) >=0){
                        if(*&lapvaltozo[j][(pos1-j)].jel[1] == 2) {
                            atlopont2_1 +=1;
                            if(atlopont2_1 == 5){
                                if(j==pos1){
                                    cout << "Nyert a 2. jatekos!";
                                }
                                jatekvege = 1;
                            }
                        }else{
                            atlopont2_1 = 0;
                        }
                        if(*&lapvaltozo[j][(pos1-j)].jel[2] == 2) {
                            atlopont2_1 +=1;
                            if(atlopont2_1 == 5){
                                if(j==pos1){
                                    cout << "Nyert a 2. jatekos!";
                                }
                                jatekvege = 1;
                            }
                        }else{
                            atlopont2_1 = 0;
                        }
                    }
                }
                
            }
        }
    }
    
    
}


int nagyobb(int a, int b){
    int nagy = 0;
    if(a > b){
        nagy = a;
    }
    if(b > a){
        nagy = b;
    }
    if(b == a){
        nagy = a;
    }
    return nagy;
}

void dinamikusnovekves(lap* lapvaltozo[], lap* lapcache[], int ujmeret){
    for(size_t s = 0; s<=ossz; s++){
        for(size_t i = 0; i<=ossz; i++){
            *&lapcache[s][i].elet = *&lapvaltozo[s][i].elet;
            for(int a=0; a<=3; a++){
                *&lapcache[s][i].jel[a] = *&lapvaltozo[s][i].jel[a];
            }
        }
    }
    for(int i=0; i<=ossz; i++){
        delete [] lapvaltozo[i];
    }
    delete [] lapvaltozo;
    
    lapvaltozo = new lap*[ujmeret];
    for(int i=0; i<ujmeret; i++){
        lapvaltozo[i] = new lap[ujmeret];
    }
    
    for(size_t s = 0; s<=ossz; s++){
        for(size_t i = 0; i<=ossz; i++){
            *&lapcache[s][i].elet = *&lapvaltozo[s][i].elet;
            for(int a=0; a<=3; a++){
                *&lapvaltozo[s][i].jel[a] = *&lapcache[s][i].jel[a];
            }
        }
    }
    
    for(int i=0; i<=ossz; i++){
        delete [] lapcache[i];
    }
    delete [] lapcache;
    
    lapcache = new lap*[ujmeret];
    for(int i=0; i<ujmeret; i++){
        lapcache[i] = new lap[ujmeret];
    }
    
    ossz = ujmeret;
    
}

void kartyamegjelenites(lap* lapvaltozo[], int sor, int oszlop){
    cout << " __\n";
    cout << "|";
    for(int i=0; i<=1; i++){
        if(lapvaltozo[sor][oszlop].jel[i] == 0){
            cout << i;
        }else{
            if(lapvaltozo[sor][oszlop].jel[i] == 1){
                cout << "X";
            }
            if(lapvaltozo[sor][oszlop].jel[i] == 2){
                cout << "O";
            }
        }
    }
    cout << "|";
    cout << endl;
    cout << "|";
    for(int a = 2; a<=3; a++){
        if(lapvaltozo[sor][oszlop].jel[a] == 0){
            cout << a;
        }else{
            if(lapvaltozo[sor][oszlop].jel[a] == 1){
                cout << "X";
            }
            if(lapvaltozo[sor][oszlop].jel[a] == 2){
                cout << "O";
            }
        }
    }
    cout << "|";
    cout << endl;
    cout << " --\n";
    cout << endl;
    
}

void koordinatalap(lap* lapvaltozo[]){
    cout << "A lapok az alabbi helyen helyezkednek el (X = kartyalap)\n";
    int eletbenlap = 0;
    int maxpos = 0;
    for(size_t s = 0; s<=99; s++){
        for(size_t i = 0; i<=99; i++){
            if(*&lapvaltozo[s][i].elet == true){
                if(i>s){
                    eletbenlap = (int)i+1;
                }
                if(s>i){
                    eletbenlap = (int)s+1;
                }
                if(s==i){
                    eletbenlap = (int)s+1;
                }
                if(maxpos <= eletbenlap){
                    maxpos = eletbenlap;
                }
            }
        }
    }
    
    for(size_t i=0; i<maxpos+2; i++){
        cout << i << ".\t";
        for(size_t a=0; a<maxpos+2; a++){
            if(*&lapvaltozo[i][a].elet == true){
                cout << "X ";
            }else{
                cout << "- ";
            }
        }
        cout << "\n";
    }
}


void lapmegtekintes(lap* lapvaltozo[]){
    string igennem1;
    int simbesor1;
    int simbeoszlop1;
    do{
        cout << "Megtekintened valamelyik lapot? Igen (I) vagy Nem (N): ";
        cin >> igennem1;
        std::transform(igennem1.begin(), igennem1.end(), igennem1.begin(), ::toupper);
        if(igennem1 == "I"){
            cout << "Melyik kartyalapra vagy kivancsi?";
            cout << " (A SZAMOZAS 0-TOL INDULNAK!) \n";
            cout << "Sor: ";
            cin >> simbesor1;
            cout << "Oszlop:";
            cin >> simbeoszlop1;
            if((simbesor1 < 100 || simbeoszlop1 < 100) && (simbesor1 >= 0 || simbeoszlop1 >= 0)){
                if(*&lapvaltozo[simbesor1][simbeoszlop1].elet == true) {
                    kartyamegjelenites(*&lapvaltozo, simbesor1, simbeoszlop1);
                }else{
                    cout << "Sajnos ez a lap nem letezik!\n";
                }
            }else{
                cout << "Sajnos ez a lap nem letezik!\n";
            }
        }
    }while(igennem1 != "N");
    
}



int main() {
    
    lap **lapvaltozo;
    lap **lapcache;
    lapvaltozo = new lap*[100];
    for(int i=0; i<100; i++){
        lapvaltozo[i] = new lap[100];
    }
    
    for (size_t i=0; i<99; i++) {
        for (size_t a=0; a<=99; a++) {
            for (int s = 0; s<4; s++){
                *&lapvaltozo[i][a].jel[s] = 0;
            }
        }
    }
    
    
    lapcache = new lap*[100];
    for(int i=0; i<100; i++){
        lapcache[i] = new lap[100];
    }
    
    for (size_t i=0; i<99; i++) {
        for (size_t a=0; a<=99; a++) {
            for (int s = 0; s<4; s++){
                *&lapcache[i][a].jel[s] = 0;
            }
        }
    }
    
    
    string bekert1_1;
    string bekert1_2;
    string bekert2_1;
    string bekert2_2;
    
    if(lapvaltozo == NULL){
        cerr << "Sikertelen memoriafoglalas";
        return 1;
    }
    
    for(size_t s = 0; s<=99; s++){
        for(size_t i = 0; i<=99; i++){
            *&lapvaltozo[s][i].jel[1] = 0;
        }
    }
    playersorszam = 1;
    
    
    
    lapvaltozo[0][0].elet = true;
    /*for (int i = 0; i<=3; i++) {
        lapvaltozo[0][2].jel[i] = 1;
    }
    lapvaltozo[1][1].elet = true;
    for (int i = 0; i<=3; i++) {
        lapvaltozo[1][1].jel[i] = 1;
    }
    lapvaltozo[2][0].elet = true;
     lapvaltozo[2][0].jel[0] = 1;
     lapvaltozo[2][0].jel[2] = 1;
     lapvaltozo[3][0].elet = true;
     lapvaltozo[3][0].jel[0] = 1;
     lapvaltozo[3][0].jel[2] = 1;*/
    
    
    
    
    cout << "- QUINQUE -\n\n";
    cout << "Udvozollek a jatekban! A jatek az elso jatekossal (X) kezdodik, es a masodikkal (O) folytatodik egeszen addig, amig az egyik jatekos nem nyer, vagy dontetlennel nem vegzodik.\nEgy kartyalap van lehelyezve, ez pedig a [0][0]-ik pozicioban van.\n";
    cout << "A kartyalapok pozicioit lepesenkent lehetoseg lesz megtekinteni, illetve azon beluli lapok szimbolumait.\n";
    cout << "A megtekintett kartyalapokon ha szamokat latsz, akkor nincs rajta szimbolum!\n";
    cout << "Kezdodjek a jatek!!\n\n";
    
    
    do{
        int simbesor1 = NULL;
        int simbeoszlop1 = NULL;
        
        if(playersorszam == 1){
            for(int kor = 0; kor<=1; kor++){
                //ELSŐ KÖR
                if(kor == 0){
                    vizsgalat(*&lapvaltozo);
                    if(jatekvege == 0){
                        do{
                            bool szomszedos = false;
                            simbesor1 = NULL;
                            simbeoszlop1 = NULL;
                            int simsorszam = NULL;
                            cout << "1. bekeres, 1. jatekos "<< endl <<"Jeloles (J) vagy Mozgatas (M)?: ";
                            cin >> bekert1_1;
                            std::transform(bekert1_1.begin(), bekert1_1.end(),bekert1_1.begin(), ::toupper);
                            
                            if(bekert1_1 == "J" || bekert1_1 == "M"){
                                
                                
                                
                                
                                
                                //HA JELÖLÉS...
                                if(bekert1_1 == "J"){
                                    if(player1sim > 0){
                                        //Kiiratjuk a lap-pályát
                                        koordinatalap(*&lapvaltozo);
                                        
                                        cout << "Jelolesi lehetosegeid szama: " << player1sim << endl;
                                        lapmegtekintes(*&lapvaltozo);
                                        
                                        cout << "\nMelyik lapra szeretned jelolni a szimbolumot? \n";
                                        cout << "(A SZAMOZAS 0-TOL INDULNAK!) \n";
                                        
                                        do{
                                            cout << "Sor: ";
                                            cin >> simbesor1;
                                            cout << "Oszlop: ";
                                            cin >> simbeoszlop1;
                                            cout << endl;
                                            int simszamlalo = 0;
                                            bool megtelt = false;
                                            if(simbesor1 > 0 && simbeoszlop1 > 0){
                                                for(int s = 0; s<4; s++){
                                                    if(*&lapvaltozo[simbesor1][simbeoszlop1].jel[s] != 0){
                                                        simszamlalo++;
                                                    }
                                                    
                                                }
                                                
                                                if(simszamlalo == 4){
                                                    megtelt = true;
                                                    cout << "Ez a lap megtelt szimbolumokkal! Valassz masikat\n";
                                                    lapmegtekintes(*&lapvaltozo);
                                                }
                                            }
                                            
                                            if(megtelt == false){
                                                if(simbesor1 < 99 || simbeoszlop1 < 99){
                                                    
                                                    if(simbesor1 < 0 || simbeoszlop1 < 0){
                                                        cout << "Csak -1 iranyba fog lerakodni a lap!\n";
                                                        if(simbesor1 < 0){
                                                            //Lefele toljuk a komplett palyat
                                                            for(int i=0; i<=99; i++){
                                                                for(int a=0; a<=99; a++){
                                                                    if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                        for(int s = 0; s<=4; s++){
                                                                            *&lapvaltozo[i+1][a].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                            *&lapvaltozo[i][a].jel[s] = 0;
                                                                        }
                                                                        *&lapvaltozo[i+1][a].elet = true;
                                                                        *&lapvaltozo[i+1][a].mozgatva = true;
                                                                        *&lapvaltozo[i][a].elet = false;
                                                                    }
                                                                }
                                                            }
                                                            
                                                            for(int i=0; i<=99; i++){
                                                                for(int a=0; a<=99; a++){
                                                                    *&lapvaltozo[i][a].mozgatva = false;
                                                                }
                                                            }
                                                            simbesor1 = 0;
                                                        }
                                                        
                                                        
                                                        if(simbeoszlop1 < 0){
                                                            //Oldalra toljuk a komplett palyat
                                                            for(int i=0; i<=99; i++){
                                                                for(int a=0; a<=99; a++){
                                                                    if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                        for(int s = 0; s<=4; s++){
                                                                            *&lapvaltozo[i][a+1].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                            *&lapvaltozo[i][a].jel[s] = 0;
                                                                        }
                                                                        *&lapvaltozo[i][a+1].elet = true;
                                                                        *&lapvaltozo[i][a+1].mozgatva = true;
                                                                        *&lapvaltozo[i][a].elet = false;
                                                                    }
                                                                }
                                                            }
                                                            
                                                            for(int i=0; i<=99; i++){
                                                                for(int a=0; a<=99; a++){
                                                                    *&lapvaltozo[i][a].mozgatva = false;
                                                                }
                                                            }
                                                            simbeoszlop1 = 0;
                                                        }
                                                        
                                                        
                                                        //3. 4. 5.
                                                        //-  X  -
                                                        //-  -  -
                                                        //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                        if(simbesor1 == 0 && simbeoszlop1 != 0){
                                                            if(*&lapvaltozo[simbesor1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1][simbeoszlop1-1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1-1].elet == true) {
                                                                
                                                                *&lapvaltozo[simbesor1][simbeoszlop1].elet = true;
                                                                szomszedos = true;
                                                            }else{
                                                                cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n";
                                                                szomszedos = false;
                                                            }
                                                            
                                                            
                                                        }
                                                        
                                                        
                                                        //5. |- -
                                                        //6. |X -
                                                        //7. |- -
                                                        //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                        if(simbeoszlop1 == 0 && simbesor1 != 0){
                                                            if(*&lapvaltozo[simbesor1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1+1].elet == true) {
                                                                
                                                                *&lapvaltozo[simbesor1][simbeoszlop1].elet = true;
                                                                szomszedos = true;
                                                            }else{
                                                                cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n";
                                                                szomszedos = false;
                                                            }
                                                            
                                                            
                                                        }
                                                        
                                                        
                                                        //    0. 1.
                                                        //0. |X  -
                                                        //1. |-  -
                                                        //
                                                        //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                        if(simbesor1 == 0 && simbeoszlop1 == 0){
                                                            if(*&lapvaltozo[simbesor1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1].elet == true) {
                                                                
                                                                *&lapvaltozo[simbesor1][simbeoszlop1].elet = true;
                                                                szomszedos = true;
                                                            }else{
                                                                cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n";
                                                                szomszedos = false;
                                                            }
                                                            
                                                            
                                                        }
                                                        
                                                        
                                                    }else{
                                                        //Ha a lappal szomszédos, csak akkor lehet új lapot létrehozni.
                                                        if(*&lapvaltozo[simbesor1][simbeoszlop1].elet == false){
                                                            if(*&lapvaltozo[simbesor1][simbeoszlop1-1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1-1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1-1].elet == true) {
                                                                
                                                                *&lapvaltozo[simbesor1][simbeoszlop1].elet = true;
                                                                szomszedos = true;
                                                            }else{
                                                                cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n";
                                                                szomszedos = false;
                                                            }
                                                        }else{
                                                            szomszedos = true;
                                                        }
                                                    }
                                                }else{
                                                    cout << "Tul nagy szam!\n";
                                                }
                                            }
                                        }while(szomszedos == false);
                                        
                                        
                                        //Ha a lap életben van, kiiratjuk a lap szimbólumait (szabad/foglalt terület)
                                        if(*&lapvaltozo[simbesor1][simbeoszlop1].elet == true){
                                            kartyamegjelenites(*&lapvaltozo, simbesor1, simbeoszlop1);
                                            
                                            do{
                                                cout << "Ird be azt a szamot, amely helyere szeretned a szimbolumot: ";
                                                cin >> simsorszam;
                                                if(simsorszam >= 0 && simsorszam < 4){
                                                    if(*&lapvaltozo[simbesor1][simbeoszlop1].jel[simsorszam]!=1 &&
                                                       *&lapvaltozo[simbesor1][simbeoszlop1].jel[simsorszam]!=2){
                                                        if(playersorszam == 1){
                                                            *&lapvaltozo[simbesor1][simbeoszlop1].jel[simsorszam] = 1;
                                                            player1sim -=1;
                                                            cout << "Jeloleseid szama meg: " << player1sim << endl;
                                                        }
                                                        if(playersorszam == 2){
                                                            *&lapvaltozo[simbesor1][simbeoszlop1].jel[simsorszam] = 2;
                                                            player2sim -=1;
                                                            cout << "Jeloleseid szama meg: " << player2sim << endl;
                                                        }
                                                    }else{
                                                        cout << "Ezen a pozicion mar szerepel egy szimbolum";
                                                        simsorszam = 6;
                                                    }
                                                }else{
                                                    cout << "Helytelen bevitel.\n";
                                                }
                                            }while(!(simsorszam >= 0 && simsorszam < 4));
                                            
                                            cout << "Kesz!\n";
                                            kartyamegjelenites(*&lapvaltozo, simbesor1, simbeoszlop1);
                                        }
                                        
                                    }else{
                                        bekert1_1 = "0";
                                        cout << "Sajnalom, de elfogyott a jelolesi lehetosegeid! (" << player1sim << ")\n";
                                    }
                                }
                                
                                
                                
                                
                                
                                //HA MOZGATÁS...
                                if(bekert1_1 == "M"){
                                    if(bekert1_1 != "J"){
                                        int mitsor1 = NULL;
                                        int mitoszlop1 = NULL;
                                        int hovasor1 = NULL;
                                        int hovaoszlop1 = NULL;
                                        bool vaneelet = false;
                                        
                                        do{
                                            koordinatalap(*&lapvaltozo);
                                            lapmegtekintes(*&lapvaltozo);
                                            do{
                                                cout << "Melyik lapot szeretned mozgatni?\nSor: ";
                                                cin >> mitsor1;
                                                cout << "Oszlop: ";
                                                cin >> mitoszlop1;
                                                if(mitsor1 > 99 || mitoszlop1 > 99){
                                                    vaneelet = false;
                                                    cout << "Tul nagy szamot adtal meg. \n";
                                                }else{
                                                    if(mitsor1 < 0 || mitoszlop1 < 0){
                                                        vaneelet = false;
                                                        cout << "Itt nincs kartya:(\n\n";
                                                    }else{
                                                        if(*&lapvaltozo[mitsor1][mitoszlop1].elet == true){
                                                            if(*&lapvaltozo[mitsor1+1][mitoszlop1].elet == true &&
                                                               *&lapvaltozo[mitsor1][mitoszlop1+1].elet == true &&
                                                               *&lapvaltozo[mitsor1-1][mitoszlop1].elet == true &&
                                                               *&lapvaltozo[mitsor1][mitoszlop1-1].elet == true){
                                                                vaneelet = false;
                                                                cout << "Sajnos ennek a lapnak mind a 4 oldalan van szomszedja.\n";
                                                            }else{
                                                                vaneelet = true;
                                                            }
                                                        }else{
                                                            cout << "Itt nincs kartya!:(\n\n";
                                                            vaneelet = false;
                                                        }
                                                    }
                                                }
                                            }while(vaneelet == false);
                                            
                                            cout << "Melyik poziciora szeretned rakni a kivalasztott kartyat?\nSor: ";
                                            cin >> hovasor1;
                                            cout << "Oszlop: ";
                                            cin >> hovaoszlop1;
                                            //HA POZITÍV IRÁNYBA TÖRTÉNIK A MOZGATÁS
                                            if(hovasor1 > 0 && hovaoszlop1 > 0){
                                                if(hovasor1 < 99 && hovaoszlop1 < 99){
                                                    if(*&lapvaltozo[hovasor1-1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1-1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                        
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                }else{
                                                    szomszedos = false;
                                                    cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                }
                                            }else{
                                                //HA NEGATÍV IRÁNYBAN TÖRTÉNIK A MOZGATÁS
                                                if(hovasor1 < 0){
                                                    //Lefele toljuk a komplett palyat
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                for(int s = 0; s<=4; s++){
                                                                    *&lapvaltozo[i+1][a].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                }
                                                                *&lapvaltozo[i+1][a].elet = true;
                                                                *&lapvaltozo[i+1][a].mozgatva = true;
                                                                *&lapvaltozo[i][a].elet = false;
                                                            }
                                                        }
                                                    }
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            *&lapvaltozo[i][a].mozgatva = false;
                                                        }
                                                    }
                                                    
                                                    hovasor1 = 0;
                                                    mitsor1 += 1;
                                                    
                                                }
                                                
                                                if(hovaoszlop1 < 0){
                                                    //Oldalra toljuk a komplett palyat
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                for(int s = 0; s<=4; s++){
                                                                    *&lapvaltozo[i][a+1].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                }
                                                                *&lapvaltozo[i][a+1].elet = true;
                                                                *&lapvaltozo[i][a+1].mozgatva = true;
                                                                *&lapvaltozo[i][a].elet = false;
                                                            }
                                                        }
                                                    }
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            *&lapvaltozo[i][a].mozgatva = false;
                                                        }
                                                    }
                                                    hovaoszlop1 = 0;
                                                    mitoszlop1 += 1;
                                                    
                                                }
                                                //3. 4. 5.
                                                //-  X  -
                                                //-  -  -
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovasor1 == 0 && hovaoszlop1 != 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1-1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                    
                                                }
                                                
                                                //5. |- -
                                                //6. |X -
                                                //7. |- -
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovaoszlop1 == 0 && hovasor1 != 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1+1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                    
                                                    
                                                }
                                                //    0. 1.
                                                //0. |X  -
                                                //1. |-  -
                                                //
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovaoszlop1 == 0 && hovasor1 == 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                }
                                                
                                            }
                                        }while(szomszedos == false);
                                        koordinatalap(*&lapvaltozo);
                                        lapmegtekintes(*&lapvaltozo);
                                        
                                    }
                                }
                                
                                
                                
                            }else{
                                cout << "Helytelen bekeresi forma..\n\n ";
                            }
                        }while(!(bekert1_1 == "J" || bekert1_1 == "M"));
                    }
                }
                //MÁSODIK KÖR
                if(kor == 1){
                    vizsgalat(*&lapvaltozo);
                    if(jatekvege == 0){
                        do{
                            bool szomszedos = false;
                            cout << "2. bekeres, 1. jatekos "<< endl <<"Mozgatas (M) vagy Passz (P)?: ";
                            cin >> bekert1_2;
                            std::transform(bekert1_2.begin(), bekert1_2.end(),bekert1_2.begin(), ::toupper);
                            
                            if(bekert1_2 == "M" || bekert1_2 == "P"){
                                
                                
                                //HA MOZGATÁS...
                                if(bekert1_2 == "M"){
                                    if(bekert1_1 != "J"){
                                        int mitsor1 = NULL;
                                        int mitoszlop1 = NULL;
                                        int hovasor1 = NULL;
                                        int hovaoszlop1 = NULL;
                                        bool vaneelet = false;
                                        
                                        do{
                                            koordinatalap(*&lapvaltozo);
                                            lapmegtekintes(*&lapvaltozo);
                                            do{
                                                cout << "Melyik lapot szeretned mozgatni?\nSor: ";
                                                cin >> mitsor1;
                                                cout << "Oszlop: ";
                                                cin >> mitoszlop1;
                                                if(mitsor1 < 0 || mitoszlop1 < 0){
                                                    vaneelet = false;
                                                    cout << "Itt nincs kartya:(\n\n";
                                                }else{
                                                    if(*&lapvaltozo[mitsor1][mitoszlop1].elet == true){
                                                        if(*&lapvaltozo[mitsor1+1][mitoszlop1].elet == true &&
                                                           *&lapvaltozo[mitsor1][mitoszlop1+1].elet == true &&
                                                           *&lapvaltozo[mitsor1-1][mitoszlop1].elet == true &&
                                                           *&lapvaltozo[mitsor1][mitoszlop1-1].elet == true){
                                                            vaneelet = false;
                                                            cout << "Sajnos ennek a lapnak mind a 4 oldalan van szomszedja.\n";
                                                        }else{
                                                            vaneelet = true;
                                                        }
                                                    }else{
                                                        cout << "Itt nincs kartya!:(\n\n";
                                                        vaneelet = false;
                                                    }
                                                }
                                            }while(vaneelet == false);
                                            
                                            cout << "Melyik poziciora szeretned rakni a kivalasztott kartyat?\nSor: ";
                                            cin >> hovasor1;
                                            cout << "Oszlop: ";
                                            cin >> hovaoszlop1;
                                            //HA POZITÍV IRÁNYBA TÖRTÉNIK A MOZGATÁS
                                            if(hovasor1 > 0 && hovaoszlop1 > 0){
                                                if(hovasor1 < 99 && hovaoszlop1 < 99){
                                                    if(*&lapvaltozo[hovasor1-1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1-1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                        
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                }else{
                                                    cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                    szomszedos = false;
                                                }
                                            }else{
                                                //HA NEGATÍV IRÁNYBAN TÖRTÉNIK A MOZGATÁS
                                                if(hovasor1 < 0){
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                for(int s = 0; s<=4; s++){
                                                                    *&lapvaltozo[i+1][a].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                }
                                                                *&lapvaltozo[i+1][a].elet = true;
                                                                *&lapvaltozo[i+1][a].mozgatva = true;
                                                                *&lapvaltozo[i][a].elet = false;
                                                            }
                                                        }
                                                    }
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            *&lapvaltozo[i][a].mozgatva = false;
                                                        }
                                                    }
                                                    
                                                    hovasor1 = 0;
                                                    mitsor1 += 1;
                                                    
                                                }
                                                
                                                if(hovaoszlop1 < 0){
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                for(int s = 0; s<=4; s++){
                                                                    *&lapvaltozo[i][a+1].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                }
                                                                *&lapvaltozo[i][a+1].elet = true;
                                                                *&lapvaltozo[i][a+1].mozgatva = true;
                                                                *&lapvaltozo[i][a].elet = false;
                                                            }
                                                        }
                                                    }
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            *&lapvaltozo[i][a].mozgatva = false;
                                                        }
                                                    }
                                                    hovaoszlop1 = 0;
                                                    mitoszlop1 += 1;
                                                    
                                                }
                                                
                                                if(hovasor1 == 0 && hovaoszlop1 != 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1-1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                    
                                                }
                                                
                                                if(hovaoszlop1 == 0 && hovasor1 != 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1+1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                    
                                                    
                                                }
                                                
                                                if(hovaoszlop1 == 0 && hovasor1 == 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                }
                                                
                                            }
                                        }while(szomszedos == false);
                                        koordinatalap(*&lapvaltozo);
                                        lapmegtekintes(*&lapvaltozo);
                                        
                                    }else{
                                        //Ha volt már az előző körben jelölés..
                                        cout << "Sajnos az elozo korben jeloltel, igy csak a Passz maradt hatra.\n";
                                        bekert1_2 = "P";
                                    }
                                }
                                if(bekert1_2 == "P"){
                                    cout << "Passzolva..\n";
                                    playersorszam = 2;
                                }
                                
                                
                            }else{
                                cout << "Helytelen bekeresi forma..\n\n ";
                            }
                        }while(!(bekert1_2 == "M" || bekert1_2 == "P"));
                        
                    }
                }
                if(jatekvege == 1){
                    playersorszam = 0;
                }else{
                    playersorszam = 2;
                }
            }
        }
        
        
        
        
        
        if(playersorszam == 2){
            
            
            for(int kor = 0; kor<=1; kor++){
                if(kor == 0){
                    vizsgalat(*&lapvaltozo);
                    if(jatekvege == 0){
                        do{
                            bool szomszedos = false;
                            simbesor1 = NULL;
                            simbeoszlop1 = NULL;
                            int simsorszam = NULL;
                            cout << "1. bekeres, 2. jatekos "<< endl <<"Jeloles (J) vagy Mozgatas (M)?: ";
                            cin >> bekert2_1;
                            std::transform(bekert2_1.begin(), bekert2_1.end(),bekert2_1.begin(), ::toupper);
                            
                            if(bekert2_1 == "J" || bekert2_1 == "M"){
                                if(bekert2_1 == "J"){
                                    if(player2sim > 0){
                                        //Kiiratjuk a lap-pályát
                                        koordinatalap(*&lapvaltozo);
                                        
                                        cout << "Jelolesi lehetosegeid szama: " << player2sim << endl;
                                        lapmegtekintes(*&lapvaltozo);
                                        
                                        cout << "\nMelyik lapra szeretned jelolni a szimbolumot? \n";
                                        cout << "(A SZAMOZAS 0-TOL INDULNAK!) \n";
                                        
                                        do{
                                            cout << "Sor: ";
                                            cin >> simbesor1;
                                            cout << "Oszlop: ";
                                            cin >> simbeoszlop1;
                                            cout << endl;
                                            int simszamlalo = 0;
                                            bool megtelt = false;
                                            if(simbesor1 > 0 && simbeoszlop1 > 0){
                                                for(int s = 0; s<4; s++){
                                                    if(*&lapvaltozo[simbesor1][simbeoszlop1].jel[s] != 0){
                                                        simszamlalo++;
                                                    }
                                                    
                                                }
                                                
                                                if(simszamlalo == 4){
                                                    megtelt = true;
                                                    cout << "Ez a lap megtelt szimbolumokkal! Valassz masikat\n";
                                                    lapmegtekintes(*&lapvaltozo);
                                                }
                                            }
                                            
                                            
                                            if(megtelt == false){
                                                if(simbesor1 < 99 || simbeoszlop1 < 99){
                                                    
                                                    if(simbesor1 < 0 || simbeoszlop1 < 0){
                                                        cout << "Csak -1 iranyba fog lerakodni a lap!\n";
                                                        if(simbesor1 < 0){
                                                            //Lefele toljuk a komplett palyat
                                                            for(int i=0; i<=99; i++){
                                                                for(int a=0; a<=99; a++){
                                                                    if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                        for(int s = 0; s<=4; s++){
                                                                            *&lapvaltozo[i+1][a].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                            *&lapvaltozo[i][a].jel[s] = 0;
                                                                        }
                                                                        *&lapvaltozo[i+1][a].elet = true;
                                                                        *&lapvaltozo[i+1][a].mozgatva = true;
                                                                        *&lapvaltozo[i][a].elet = false;
                                                                    }
                                                                }
                                                            }
                                                            
                                                            for(int i=0; i<=99; i++){
                                                                for(int a=0; a<=99; a++){
                                                                    *&lapvaltozo[i][a].mozgatva = false;
                                                                }
                                                            }
                                                            simbesor1 = 0;
                                                        }
                                                        
                                                        
                                                        if(simbeoszlop1 < 0){
                                                            //Oldalra toljuk a komplett palyat
                                                            for(int i=0; i<=99; i++){
                                                                for(int a=0; a<=99; a++){
                                                                    if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                        for(int s = 0; s<=4; s++){
                                                                            *&lapvaltozo[i][a+1].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                            *&lapvaltozo[i][a].jel[s] = 0;
                                                                        }
                                                                        *&lapvaltozo[i][a+1].elet = true;
                                                                        *&lapvaltozo[i][a+1].mozgatva = true;
                                                                        *&lapvaltozo[i][a].elet = false;
                                                                    }
                                                                }
                                                            }
                                                            
                                                            for(int i=0; i<=99; i++){
                                                                for(int a=0; a<=99; a++){
                                                                    *&lapvaltozo[i][a].mozgatva = false;
                                                                }
                                                            }
                                                            simbeoszlop1 = 0;
                                                        }
                                                        
                                                        
                                                        //3. 4. 5.
                                                        //-  X  -
                                                        //-  -  -
                                                        //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                        if(simbesor1 == 0 && simbeoszlop1 != 0){
                                                            if(*&lapvaltozo[simbesor1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1][simbeoszlop1-1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1-1].elet == true) {
                                                                
                                                                *&lapvaltozo[simbesor1][simbeoszlop1].elet = true;
                                                                szomszedos = true;
                                                            }else{
                                                                cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n";
                                                                szomszedos = false;
                                                            }
                                                            
                                                            
                                                        }
                                                        
                                                        
                                                        //5. |- -
                                                        //6. |X -
                                                        //7. |- -
                                                        //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                        if(simbeoszlop1 == 0 && simbesor1 != 0){
                                                            if(*&lapvaltozo[simbesor1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1+1].elet == true) {
                                                                
                                                                *&lapvaltozo[simbesor1][simbeoszlop1].elet = true;
                                                                szomszedos = true;
                                                            }else{
                                                                cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n";
                                                                szomszedos = false;
                                                            }
                                                            
                                                            
                                                        }
                                                        
                                                        
                                                        //    0. 1.
                                                        //0. |X  -
                                                        //1. |-  -
                                                        //
                                                        //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                        if(simbesor1 == 0 && simbeoszlop1 == 0){
                                                            if(*&lapvaltozo[simbesor1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1].elet == true) {
                                                                
                                                                *&lapvaltozo[simbesor1][simbeoszlop1].elet = true;
                                                                szomszedos = true;
                                                            }else{
                                                                cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n";
                                                                szomszedos = false;
                                                            }
                                                            
                                                            
                                                        }
                                                        
                                                        
                                                    }else{
                                                        //Ha a lappal szomszédos, csak akkor lehet új lapot létrehozni.
                                                        if(*&lapvaltozo[simbesor1][simbeoszlop1].elet == false){
                                                            if(*&lapvaltozo[simbesor1][simbeoszlop1-1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1-1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1].elet == true ||
                                                               *&lapvaltozo[simbesor1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1-1][simbeoszlop1+1].elet == true ||
                                                               *&lapvaltozo[simbesor1+1][simbeoszlop1-1].elet == true) {
                                                                
                                                                *&lapvaltozo[simbesor1][simbeoszlop1].elet = true;
                                                                szomszedos = true;
                                                            }else{
                                                                cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n";
                                                                szomszedos = false;
                                                            }
                                                        }else{
                                                            szomszedos = true;
                                                        }
                                                    }
                                                }else{
                                                    cout << "Tul nagy szam!\n";
                                                }
                                            }
                                        }while(szomszedos == false);
                                        
                                        
                                        //Ha a lap életben van, kiiratjuk a lap szimbólumait (szabad/foglalt terület)
                                        if(*&lapvaltozo[simbesor1][simbeoszlop1].elet == true){
                                            kartyamegjelenites(*&lapvaltozo, simbesor1, simbeoszlop1);
                                            do{
                                                cout << "Ird be azt a szamot, amely helyere szeretned a szimbolumot: ";
                                                cin >> simsorszam;
                                                if(simsorszam >= 0 && simsorszam < 4){
                                                    if(*&lapvaltozo[simbesor1][simbeoszlop1].jel[simsorszam]!=1 &&
                                                       *&lapvaltozo[simbesor1][simbeoszlop1].jel[simsorszam]!=2){
                                                        if(playersorszam == 1){
                                                            *&lapvaltozo[simbesor1][simbeoszlop1].jel[simsorszam] = 1;
                                                            player1sim -=1;
                                                            cout << "Jeloleseid szama meg: " << player1sim << endl;
                                                        }
                                                        if(playersorszam == 2){
                                                            *&lapvaltozo[simbesor1][simbeoszlop1].jel[simsorszam] = 2;
                                                            player2sim -=1;
                                                            cout << "Jeloleseid szama meg: " << player2sim << endl;
                                                        }
                                                    }else{
                                                        cout << "Ezen a pozicion mar szerepel egy szimbolum\n";
                                                        simsorszam = 6;
                                                    }
                                                }else{
                                                    cout << "Helytelen bevitel.\n";
                                                }
                                            }while(!(simsorszam >= 0 && simsorszam < 4));
                                            
                                            cout << "Kesz!\n";
                                            kartyamegjelenites(*&lapvaltozo, simbesor1, simbeoszlop1);
                                        }
                                        
                                    }else{
                                        bekert1_1 = "0";
                                        cout << "Sajnalom, de elfogyott a jelolesi lehetosegeid! (" << player1sim << ")\n";
                                    }
                                }
                                
                                if(bekert2_1 == "M"){
                                    if(bekert2_1 != "J"){
                                        int mitsor1 = NULL;
                                        int mitoszlop1 = NULL;
                                        int hovasor1 = NULL;
                                        int hovaoszlop1 = NULL;
                                        bool vaneelet = false;
                                        
                                        do{
                                            koordinatalap(*&lapvaltozo);
                                            lapmegtekintes(*&lapvaltozo);
                                            do{
                                                cout << "Melyik lapot szeretned mozgatni?\nSor: ";
                                                cin >> mitsor1;
                                                cout << "Oszlop: ";
                                                cin >> mitoszlop1;
                                                if(mitsor1 > 99 || mitoszlop1 > 99){
                                                    vaneelet = false;
                                                    cout << "Tul nagy szamot adtal meg. \n";
                                                }else{
                                                    if(mitsor1 < 0 || mitoszlop1 < 0){
                                                        vaneelet = false;
                                                        cout << "Itt nincs kartya:(\n\n";
                                                    }else{
                                                        if(*&lapvaltozo[mitsor1][mitoszlop1].elet == true){
                                                            if(*&lapvaltozo[mitsor1+1][mitoszlop1].elet == true &&
                                                               *&lapvaltozo[mitsor1][mitoszlop1+1].elet == true &&
                                                               *&lapvaltozo[mitsor1-1][mitoszlop1].elet == true &&
                                                               *&lapvaltozo[mitsor1][mitoszlop1-1].elet == true){
                                                                vaneelet = false;
                                                                cout << "Sajnos ennek a lapnak mind a 4 oldalan van szomszedja.\n";
                                                            }else{
                                                                vaneelet = true;
                                                            }
                                                        }else{
                                                            cout << "Itt nincs kartya!:(\n\n";
                                                            vaneelet = false;
                                                        }
                                                    }
                                                }
                                            }while(vaneelet == false);
                                            
                                            cout << "Melyik poziciora szeretned rakni a kivalasztott kartyat?\nSor: ";
                                            cin >> hovasor1;
                                            cout << "Oszlop: ";
                                            cin >> hovaoszlop1;
                                            //HA POZITÍV IRÁNYBA TÖRTÉNIK A MOZGATÁS
                                            if(hovasor1 > 0 && hovaoszlop1 > 0){
                                                if(hovasor1 < 99 && hovaoszlop1 < 99){
                                                    if(*&lapvaltozo[hovasor1-1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1-1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                        
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                }else{
                                                    szomszedos = false;
                                                    cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                }
                                            }else{
                                                //HA NEGATÍV IRÁNYBAN TÖRTÉNIK A MOZGATÁS
                                                if(hovasor1 < 0){
                                                    //Lefele toljuk a komplett palyat
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                for(int s = 0; s<=4; s++){
                                                                    *&lapvaltozo[i+1][a].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                }
                                                                *&lapvaltozo[i+1][a].elet = true;
                                                                *&lapvaltozo[i+1][a].mozgatva = true;
                                                                *&lapvaltozo[i][a].elet = false;
                                                            }
                                                        }
                                                    }
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            *&lapvaltozo[i][a].mozgatva = false;
                                                        }
                                                    }
                                                    
                                                    hovasor1 = 0;
                                                    mitsor1 += 1;
                                                    
                                                }
                                                
                                                if(hovaoszlop1 < 0){
                                                    //Oldalra toljuk a komplett palyat
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                for(int s = 0; s<=4; s++){
                                                                    *&lapvaltozo[i][a+1].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                }
                                                                *&lapvaltozo[i][a+1].elet = true;
                                                                *&lapvaltozo[i][a+1].mozgatva = true;
                                                                *&lapvaltozo[i][a].elet = false;
                                                            }
                                                        }
                                                    }
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            *&lapvaltozo[i][a].mozgatva = false;
                                                        }
                                                    }
                                                    hovaoszlop1 = 0;
                                                    mitoszlop1 += 1;
                                                    
                                                }
                                                //3. 4. 5.
                                                //-  X  -
                                                //-  -  -
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovasor1 == 0 && hovaoszlop1 != 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1-1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                    
                                                }
                                                
                                                //5. |- -
                                                //6. |X -
                                                //7. |- -
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovaoszlop1 == 0 && hovasor1 != 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1+1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                    
                                                    
                                                }
                                                //    0. 1.
                                                //0. |X  -
                                                //1. |-  -
                                                //
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovaoszlop1 == 0 && hovasor1 == 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                }
                                                
                                            }
                                        }while(szomszedos == false);
                                        koordinatalap(*&lapvaltozo);
                                        lapmegtekintes(*&lapvaltozo);
                                        
                                    }
                                }
                                
                            }else{
                                cout << "Helytelen bekeresi forma..\n\n ";
                            }
                        }while(!(bekert2_1 == "J" || bekert2_1 == "M"));
                    }
                    
                }
                if(kor == 1){
                    vizsgalat(*&lapvaltozo);
                    if(jatekvege == 0){
                        do{
                            bool szomszedos = false;
                            simbesor1 = NULL;
                            simbeoszlop1 = NULL;
                            cout << "2. bekeres, 2. jatekos "<< endl <<"Mozgatas (M) vagy Passz (P)?: ";
                            cin >> bekert2_2;
                            std::transform(bekert2_2.begin(), bekert2_2.end(),bekert2_2.begin(), ::toupper);
                            
                            if(bekert2_2 == "M" || bekert2_2 == "P"){
                                if(bekert2_2 == "M"){
                                    if(bekert2_1 != "J"){
                                        int mitsor1 = NULL;
                                        int mitoszlop1 = NULL;
                                        int hovasor1 = NULL;
                                        int hovaoszlop1 = NULL;
                                        bool vaneelet = false;
                                        
                                        do{
                                            koordinatalap(*&lapvaltozo);
                                            lapmegtekintes(*&lapvaltozo);
                                            do{
                                                cout << "Melyik lapot szeretned mozgatni?\nSor: ";
                                                cin >> mitsor1;
                                                cout << "Oszlop: ";
                                                cin >> mitoszlop1;
                                                if(mitsor1 > 99 || mitoszlop1 > 99){
                                                    vaneelet = false;
                                                    cout << "Tul nagy szamot adtal meg. \n";
                                                }else{
                                                    if(mitsor1 < 0 || mitoszlop1 < 0){
                                                        vaneelet = false;
                                                        cout << "Itt nincs kartya:(\n\n";
                                                    }else{
                                                        if(*&lapvaltozo[mitsor1][mitoszlop1].elet == true){
                                                            if(*&lapvaltozo[mitsor1+1][mitoszlop1].elet == true &&
                                                               *&lapvaltozo[mitsor1][mitoszlop1+1].elet == true &&
                                                               *&lapvaltozo[mitsor1-1][mitoszlop1].elet == true &&
                                                               *&lapvaltozo[mitsor1][mitoszlop1-1].elet == true){
                                                                vaneelet = false;
                                                                cout << "Sajnos ennek a lapnak mind a 4 oldalan van szomszedja.\n";
                                                            }else{
                                                                vaneelet = true;
                                                            }
                                                        }else{
                                                            cout << "Itt nincs kartya!:(\n\n";
                                                            vaneelet = false;
                                                        }
                                                    }
                                                }
                                            }while(vaneelet == false);
                                            
                                            cout << "Melyik poziciora szeretned rakni a kivalasztott kartyat?\nSor: ";
                                            cin >> hovasor1;
                                            cout << "Oszlop: ";
                                            cin >> hovaoszlop1;
                                            //HA POZITÍV IRÁNYBA TÖRTÉNIK A MOZGATÁS
                                            if(hovasor1 > 0 && hovaoszlop1 > 0){
                                                if(hovasor1 < 99 && hovaoszlop1 < 99){
                                                    if(*&lapvaltozo[hovasor1-1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1-1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                        
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                }else{
                                                    szomszedos = false;
                                                    cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                }
                                            }else{
                                                //HA NEGATÍV IRÁNYBAN TÖRTÉNIK A MOZGATÁS
                                                if(hovasor1 < 0){
                                                    //Lefele toljuk a komplett palyat
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                for(int s = 0; s<=4; s++){
                                                                    *&lapvaltozo[i+1][a].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                }
                                                                *&lapvaltozo[i+1][a].elet = true;
                                                                *&lapvaltozo[i+1][a].mozgatva = true;
                                                                *&lapvaltozo[i][a].elet = false;
                                                            }
                                                        }
                                                    }
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            *&lapvaltozo[i][a].mozgatva = false;
                                                        }
                                                    }
                                                    
                                                    hovasor1 = 0;
                                                    mitsor1 += 1;
                                                    
                                                }
                                                
                                                if(hovaoszlop1 < 0){
                                                    //Oldalra toljuk a komplett palyat
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            if(*&lapvaltozo[i][a].elet == true && *&lapvaltozo[i][a].mozgatva == false){
                                                                for(int s = 0; s<=4; s++){
                                                                    *&lapvaltozo[i][a+1].jel[s] = *&lapvaltozo[i][a].jel[s];
                                                                }
                                                                *&lapvaltozo[i][a+1].elet = true;
                                                                *&lapvaltozo[i][a+1].mozgatva = true;
                                                                *&lapvaltozo[i][a].elet = false;
                                                            }
                                                        }
                                                    }
                                                    
                                                    for(int i=0; i<=99; i++){
                                                        for(int a=0; a<=99; a++){
                                                            *&lapvaltozo[i][a].mozgatva = false;
                                                        }
                                                    }
                                                    hovaoszlop1 = 0;
                                                    mitoszlop1 += 1;
                                                    
                                                }
                                                //3. 4. 5.
                                                //-  X  -
                                                //-  -  -
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovasor1 == 0 && hovaoszlop1 != 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1][hovaoszlop1-1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1-1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                    
                                                }
                                                
                                                //5. |- -
                                                //6. |X -
                                                //7. |- -
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovaoszlop1 == 0 && hovasor1 != 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1].elet == true ||
                                                       *&lapvaltozo[hovasor1-1][hovaoszlop1+1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                    
                                                    
                                                }
                                                //    0. 1.
                                                //0. |X  -
                                                //1. |-  -
                                                //
                                                //Vizsgálat az X körül (szomszédkeresés), ha stimmel minden, mozgathatjuk
                                                if(hovaoszlop1 == 0 && hovasor1 == 0){
                                                    if(*&lapvaltozo[hovasor1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1+1].elet == true ||
                                                       *&lapvaltozo[hovasor1+1][hovaoszlop1].elet == true) {
                                                        
                                                        szomszedos = true;
                                                        for(int i = 0; i<=3; i++){
                                                            *&lapvaltozo[hovasor1][hovaoszlop1].jel[i] = *&lapvaltozo[mitsor1][mitoszlop1].jel[i];
                                                            *&lapvaltozo[mitsor1][mitoszlop1].jel[i] = 0;
                                                        }
                                                        *&lapvaltozo[hovasor1][hovaoszlop1].elet = true;
                                                        *&lapvaltozo[mitsor1][mitoszlop1].elet = false;
                                                    }else{
                                                        cout << "Sajnalom, de erre a poziciora nem rakhat lapot\n\n";
                                                        szomszedos = false;
                                                    }
                                                }
                                                
                                            }
                                        }while(szomszedos == false);
                                        koordinatalap(*&lapvaltozo);
                                        lapmegtekintes(*&lapvaltozo);
                                        
                                    }
                                }
                            }else{
                                cout << "Helytelen bekeresi forma..\n\n ";
                            }
                        }while(!(bekert2_2 == "M" || bekert2_2 == "P"));
                    }
                    
                }
            }
        }
        if(jatekvege == 1){
            playersorszam = 0;
        }else{
            playersorszam = 1;
        }
        
        
    }while(jatekvege != 1);
    delete[] lapvaltozo;
    
}
