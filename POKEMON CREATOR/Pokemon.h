#ifndef POKEMON_H
#define POKEMON_H

#include <string>

using namespace std;

class Pokemon{
    public:
        Pokemon();
        
        void setName(string c);
        void setRegion(string c);

        void setType1(int n);
        void setType2(int n);

        void randomizeStat(bool f);

        void print();

        void remove();

    private:
        string name;
        string region;
        string type1;
        string type2;
        int hp;
        int atk;
        int def;
        int spe;
        int spatk;
        int spdef;
        bool islegendary;
};

#endif