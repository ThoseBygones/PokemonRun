#include <iostream>
#include <cstdlib>
#include <string>
#include "MicroMap.h"
using namespace std;

void MicroMap::showMap()
{
    system("cls");
    cout << "********************************************************************************" << endl;    //80个*
    cout << "*                                                                              *" << endl;
    cout << "*  ##########          @@@@@@@@@@@@          ##########                        *" << endl;
    cout << "*  ";
    showCity("飞龙市");
    cout << "==========";
    showHabitat("迷雾森林");
    cout << "==========";
    showCity("静水市");
    cout << "                        *" << endl;
    cout << "*  ##########          @@@@@@@@@@@@          ##########                        *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                      ############          ##########          @@@@@@@@@@@@  *" << endl;
    cout << "*                      ";
    showCity("精灵联盟");
    cout << "          ";
    showCity("银叶市");
    cout << "==========";
    showHabitat("战斗乐园");
    cout << "  *" << endl;
    cout << "*                      ############          ##########          @@@@@@@@@@@@  *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                            ##########           ##########   *" << endl;
    cout << "*                                            ";
    showCity("田园市");
    cout << "===========";
    showCity("雪枫镇");
    cout << "   *"<< endl;
    cout << "*                                            ##########           ##########   *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "********************************************************************************" << endl;
}

void MicroMap::showCity(string cityName)
{
    cout << "# " << cityName << " #";
}

void MicroMap::showHabitat(string habitatName)
{
    cout << "@ " << habitatName << " @";
}
