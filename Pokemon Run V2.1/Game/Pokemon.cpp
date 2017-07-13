#include <iostream>
#include <string>
#include <cstdlib>
#include "Pokemon.h"
using namespace std;

void Pokemon::showLine(string item)
{
    cout << "  " << item;
}

void Pokemon::showInfo()
{
    cout << "******************************" << endl;
    showLine("");
    cout << pokeName << endl;
    showLine("等级：");
    cout << level << endl;
    showLine("生命值：");
    cout << currentHp << " / " << hp << endl;
    cout << "******************************" << endl;
}

int Pokemon::hurt(int value)
{
    int hurtValue = value * 2 / (1 + defence / 10) + (rand() % 10 - 5);
    currentHp -= hurtValue;
    if(currentHp < 0)
        currentHp = 0;
    return hurtValue;
}
