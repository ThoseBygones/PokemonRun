#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Pikachu.h"
using namespace std;

void Pikachu::showLine(string item)
{
    cout << item;
}

void Pikachu::showInfo()
{
    cout << "******************************" << endl;
    showLine("  ");
    cout << pName << endl;
    showLine("  �ȼ���");
    cout << pLevel << endl;
    showLine("  ����ֵ��");
    cout << currentPikaHp << " / " << pHp << endl;
    showLine("  ����ֵ��");
    cout << currentPikaExp << " / " << pExp <<endl;
    cout << "******************************" << endl;
}

void Pikachu::showCondition()
{
    system("cls");
    cout << "******************************" << endl;
    showLine("*  ������֣�");
    cout << setfill(' ');
    cout << setw(16) << left << pName << "*" << endl;
    showLine("*  ��ĵȼ���");
    cout << setw(16) << left << pLevel << "*" << endl;
    showLine("*  ����ֵ��");
    cout << setw(4) << right << currentPikaExp << " / " << setw(11) << left << pExp << "*" <<endl;
    showLine("*  ��������");
    cout << setw(18) << left << pAttack << "*" <<endl;
    showLine("*  ��������");
    cout << setw(18) << left << pDefence << "*" <<endl;
    showLine("*  ����ֵ��");
    cout << setw(3) << right << currentPikaHp << " / " << setw(12) << left << pHp << "*" <<endl;
    showLine("*  ����ʣ�");
    cout << setw(18) << left << pEvd << "*" <<endl;
    cout << "******************************" << endl;
    system("pause");
}

void Pikachu::addItems()
{
    char shoppingchoice;
    int amount;
    cin >> shoppingchoice;
    switch(shoppingchoice)
    {
    case '1':
    {
        cout << "����Ҫ����ٸ���" << endl;
        cout << "������������" << endl;
        cin >> amount;
        if(cin.fail())      //������������
        {
            cerr << "������������" << endl;
            system("pause");
            cin.clear ();
            break;
        }
        if(amount < 0 || amount * 30 > bag.money)
        {
            cout << "������󣬻����Ǯ������..." << endl;
            system("pause");
            break;
        }
        bag.Hpnum += amount;
        bag.money -= amount * 30;
        cout << "����ɹ���" << endl;
        system("pause");
        break;
    }

    case '2':
    {
        cout << "����Ҫ�򼸸���" << endl;
        cin >> amount;
        if(cin.fail())
        {
            cerr << "������������" << endl;
            system("pause");
            cin.clear();
            break;
        }
        if(amount < 0 || amount * 80 > bag.money)
        {
            cout << "������󣬻����Ǯ������..." << endl;
            system("pause");
            break;
        }

        bag.SupHpnum += amount;
        bag.money -= amount * 80;
        cout << "����ɹ���" << endl;
        system("pause");
        break;
    }

    case '3':
    {
        cout << "����Ҫ�򼸸���" << endl;
        cin >> amount;
        if(cin.fail())      //������������
        {
            cerr << "������������" << endl;
            system("pause");
            cin.clear();
            break;
        }
        if(amount < 0 || amount * 50 > bag.money)
        {
            cout << "�Բ������Ǯ������..."<<endl;
            system("pause");
            break;
        }
        bag.Attnum += amount;
        bag.money -= amount * 50;
        cout << "����ɹ���" << endl;
        system("pause");
        break;
    }

    case '4':
    {
        cout << "����Ҫ�򼸸���" << endl;
        cin >> amount;
        if(cin.fail())      //������������
        {
            cerr << "������������" << endl;
            system("pause");
            cin.clear();
            break;
        }
        if(amount < 0 || amount * 50 > bag.money)
        {
            cout << "�Բ������Ǯ������..." << endl;
            system("pause");
            break;
        }
        bag.Defnum += amount;
        bag.money -= amount * 50;
        cout << "����ɹ���" << endl;
        system("pause");
        break;
    }

    case '5':
    {
        cout << "����Ҫ�򼸸���" << endl;
        cin >> amount;
        if(cin.fail())      //������������
        {
            cerr << "������������" << endl;
            system("pause");
            cin.clear();
            break;
        }
        if(amount < 0 || amount * 50 > bag.money)
        {
            cout << "�Բ������Ǯ������..." << endl;
            system("pause");
            break;
        }
        bag.Evdum += amount;
        bag.money -= amount * 50;
        cout << "����ɹ���" << endl;
        system("pause");
        break;
    }

    case '0':
    {
        cout << "��ӭ�ٴι���~" << endl;
        system("pause");
        return;
    }

    default:
    {
        cout << "������������" << endl;
        system("pause");
        break;
    }

    }

}

