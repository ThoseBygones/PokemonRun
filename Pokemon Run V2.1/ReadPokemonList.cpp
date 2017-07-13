#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

class Pokemon
{
public:
    Pokemon(int pokeId, string pokeName, int level, int attack, int defence, int hp, double evd, double catchRate, int moneyLeft, int exp): pokeId(pokeId),pokeName(pokeName), level(level), attack(attack), defence(defence), hp(hp), evd(evd), catchRate(catchRate), moneyLeft(moneyLeft), exp(exp) {}
    void showInfo();
private:
    int pokeId;         //������
    string pokeName;    //��������
    int level;          //�ȼ�
    int attack;         //����
    int defence;        //����
    int hp;             //����
    double evd;         //�����
    double catchRate;   //������
    int moneyLeft;      //�����Ǯ
    int exp;            //���侭��
    //string stDesc;    //��������

};

/*void Pokemon::showInfo()
{
    cout << p.pokeId << " " << p.pokeName << " " << p.level << " " << p.attack << " " << p.defence << " " << p.hp << " " << p.evd << " " << p.catchRate << " " << p.moneyLeft << " " << p.exp << endl;
}*/

void Pokemon::showInfo()
{
    cout << pokeId << "  " << pokeName << "  " << level << "  " << attack << "  " << defence << "  " << hp << "  " << evd << "  " << catchRate << "  " << moneyLeft << "  " << exp << endl;
}

class FileNotFoundException: public std::runtime_error
{
public:
    FileNotFoundException(const string& errormsg): runtime_error(errormsg) {}
};

int main()
{
    string line;
    ifstream myFile;
    vector <Pokemon *> pokemonList(20);
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
            pokemonList[index] = new Pokemon(pokeId, pokeName, level, attack, defence, hp, evd, catchRate, moneyLeft, exp);
            pokemonList[index]->showInfo();
            index++;
        }
    }
    myFile.close();
    return 0;
}
