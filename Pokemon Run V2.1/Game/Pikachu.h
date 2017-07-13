#ifndef PIKACHU_H_INCLUDED
#define PIKACHU_H_INCLUDED

#include <string>
#include "Bag.h"
#include "Pokemon.h"
using namespace std;

class Pikachu
{
public:
    Pikachu(Bag bag, string pName = "Ƥ����", int pLevel = 1, int pAttack = 124, int pDefence = 118,int currentPikaAttack = 124,int currentPikaDefence = 118 ,int currentPikaHp = 100,int pHp = 100, int currentPikaExp=0,int pExp=40,double currentPikaEvd = 0.08,double pEvd = 0.08): bag(bag), pName(pName), pLevel(pLevel), pAttack(pAttack), pDefence(pDefence),currentPikaAttack(currentPikaAttack), currentPikaDefence(currentPikaDefence),  currentPikaHp(currentPikaHp),pHp(pHp),currentPikaExp(currentPikaExp),pExp(pExp),currentPikaEvd(currentPikaEvd), pEvd(pEvd) {}
    bool combat(Pokemon&);
    void addItems();
    void use();
    void showBagContent();
    void showBagMoney();
    void showCondition();
    void showInfo();
    void showLine(string item);
    void levelUp();
    void recoverHp();
    int hurt(int value);

    string getNameValue() {return pName;}
    int getLevelValue() {return pLevel;}
    int getAttackValue() {return pAttack;}
    int getDefenceValue() {return pDefence;}
    int getCurrentHpValue() {return currentPikaHp;}
    int getHpValue() {return pHp;}
    int getCurrentExpValue() {return currentPikaExp;}
    int getExp() {return pExp;}
    double getEvdValue() {return pEvd;}

    int getBagHpnum() {return bag.Hpnum;}
    int getBagSupHpnum() {return bag.SupHpnum;}
    int getBagAttnum() {return bag.Attnum;}
    int getBagDefnum() {return bag.Defnum;}
    int getBagEvdnum() {return bag.Evdum;}
    int getBagMoney() {return bag.money;}
    bool getMedalOfCourage() {return bag.medalOfCourage;}
    bool getMedalOfWisdom() {return bag.medalOfWisdom;}
    bool getMedalOfFriendship() {return bag.medalOfFriendship;}
    bool getMedalOfHope() {return bag.medalOfHope;}
    bool getMedalOfBrightness() {return bag.medalOfBrightness;}

private:
    Bag bag;
    string pName;
    int pLevel;          //�ȼ�
    int pAttack;        //����
    int pDefence; //����
    int currentPikaAttack;		//��ǰ����
    int currentPikaDefence;		//��ǰ����
    int currentPikaHp;  //��ǰ����
    int pHp;         //����
    int currentPikaExp;		//��ǰ����
    int pExp;       //�������辭��
    double currentPikaEvd;		//��ǰ�����
    double pEvd;            //�����
};

#endif // PIKACHU_H_INCLUDED
