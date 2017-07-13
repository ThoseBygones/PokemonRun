#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
//#include "Error.h"
//#include "Pokemon.h"
using namespace std;

//extern vector <Pokemon *> pokemonList(40);

int main()
{
    string line;
    ifstream saveFile;
    int index = 0;
    saveFile.open("PokemonListTest.txt", ios_base::in);
    if(!saveFile)
    {
        cout << "The save file does not exist!" << endl;
    }
    else
    {
        while(!saveFile.eof())
        {
            getline(saveFile, line);
            istringstream is(line);
            int a;
            double b;
            string c;
            is >> a >> b >> c;
            cout << a << " " << b << " " << c;
        }
    }
    return 0;
}

/*int main()
{
    vector <Pokemon *> pokemonList(40);
    readPokemonList(pokemonList);
    return 0;
}*/
