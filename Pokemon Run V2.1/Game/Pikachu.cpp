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
    showLine("  等级：");
    cout << pLevel << endl;
    showLine("  生命值：");
    cout << currentPikaHp << " / " << pHp << endl;
    showLine("  经验值：");
    cout << currentPikaExp << " / " << pExp <<endl;
    cout << "******************************" << endl;
}

void Pikachu::showCondition()
{
    system("cls");
    cout << "******************************" << endl;
    showLine("*  你的名字：");
    cout << setfill(' ');
    cout << setw(16) << left << pName << "*" << endl;
    showLine("*  你的等级：");
    cout << setw(16) << left << pLevel << "*" << endl;
    showLine("*  经验值：");
    cout << setw(4) << right << currentPikaExp << " / " << setw(11) << left << pExp << "*" <<endl;
    showLine("*  攻击力：");
    cout << setw(18) << left << pAttack << "*" <<endl;
    showLine("*  防御力：");
    cout << setw(18) << left << pDefence << "*" <<endl;
    showLine("*  生命值：");
    cout << setw(3) << right << currentPikaHp << " / " << setw(12) << left << pHp << "*" <<endl;
    showLine("*  躲避率：");
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
        cout << "请问要买多少个？" << endl;
        cout << "请输入数量：" << endl;
        cin >> amount;
        if(cin.fail())      //输入流错误处理
        {
            cerr << "您的输入有误！" << endl;
            system("pause");
            cin.clear ();
            break;
        }
        if(amount < 0 || amount * 30 > bag.money)
        {
            cout << "输入错误，或你的钱不够了..." << endl;
            system("pause");
            break;
        }
        bag.Hpnum += amount;
        bag.money -= amount * 30;
        cout << "购买成功！" << endl;
        system("pause");
        break;
    }

    case '2':
    {
        cout << "请问要买几个？" << endl;
        cin >> amount;
        if(cin.fail())
        {
            cerr << "您的输入有误！" << endl;
            system("pause");
            cin.clear();
            break;
        }
        if(amount < 0 || amount * 80 > bag.money)
        {
            cout << "输入错误，或你的钱不够了..." << endl;
            system("pause");
            break;
        }

        bag.SupHpnum += amount;
        bag.money -= amount * 80;
        cout << "购买成功！" << endl;
        system("pause");
        break;
    }

    case '3':
    {
        cout << "请问要买几个？" << endl;
        cin >> amount;
        if(cin.fail())      //输入流错误处理
        {
            cerr << "您的输入有误！" << endl;
            system("pause");
            cin.clear();
            break;
        }
        if(amount < 0 || amount * 50 > bag.money)
        {
            cout << "对不起，你的钱不够了..."<<endl;
            system("pause");
            break;
        }
        bag.Attnum += amount;
        bag.money -= amount * 50;
        cout << "购买成功！" << endl;
        system("pause");
        break;
    }

    case '4':
    {
        cout << "请问要买几个？" << endl;
        cin >> amount;
        if(cin.fail())      //输入流错误处理
        {
            cerr << "您的输入有误！" << endl;
            system("pause");
            cin.clear();
            break;
        }
        if(amount < 0 || amount * 50 > bag.money)
        {
            cout << "对不起，你的钱不够了..." << endl;
            system("pause");
            break;
        }
        bag.Defnum += amount;
        bag.money -= amount * 50;
        cout << "购买成功！" << endl;
        system("pause");
        break;
    }

    case '5':
    {
        cout << "请问要买几个？" << endl;
        cin >> amount;
        if(cin.fail())      //输入流错误处理
        {
            cerr << "您的输入有误！" << endl;
            system("pause");
            cin.clear();
            break;
        }
        if(amount < 0 || amount * 50 > bag.money)
        {
            cout << "对不起，你的钱不够了..." << endl;
            system("pause");
            break;
        }
        bag.Evdum += amount;
        bag.money -= amount * 50;
        cout << "购买成功！" << endl;
        system("pause");
        break;
    }

    case '0':
    {
        cout << "欢迎再次光临~" << endl;
        system("pause");
        return;
    }

    default:
    {
        cout << "您的输入有误！" << endl;
        system("pause");
        break;
    }

    }

}

void Pikachu::use()
{
    char useoperation;
    cout << endl
         << "您想使用什么道具？" << endl
         << "******************************" << endl
         << "*  1.回复药水    2.超级药水  *" << endl
         << "*  3.力量药水    4.防御药水  *" << endl
         << "*  5.敏捷药水    0.退出      *" << endl
         << "******************************" << endl << endl
         << "请选择：";
    while(cin >> useoperation)
    {
        switch(useoperation)
        {
        case '1':
            if(bag.Hpnum <= 0)
            {
                cout << "对不起，你没有回复药水了！~" << endl;
                break;
            }
            else
            {
                currentPikaHp = (currentPikaHp + 50) > pHp ? pHp : (currentPikaHp + 50);
                cout << "使用生命药水成功，生命增加50点" << endl;
                bag.Hpnum --;	 	//pika.showCondition();
            }
            break;
        case '2':
            if(bag.SupHpnum <= 0)
            {
                cout << "对不起，你没有超级药水了..." << endl;
                break;
            }
            else
            {
                currentPikaHp = (currentPikaHp + 100) > pHp ? pHp : (currentPikaHp + 100);
                cout << "使用超级药水成功，生命增加100点" << endl;
                bag.SupHpnum--;	 	//pika.showCondition();
            }
            break;
        case '3':
            if (bag.Attnum <= 0)
            {
                cout << "对不起，你没有力量药水了..." << endl;
                break;
            }
            else
            {
                currentPikaAttack += 50;
                cout << "使用力量药水成功，攻击力增加50点" << endl;
                bag.Attnum--;	 	//pika.showCondition();
            }
            break;
        case '4':
            if (bag.Defnum <= 0)
            {
                cout << "对不起，你没有防御药水了..." << endl;
                break;
            }
            else
            {
                currentPikaDefence += 50;
                cout << "使用防御药水成功，防御力增加50点" << endl;
                bag.Defnum--;	 	//pika.showCondition();
            }
            break;
        case '5':
            if (bag.Evdum <= 0)
            {
                cout << "对不起，你没有迅捷药水了..." << endl;
                break;
            }
            else
            {
                //currentPikaEvd+=0.2;
                currentPikaEvd = (currentPikaEvd + 0.2) > 1 ? 1 : (currentPikaEvd + 0.2);
                cout << "使用迅捷药水成功，躲避率增加20%" << endl;
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
            cout << "您的输入有误!" << endl;
            break;
        }
        system("pause");
        system("cls");
        cout << "您还想使用什么道具？" << endl
             << "******************************" << endl
             << "*  1.回复药水    2.超级药水  *" << endl
             << "*  3.力量药水    4.防御药水  *" << endl
             << "*  5.敏捷药水    0.退出      *" << endl
             << "******************************" << endl << endl
             << "请选择：";
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
    cout << "回复成功！可以继续冒险了~" << endl;
    system("pause");
}
