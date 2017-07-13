#include <iostream>
#include <string>
#include <cstdlib>
#include "PokemonStore.h"
#include "Pikachu.h"

using namespace std;

void PokemonStore::showShop(Pikachu &pikachu)
{
    system("cls");
    pikachu.showBagMoney();
    cout << "你要购买什么？" << endl
         << "***********************************************" << endl
         << "*  1.回复药水(30/1个)     2.超级药水(80/1个)  *" << endl
         << "*  3.力量药水(50/1个)     4.防御药水(50/1个)  *" << endl
         << "*  5.敏捷药水(50/1个)     0.退出              *" << endl
         << "***********************************************" << endl << endl
         << "请选择：";
}
