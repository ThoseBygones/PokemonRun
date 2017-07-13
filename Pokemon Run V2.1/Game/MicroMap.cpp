#include <iostream>
#include <cstdlib>
#include <string>
#include "MicroMap.h"
using namespace std;

void MicroMap::showMap()
{
    system("cls");
    cout << "********************************************************************************" << endl;    //80��*
    cout << "*                                                                              *" << endl;
    cout << "*  ##########          @@@@@@@@@@@@          ##########                        *" << endl;
    cout << "*  ";
    showCity("������");
    cout << "==========";
    showHabitat("����ɭ��");
    cout << "==========";
    showCity("��ˮ��");
    cout << "                        *" << endl;
    cout << "*  ##########          @@@@@@@@@@@@          ##########                        *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                           ||                   ||                            *" << endl;
    cout << "*                      ############          ##########          @@@@@@@@@@@@  *" << endl;
    cout << "*                      ";
    showCity("��������");
    cout << "          ";
    showCity("��Ҷ��");
    cout << "==========";
    showHabitat("ս����԰");
    cout << "  *" << endl;
    cout << "*                      ############          ##########          @@@@@@@@@@@@  *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                                ||                   ||       *" << endl;
    cout << "*                                            ##########           ##########   *" << endl;
    cout << "*                                            ";
    showCity("��԰��");
    cout << "===========";
    showCity("ѩ����");
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
