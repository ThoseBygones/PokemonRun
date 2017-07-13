#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>
#include "Pikachu.h"
#include "Pokemon.h"
#include "Bag.h"
using namespace std;

bool Pikachu::combat(Pokemon &currentPoke)
{
    char choice;
    currentPikaAttack = pAttack;
    currentPikaDefence = pDefence;
    currentPikaEvd = pEvd;
    while(true)
    {
        system("cls");
        currentPoke.showInfo();
        cout << "              VS" << endl;
        showInfo();
        cout << endl;
        cout << "************************************************************" << endl;
        cout << "*                                                          *" << endl;
        cout << "*  1.��ͨ����  2.���⼼��  3.ʹ����Ʒ  4.�鿴״̬  5.����  *" << endl;
        cout << "*                                                          *" << endl;
        cout << "************************************************************" << endl;
        cout << "��ѡ��";
        cin >> choice;

        switch (choice)
        {
        case '1' :
        {
            cout << "�㹥����" << currentPoke.getPokeName() << "��" ;
            int tempEvdValue = currentPoke.getEvd() * 100;
            int randomValue = rand() % 100 + 1;
            if(randomValue <= tempEvdValue)
            {
                cout << currentPoke.getPokeName() << "�������Ĺ�����" << endl;
            }
            else
            {
                int tempHurtValue = currentPoke.hurt(currentPikaAttack);
                cout << "�����" << tempHurtValue << "���˺���" <<endl;
            }
            system("pause");
            system("cls");

            currentPoke.showInfo();
            cout << "              VS" << endl;
            showInfo();

            if(currentPoke.getCurrentHp() > 0)
            {
                cout << currentPoke.getPokeName() << "�������㣡" ;
                tempEvdValue = currentPikaEvd * 100;
                randomValue = rand() % 100 + 1;
                if(randomValue <= tempEvdValue)
                {
                    cout << "������" << currentPoke.getPokeName() << "�Ĺ�����"<< endl;
                }
                else
                {
                    int tempHurtValue = hurt(currentPoke.getAttack());
                    cout << "�����" << tempHurtValue << "���˺���" <<endl;
                }
                system("pause");

                if(currentPikaHp <= 0)
                {
                    cout << "�������ֵ��Ϊ0��ս��������" << endl;
                    system("pause");
                    if(bag.money >= 200)
                    {
                        int moneyLost = 200;
                        bag.money -= moneyLost;
                        cout << "����Ϊս��ʧ����ʧ�˽��200" << endl;
                        system("pause");
                    }
                    currentPikaHp += 1;
                    return true;
                }
            }
            else
            {
                cout << "�������" << currentPoke.getPokeName() << "�����ʤ����" << endl;
                cout << "�����˾���ֵ��" << currentPoke.getExp() << endl;
                cout << "�����˽�ң�" << currentPoke.getMoneyLeft() << endl;
                bag.money += currentPoke.getMoneyLeft();
                currentPikaExp += currentPoke.getExp();
                if(currentPikaExp >= pExp)
                {
                    currentPikaExp = currentPikaExp - pExp;
                    pLevel++;
                    cout << "��ϲ�㣬������" << pLevel << "����" << endl;
                    levelUp();
                    //system("pause");
                }
                currentPikaAttack = pAttack;
                currentPikaDefence = pDefence;
                currentPikaEvd = pEvd;
                return false;
            }
            break;
        }
        case '2' :
        {
            if(currentPikaHp >= pHp/3)
            {
                cout << "ŭ�����㣡" << endl;
                system("pause");
                break;
            }
            else
            {
                cout << "��ʹ�������⼼��:ʮ����أ�" << endl;
                system("pause");
                cout << "Ƥ��~~~~��~~~~~������" << endl;
                system("pause");
                int tempHurtValue = currentPoke.hurt(currentPikaAttack + pLevel * 30);
                cout << "�����" << tempHurtValue << "���˺���" <<endl;
            }
            system("pause");
            system("cls");

            currentPoke.showInfo();
            cout << "              VS" << endl;
            showInfo();

            if(currentPoke.getCurrentHp() > 0)
            {
                cout << currentPoke.getPokeName() << "�������㣡" ;
                int tempEvdValue = currentPikaEvd * 100;
                int randomValue = rand() % 100 + 1;
                if(randomValue <= tempEvdValue)
                {
                    cout << "������" << currentPoke.getPokeName() << "�Ĺ�����"<< endl;
                }
                else
                {
                    int tempHurtValue = hurt(currentPoke.getAttack());
                    cout << "�����" << tempHurtValue << "���˺���" <<endl;
                }
                system("pause");

                if(currentPikaHp <= 0)
                {
                    cout << "�������ֵ��Ϊ0����Ϸ������"<<endl;
                    system("pause");
                    if(bag.money >= 200)
                    {
                        int moneyLost = 200;
                        bag.money -= moneyLost;
                        cout << "����Ϊս��ʧ����ʧ�˽��200" << endl;
                        system("pause");
                    }
                    currentPikaHp += 1;
                    return true;
                }
            }
            else
            {
                cout << "�������" << currentPoke.getPokeName() << "�����ʤ����" << endl;
                cout << "�����˾���ֵ��" << currentPoke.getExp() << endl;
                cout << "�����˽�ң�" << currentPoke.getMoneyLeft() << endl;
                bag.money += currentPoke.getMoneyLeft();
                currentPikaExp += currentPoke.getExp();
                if(currentPikaExp >= pExp)
                {
                    currentPikaExp = currentPikaExp - pExp;
                    pLevel++;
                    cout << "��ϲ�㣬������" << pLevel << "����" << endl;
                    levelUp();
                    //system("pause");
                }
                currentPikaAttack = pAttack;
                currentPikaDefence = pDefence;
                currentPikaEvd = pEvd;
                return false;
            }
            break;
        }
        case '3' :
        {
            showBagContent();
            use();
            break;
        }
        case '4' :
        {
            showCondition();
            break;
        }
        case '5' :
        {
            cout << "���ܳɹ���" << endl;
            currentPikaAttack = pAttack;
            currentPikaDefence = pDefence;
            currentPikaEvd = pEvd;
            return false;
        }
        default:
        {
            cout << "����������������������" << endl;
            system("pause");
            break;
        }
        }
    }
    return false;
}
