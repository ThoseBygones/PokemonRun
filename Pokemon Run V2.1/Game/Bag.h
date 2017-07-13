#ifndef BAG_H_INCLUDED
#define BAG_H_INCLUDED

#include <string>
using namespace std;

class Bag
{
public:
    Bag(int Hpnum = 1, int SupHpnum = 0, int Attnum = 0, int Defnum = 0, int Evdum = 0, int money = 100, bool medalOfCourage = false, bool medalOfWisdom = false, bool medalOfFriendship = false, bool medalOfHope = false, bool medalOfBrightness = false) : Hpnum(Hpnum), SupHpnum(SupHpnum), Attnum(Attnum), Defnum(Defnum), Evdum(Evdum), money(money), medalOfCourage(medalOfCourage), medalOfWisdom(medalOfWisdom), medalOfFriendship(medalOfFriendship), medalOfHope(medalOfHope), medalOfBrightness(medalOfBrightness) {}
    void showBag();
    void showMoney();
    void showLine1(string item);
    int Hpnum;
    int SupHpnum;
    int Attnum;
    int Defnum;
    int Evdum;
    int money;
    bool medalOfCourage;
    bool medalOfWisdom;
    bool medalOfFriendship;
    bool medalOfHope;
    bool medalOfBrightness;
};

#endif // BAG_H_INCLUDED
