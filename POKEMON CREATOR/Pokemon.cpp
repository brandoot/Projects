#include "Pokemon.h"
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <ios>

using namespace std;

string typeA[18] = {"Bug","Dark","Dragon","Electric","Fairy","Fight","Fire","Flying","Ghost","Grass","Ground","Ice","Normal","Poison","Psychic","Rock","Steel","Water"};
string typeB[19] = {"Bug","Dark","Dragon","Electric","Fairy","Fight","Fire","Flying","Ghost","Grass","Ground","Ice","Normal","Poison","Psychic","Rock","Steel","Water",""};

Pokemon::Pokemon(){
    
    name = "";
    region = "";
    type1 = "";
    type2 = "";

    islegendary = false;

    hp = 0;
    atk = 0;
    def = 0;
    spe = 0;
    spatk = 0;
    spdef = 0;

}

void Pokemon::setName(string c){
    name = c;
}

void Pokemon::setRegion(string c){
    region = c;
}

void Pokemon::setType1(int n){
    type1 = typeA[n];
}

void Pokemon::setType2(int n){
    type2 = typeB[n];
}

void Pokemon::randomizeStat(bool f){
   
    unsigned seed = time(0);
    srand(seed);
    
    if(f = true){
        hp = rand() % 90 + 70;
        atk = rand() % 80 + 60;
        def = rand() % 80 + 60;
        spatk = rand() % 80 + 60;
        spdef = rand() % 80 + 60;
        spe = rand() % 90 + 70;  
    }
    else{
        hp = rand() % 70 + 30;
        atk = rand() % 60 + 20;
        def = rand() % 60 + 20;
        spatk = rand() % 60 + 20;
        spdef = rand() % 60 + 20;
        spe = rand() % 70 + 30;  
    } 
}

void Pokemon::print(){
    cout << name << "  " << region <<"  "<< type1 << "  " << type2 <<endl <<
        "HP  "<< hp  << endl<<
        "ATK  " << atk<< endl  <<
        "DEF  "  << def <<endl <<
        "SpATK  " << spatk  << endl << 
        "SpDEF  "  << spdef  << endl <<
        "Spe  "  << spe << endl;
}

void Pokemon::remove(){
    name = "";
    region = "";
    type1 = "";
    type2 = "";

    islegendary = false;

    hp = 0;
    atk = 0;
    def = 0;
    spe = 0;
    spatk = 0;
    spdef = 0;
}