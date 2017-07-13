#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
using namespace std;

class MicroMap
{
public:
    void showMap();
    void showCity(string cityName);
    void showHabitat(string habitatName);
};

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

int main()
{
    MicroMap micromap;
    micromap.showMap();
    system("pause");
    return 0;
}
