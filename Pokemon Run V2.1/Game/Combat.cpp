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
        cout << "*  1.普通攻击  2.特殊技能  3.使用物品  4.查看状态  5.逃跑  *" << endl;
        cout << "*                                                          *" << endl;
        cout << "************************************************************" << endl;
        cout << "请选择：";
        cin >> choice;

        switch (choice)
        {
        case '1' :
        {
            cout << "你攻击了" << currentPoke.getPokeName() << "！" ;
            int tempEvdValue = currentPoke.getEvd() * 100;
            int randomValue = rand() % 100 + 1;
            if(randomValue <= tempEvdValue)
            {
                cout << currentPoke.getPokeName() << "躲避了你的攻击！" << endl;
            }
            else
            {
                int tempHurtValue = currentPoke.hurt(currentPikaAttack);
                cout << "造成了" << tempHurtValue << "点伤害！" <<endl;
            }
            system("pause");
            system("cls");

            currentPoke.showInfo();
            cout << "              VS" << endl;
            showInfo();

            if(currentPoke.getCurrentHp() > 0)
            {
                cout << currentPoke.getPokeName() << "攻击了你！" ;
                tempEvdValue = currentPikaEvd * 100;
                randomValue = rand() % 100 + 1;
                if(randomValue <= tempEvdValue)
                {
                    cout << "你躲避了" << currentPoke.getPokeName() << "的攻击！"<< endl;
                }
                else
                {
                    int tempHurtValue = hurt(currentPoke.getAttack());
                    cout << "造成了" << tempHurtValue << "点伤害！" <<endl;
                }
                system("pause");

                if(currentPikaHp <= 0)
                {
                    cout << "你的生命值降为0，战斗结束。" << endl;
                    system("pause");
                    if(bag.money >= 200)
                    {
                        int moneyLost = 200;
                        bag.money -= moneyLost;
                        cout << "你因为战斗失败损失了金币200" << endl;
                        system("pause");
                    }
                    currentPikaHp += 1;
                    return true;
                }
            }
            else
            {
                cout << "你击败了" << currentPoke.getPokeName() << "获得了胜利！" << endl;
                cout << "你获得了经验值：" << currentPoke.getExp() << endl;
                cout << "你获得了金币：" << currentPoke.getMoneyLeft() << endl;
                bag.money += currentPoke.getMoneyLeft();
                currentPikaExp += currentPoke.getExp();
                if(currentPikaExp >= pExp)
                {
                    currentPikaExp = currentPikaExp - pExp;
                    pLevel++;
                    cout << "恭喜你，升到了" << pLevel << "级！" << endl;
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
                cout << "怒气不足！" << endl;
                system("pause");
                break;
            }
            else
            {
                cout << "你使用了特殊技能:十万伏特！" << endl;
                system("pause");
                cout << "皮卡~~~~丘~~~~~！！！" << endl;
                system("pause");
                int tempHurtValue = currentPoke.hurt(currentPikaAttack + pLevel * 30);
                cout << "造成了" << tempHurtValue << "点伤害！" <<endl;
            }
            system("pause");
            system("cls");

            currentPoke.showInfo();
            cout << "              VS" << endl;
            showInfo();

            if(currentPoke.getCurrentHp() > 0)
            {
                cout << currentPoke.getPokeName() << "攻击了你！" ;
                int tempEvdValue = currentPikaEvd * 100;
                int randomValue = rand() % 100 + 1;
                if(randomValue <= tempEvdValue)
                {
                    cout << "你躲避了" << currentPoke.getPokeName() << "的攻击！"<< endl;
                }
                else
                {
                    int tempHurtValue = hurt(currentPoke.getAttack());
                    cout << "造成了" << tempHurtValue << "点伤害！" <<endl;
                }
                system("pause");

                if(currentPikaHp <= 0)
                {
                    cout << "你的生命值降为0，游戏结束。"<<endl;
                    system("pause");
                    if(bag.money >= 200)
                    {
                        int moneyLost = 200;
                        bag.money -= moneyLost;
                        cout << "你因为战斗失败损失了金币200" << endl;
                        system("pause");
                    }
                    currentPikaHp += 1;
                    return true;
                }
            }
            else
            {
                cout << "你击败了" << currentPoke.getPokeName() << "获得了胜利！" << endl;
                cout << "你获得了经验值：" << currentPoke.getExp() << endl;
                cout << "你获得了金币：" << currentPoke.getMoneyLeft() << endl;
                bag.money += currentPoke.getMoneyLeft();
                currentPikaExp += currentPoke.getExp();
                if(currentPikaExp >= pExp)
                {
                    currentPikaExp = currentPikaExp - pExp;
                    pLevel++;
                    cout << "恭喜你，升到了" << pLevel << "级！" << endl;
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
            cout << "逃跑成功！" << endl;
            currentPikaAttack = pAttack;
            currentPikaDefence = pDefence;
            currentPikaEvd = pEvd;
            return false;
        }
        default:
        {
            cout << "您的输入有误，请重新输入" << endl;
            system("pause");
            break;
        }
        }
    }
    return false;
}
