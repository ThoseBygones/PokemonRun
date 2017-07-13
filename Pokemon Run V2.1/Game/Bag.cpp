#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "Bag.h"
using namespace std ;


void Bag::showLine1(string item)
{
    cout << item;
}
void Bag::showMoney()
{
    cout << "你当前拥有金币：" << money << endl;
}
void Bag::showBag()
{

    system("cls");
    cout << "你当前拥有:" << endl;
    cout << "******************************" << endl;
    cout << "*                            *" << endl;
    cout << "* 物品类：                   *" << endl;
    cout << "*  ";
    showLine1("回复药水:");
    cout << setfill(' ') << setw(3) << right << Hpnum << "个            *" << endl;
    cout << "*  ";
    showLine1("超级药水:");
    cout << setw(3) << right << SupHpnum << "个            *" << endl;
    cout << "*  ";
    showLine1("力量药水:");
    cout << setw(3) << right << Attnum << "个            *" << endl;
    cout << "*  ";
    showLine1("防御药水:");
    cout << setw(3) << right << Defnum << "个            *" << endl;
    cout << "*  ";
    showLine1("迅捷药水:");
    cout << setw(3) << right << Evdum << "个            *" << endl;
    cout << "*  ";
    showLine1("金币:");
    cout << setw(8) << right << money << "个           *" << endl;
    cout << "*                            *" << endl;
    cout << "******************************" << endl;
    cout << "*                            *" << endl;
    cout << "* 徽章类：                   *" << endl;
    if(!medalOfCourage && !medalOfWisdom && !medalOfFriendship && !medalOfHope && !medalOfBrightness)
        cout << "*  无                        *" << endl;
    else
    {
        if(medalOfCourage)
            cout << "*  勇气徽章                  *" << endl;
        if(medalOfWisdom)
            cout << "*  智慧徽章                  *" << endl;
        if(medalOfFriendship)
            cout << "*  友情徽章                  *" << endl;
        if(medalOfHope)
            cout << "*  希望徽章                  *" << endl;
        if(medalOfBrightness)
            cout << "*  光明徽章                  *" << endl;
    }
    cout << "*                            *" << endl;
    cout << "******************************" << endl;
}

