#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

#include <string>
using namespace std;

class Pokemon
{
public:
    Pokemon(int pokeId, string pokeName, int level, int attack, int defence, int hp, int currentHp, double evd, double catchRate, int moneyLeft, int exp): pokeId(pokeId),pokeName(pokeName), level(level), attack(attack), defence(defence), hp(hp), currentHp(currentHp), evd(evd), catchRate(catchRate), moneyLeft(moneyLeft), exp(exp) {}
    void showInfo();
    void showLine(string);
    int hurt(int value);
    int getCurrentHp() {return currentHp;}
    int getAttack() {return attack;}
    int getMoneyLeft(){return moneyLeft;}
    int getExp(){return exp;}
    double getEvd(){return evd;}
    string getPokeName() {return pokeName;}
private:
    int pokeId;         //������
    string pokeName;    //��������
    int level;          //�ȼ�
    int attack;         //����
    int defence;        //����
    int hp;             //����
    int currentHp;      //��ǰ����
    double evd;         //�����
    double catchRate;   //������
    int moneyLeft;      //�����Ǯ
    int exp;            //���侭��
    //string stDesc;    //��������
};

#endif // POKEMON_H_INCLUDED
