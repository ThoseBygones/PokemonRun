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
    int pokeId;         //精灵编号
    string pokeName;    //精灵名称
    int level;          //等级
    int attack;         //攻击
    int defence;        //防御
    int hp;             //生命
    int currentHp;      //当前生命
    double evd;         //躲避率
    double catchRate;   //捕获率
    int moneyLeft;      //掉落金钱
    int exp;            //掉落经验
    //string stDesc;    //精灵描述
};

#endif // POKEMON_H_INCLUDED
