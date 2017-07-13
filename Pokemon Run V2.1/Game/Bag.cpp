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
    cout << "�㵱ǰӵ�н�ң�" << money << endl;
}
void Bag::showBag()
{

    system("cls");
    cout << "�㵱ǰӵ��:" << endl;
    cout << "******************************" << endl;
    cout << "*                            *" << endl;
    cout << "* ��Ʒ�ࣺ                   *" << endl;
    cout << "*  ";
    showLine1("�ظ�ҩˮ:");
    cout << setfill(' ') << setw(3) << right << Hpnum << "��            *" << endl;
    cout << "*  ";
    showLine1("����ҩˮ:");
    cout << setw(3) << right << SupHpnum << "��            *" << endl;
    cout << "*  ";
    showLine1("����ҩˮ:");
    cout << setw(3) << right << Attnum << "��            *" << endl;
    cout << "*  ";
    showLine1("����ҩˮ:");
    cout << setw(3) << right << Defnum << "��            *" << endl;
    cout << "*  ";
    showLine1("Ѹ��ҩˮ:");
    cout << setw(3) << right << Evdum << "��            *" << endl;
    cout << "*  ";
    showLine1("���:");
    cout << setw(8) << right << money << "��           *" << endl;
    cout << "*                            *" << endl;
    cout << "******************************" << endl;
    cout << "*                            *" << endl;
    cout << "* �����ࣺ                   *" << endl;
    if(!medalOfCourage && !medalOfWisdom && !medalOfFriendship && !medalOfHope && !medalOfBrightness)
        cout << "*  ��                        *" << endl;
    else
    {
        if(medalOfCourage)
            cout << "*  ��������                  *" << endl;
        if(medalOfWisdom)
            cout << "*  �ǻۻ���                  *" << endl;
        if(medalOfFriendship)
            cout << "*  �������                  *" << endl;
        if(medalOfHope)
            cout << "*  ϣ������                  *" << endl;
        if(medalOfBrightness)
            cout << "*  ��������                  *" << endl;
    }
    cout << "*                            *" << endl;
    cout << "******************************" << endl;
}