void Pikachu::use()
{
    char useoperation;
    cout << endl
         << "����ʹ��ʲô���ߣ�" << endl
         << "******************************" << endl
         << "*  1.�ظ�ҩˮ    2.����ҩˮ  *" << endl
         << "*  3.����ҩˮ    4.����ҩˮ  *" << endl
         << "*  5.����ҩˮ    0.�˳�      *" << endl
         << "******************************" << endl << endl
         << "��ѡ��";
    while(cin >> useoperation)
    {
        switch(useoperation)
        {
        case '1':
            if(bag.Hpnum <= 0)
            {
                cout << "�Բ�����û�лظ�ҩˮ�ˣ�~" << endl;
                break;
            }
            else
            {
                currentPikaHp = (currentPikaHp + 50) > pHp ? pHp : (currentPikaHp + 50);
                cout << "ʹ������ҩˮ�ɹ�����������50��" << endl;
                bag.Hpnum --;	 	//pika.showCondition();
            }
            break;
        case '2':
            if(bag.SupHpnum <= 0)
            {
                cout << "�Բ�����û�г���ҩˮ��..." << endl;
                break;
            }
            else
            {
                currentPikaHp = (currentPikaHp + 100) > pHp ? pHp : (currentPikaHp + 100);
                cout << "ʹ�ó���ҩˮ�ɹ�����������100��" << endl;
                bag.SupHpnum--;	 	//pika.showCondition();
            }
            break;
        case '3':
            if (bag.Attnum <= 0)
            {
                cout << "�Բ�����û������ҩˮ��..." << endl;
                break;
            }
            else
            {
                currentPikaAttack += 50;
                cout << "ʹ������ҩˮ�ɹ�������������50��" << endl;
                bag.Attnum--;	 	//pika.showCondition();
            }
            break;
        case '4':
            if (bag.Defnum <= 0)
            {
                cout << "�Բ�����û�з���ҩˮ��..." << endl;
                break;
            }
            else
            {
                currentPikaDefence += 50;
                cout << "ʹ�÷���ҩˮ�ɹ�������������50��" << endl;
                bag.Defnum--;	 	//pika.showCondition();
            }
            break;
        case '5':
            if (bag.Evdum <= 0)
            {
                cout << "�Բ�����û��Ѹ��ҩˮ��..." << endl;
                break;
            }
            else
            {
                //currentPikaEvd+=0.2;
                currentPikaEvd = (currentPikaEvd + 0.2) > 1 ? 1 : (currentPikaEvd + 0.2);
                cout << "ʹ��Ѹ��ҩˮ�ɹ������������20%" << endl;
                bag.Evdum--;
                //pika.showCondition();
            }
            break;
        case '0':
        {
            system("pause");
            return;
        }

        default:
            cout << "������������!" << endl;
            break;
        }
        system("pause");
        system("cls");
        cout << "������ʹ��ʲô���ߣ�" << endl
             << "******************************" << endl
             << "*  1.�ظ�ҩˮ    2.����ҩˮ  *" << endl
             << "*  3.����ҩˮ    4.����ҩˮ  *" << endl
             << "*  5.����ҩˮ    0.�˳�      *" << endl
             << "******************************" << endl << endl
             << "��ѡ��";
    }
}

void Pikachu::showBagContent()
{
    bag.showBag();
}

void Pikachu::showBagMoney()
{
    bag.showMoney();
}

int Pikachu::hurt(int value)
{
    int hurtValue = value * 2 / (1 + currentPikaDefence / 10) + (rand() % 10 - 5);
    currentPikaHp -= hurtValue;
    if(currentPikaHp < 0)
        currentPikaHp = 0;
    return hurtValue;
}

void Pikachu::levelUp()
{
    pAttack += 10;
    pDefence += 5;
    pHp += 10;
    pExp = 40 * pLevel;
}

void Pikachu::recoverHp()
{
    currentPikaHp = pHp;
    cout << "�ظ��ɹ������Լ���ð����~" << endl;
    system("pause");
}
