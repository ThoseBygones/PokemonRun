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
    cout << "��Ҫ����ʲô��" << endl
         << "***********************************************" << endl
         << "*  1.�ظ�ҩˮ(30/1��)     2.����ҩˮ(80/1��)  *" << endl
         << "*  3.����ҩˮ(50/1��)     4.����ҩˮ(50/1��)  *" << endl
         << "*  5.����ҩˮ(50/1��)     0.�˳�              *" << endl
         << "***********************************************" << endl << endl
         << "��ѡ��";
}
