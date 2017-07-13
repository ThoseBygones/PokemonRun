#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
#include "Error.h"
#include "Pokemon.h"
using namespace std;

//extern vector <Pokemon *> pokemonList(40);

void readPokemonList(vector <Pokemon *> &pokemonList)
{
    string line;
    ifstream myFile;
    int index = 0;
    myFile.open("PokemonList.txt", ios_base::in);
    try
    {
        if(!myFile)
        {
            throw runtime_error("The file does not exist!");
        }
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    if(myFile)
    {
        while(!myFile.eof())
        {
            getline(myFile, line);
            //fromString(line);
            istringstream is(line);
            int pokeId;
            string pokeName;
            int level;
            int attack;
            int defence;
            int hp;
            double evd;
            double catchRate;
            int moneyLeft;
            int exp;
            is >> pokeId >> pokeName >> level >> attack >> defence >> hp >> evd >> catchRate >> moneyLeft >> exp;
            int currentHp = hp;
            pokemonList[index] = new Pokemon(pokeId, pokeName, level, attack, defence, hp, currentHp, evd, catchRate, moneyLeft, exp);
            //pokemonList[index]->showInfo();
            index++;
        }
    }
    /*int x;
    cout << "请输入遇见怪物的编号：";
    cin >> x;
    Pokemon currentPoke = *pokemonList[x-1];
    pika.combat(bag,currentPoke);
    //pika.showCondition();
    myFile.close();
    return 0;*/
}

/*int main()
{
    vector <Pokemon *> pokemonList(40);
    readPokemonList(pokemonList);
    return 0;
}*/
