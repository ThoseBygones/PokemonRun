#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include "Map.h"
#include "GameTable.h"
#include "MicroMap.h"
#include "Pikachu.h"
#include "PokemonStore.h"
#include "Bag.h"
using namespace std;

extern int CityMap::newMapId;
extern int CityMap::newMapX;
extern int CityMap::newMapY;

Bag bag;
Pikachu pikachu(bag);
vector <Pokemon *> pokemonList(40);
extern void readPokemonList(vector <Pokemon *> &pokemonList);

int main()
{
    GameTable gametable;
    gametable.showGameTable();
    int gameIndex;
    //while(cin >> gameIndex)
    //{
    while(cin >> gameIndex)
    {
        system("cls");
        switch(gameIndex)
        {
        case(1):
        {
            cout << "正在载入游戏..." << endl;
            system("pause");
            system("cls");
            gametable.loadStory();
            //vector <Pokemon *> pokemonList(40);
            readPokemonList(pokemonList);
            vector <CityMap *> citymap(10);
            int index = 0;
            citymap[index++] = new XueFengZhen();
            citymap[index++] = new TianYuanShi();
            citymap[index++] = new YinYeShi();
            citymap[index++] = new JingShuiShi();
            citymap[index++] = new FeiLongShi();
            citymap[index++] = new JingLingLianMeng();
            citymap[index++] = new ZhanDouLeYuan();
            citymap[index++] = new MiWuSenLin();
            for(int i=0; i<index; i++)
            {
                citymap[i]->initialMap();
                if(i == 7)
                    citymap[i]->randomPokemonLocation();
            }
            char operation;
            citymap[CityMap::newMapId]->initialPlayerLocation(41,22);
            citymap[CityMap::newMapId]->showMap();
            citymap[CityMap::newMapId]->showPosition();
            gametable.showOperationTable();
            citymap[CityMap::newMapId]->showMapOperation();
            int tempId = CityMap::newMapId;
            while(cin >> operation)
            {
                switch(operation)
                {
                case('1'):
                {
                    pikachu.showBagContent();
                    pikachu.use();
                    break;
                }
                case('2'):
                {
                    MicroMap micromap;
                    micromap.showMap();
                    system("pause");
                    break;
                }
                case('3'):
                {
                    pikachu.showCondition();
                    break;
                }
                case('4'):
                {
                    gametable.showSystemTable();
                    char systemoperation;
                    while(cin >> systemoperation)
                    {
                        bool flag = 0;
                        switch(systemoperation)
                        {
                        case('1'):
                        {
                            flag = true;
                            break;
                        }
                        case('2'):
                        {
                            ofstream output;
                            fstream file[3];
                            file[0].open("PlayerSave1.txt",ios_base::in);
                            file[1].open("PlayerSave2.txt",ios_base::in);
                            file[2].open("PlayerSave3.txt",ios_base::in);
                            gametable.showSaveFilesList2(file);
                            //for(int i=0; i<=2; i++)
                            //    file[i].close();
                            char choice;
                            cin >> choice;
                            switch(choice)
                            {
                            case('1'):
                            {
                                char operation;
                                if(file[0])
                                {
                                    cout << "该存档已存在，是否覆盖？" << endl;
                                    cout << "  1.是    2.否" << endl;
                                    cout << "请输入：";
                                    cin >> operation;
                                    if(operation == '1')
                                    {
                                        output.open("PlayerSave1.txt");
                                        output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                               << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                               << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                               << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                               << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                        output.close();
                                        cout << "正在存档，请不要关闭游戏..." << endl;
                                        system("pause");
                                        cout << "游戏保存成功！" << endl;
                                        system("pause");
                                        break;
                                    }
                                    else if(operation == '2')
                                        break;
                                }
                                else
                                {
                                    output.open("PlayerSave1.txt");
                                    output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                           << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                           << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                           << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                           << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                    output.close();
                                    cout << "正在存档，请不要关闭游戏..." << endl;
                                    system("pause");
                                    cout << "游戏保存成功！" << endl;
                                    system("pause");
                                }
                                break;
                            }

                            case('2'):
                            {
                                char operation;
                                if(file[1])
                                {
                                    cout << "该存档已存在，是否覆盖？" << endl;
                                    cout << "  1.是    2.否" << endl;
                                    cout << "请输入：";
                                    cin >> operation;
                                    if(operation == '1')
                                    {
                                        output.open("PlayerSave2.txt");
                                        output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                               << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                               << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                               << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                               << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                        output.close();
                                        cout << "正在存档，请不要关闭游戏..." << endl;
                                        system("pause");
                                        cout << "游戏保存成功！" << endl;
                                        system("pause");
                                        break;
                                    }
                                    else if(operation == '2')
                                        break;
                                }
                                else
                                {
                                    output.open("PlayerSave2.txt");
                                    output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                           << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                           << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                           << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                           << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                    output.close();
                                    cout << "正在存档，请不要关闭游戏..." << endl;
                                    system("pause");
                                    cout << "游戏保存成功！" << endl;
                                    system("pause");
                                }
                                break;
                            }
                            case('3'):
                            {
                                char operation;
                                if(file[2])
                                {
                                    cout << "该存档已存在，是否覆盖？" << endl;
                                    cout << "  1.是    2.否" << endl;
                                    cout << "请输入：";
                                    cin >> operation;
                                    if(operation == '1')
                                    {
                                        output.open("PlayerSave3.txt");
                                        output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                               << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                               << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                               << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                               << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                        output.close();
                                        cout << "正在存档，请不要关闭游戏..." << endl;
                                        system("pause");
                                        cout << "游戏保存成功！" << endl;
                                        system("pause");
                                        break;
                                    }
                                    else if(operation == '2')
                                        break;
                                }
                                else
                                {
                                    output.open("PlayerSave3.txt");
                                    output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                           << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                           << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                           << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                           << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                    output.close();
                                    cout << "正在存档，请不要关闭游戏..." << endl;
                                    system("pause");
                                    cout << "游戏保存成功！" << endl;
                                    system("pause");
                                }
                                break;
                            }
                            default:
                            {
                                cout << "输入有误，请重新输入！" << endl;
                                system("pause");
                                system("cls");
                            }
                            }
                            break;
                        }
                        case('3'):
                        {
                            cout << "正在读取游戏存档..." << endl;
                            string line;
                            ifstream saveFile[3];
                            saveFile[0].open("PlayerSave1.txt", ios_base::in);
                            saveFile[1].open("PlayerSave2.txt", ios_base::in);
                            saveFile[2].open("PlayerSave3.txt", ios_base::in);
                            gametable.showSaveFilesList(saveFile);
                            char choice;
                            cin >> choice;
                            int num = choice - '1';
                            if(!saveFile[num])
                            {
                                cout << "该存档不存在！" << endl;
                                system("pause");
                                break;
                            }
                            else
                            {
                                while(!saveFile[num].eof())
                                {
                                    getline(saveFile[num], line);
                                    istringstream is(line);
                                    int saveMapId;
                                    int saveMapX;
                                    int saveMapY;
                                    string saveName;
                                    int saveLevel;          //等级
                                    int saveAttack;        //攻击
                                    int saveDefence; //防御
                                    int saveCurrentHp;  //当前生命
                                    int saveHp;         //生命
                                    int saveCurrentExp;		//当前经验
                                    int saveExp;       //升级所需经验
                                    double saveEvd;

                                    int saveHpNum;
                                    int saveSupHpNum;
                                    int saveAttNum;
                                    int saveDefNum;
                                    int saveEvdNum;
                                    int saveMoney;
                                    bool saveMedalOfCourage;
                                    bool saveMedalOfWisdom;
                                    bool saveMedalOfFriendship;
                                    bool saveMedalOfHope;
                                    bool saveMedalOfBrightness;

                                    is >> saveMapId >> saveMapX >> saveMapY
                                       >> saveName >> saveLevel >> saveAttack >> saveDefence
                                       >> saveCurrentHp >> saveHp >> saveCurrentExp >> saveExp >> saveEvd
                                       >> saveHpNum >> saveSupHpNum >> saveAttNum >> saveDefNum >> saveEvdNum >> saveMoney
                                       >> saveMedalOfCourage >> saveMedalOfWisdom >> saveMedalOfFriendship >> saveMedalOfHope >> saveMedalOfBrightness;
                                    citymap[CityMap::newMapId]->deletePlayerLocation();
                                    CityMap::newMapId = saveMapId;
                                    tempId = CityMap::newMapId;
                                    citymap[CityMap::newMapId]->initialPlayerLocation(saveMapX,saveMapY);
                                    Bag tempBag(saveHpNum,saveSupHpNum,saveAttNum,saveDefNum,saveEvdNum,saveMoney,saveMedalOfCourage,saveMedalOfWisdom,saveMedalOfFriendship,saveMedalOfHope,saveMedalOfBrightness);
                                    Pikachu tempPikachu(tempBag,saveName,saveLevel,saveAttack,saveDefence,saveAttack,saveDefence,saveCurrentHp,saveHp,saveCurrentExp,saveExp,saveEvd,saveEvd);
                                    pikachu = tempPikachu;
                                    cout << "读取游戏存档成功！" << endl;
                                    system("pause");
                                }
                            }
                            saveFile[num].close();
                            break;
                        }

                        case('4'):
                        {
                            cout << "游戏结束，正在退出游戏..." << endl;
                            return 0;
                        }
                        default:
                        {
                            cout << "你的输入有误，请重新输入！" << endl;
                            system("pause");
                            break;
                        }

                        }
                        if(flag)
                            break;
                        gametable.showSystemTable();
                    }
                    break;
                }
                default:
                {
                    citymap[CityMap::newMapId]->mov(operation);
                    break;
                }
                }
                if(tempId != CityMap::newMapId)
                {
                    citymap[tempId]->deletePlayerLocation();
                    citymap[CityMap::newMapId]->initialPlayerLocation(CityMap::newMapX,CityMap::newMapY);
                    if(CityMap::newMapId == 7)
                    {
                        citymap[CityMap::newMapId]->deletePokemonLocation();
                        citymap[CityMap::newMapId]->randomPokemonLocation();
                    }
                    tempId = CityMap::newMapId;
                }
                system("cls");
                citymap[CityMap::newMapId]->showMap();
                citymap[CityMap::newMapId]->showPosition();
                gametable.showOperationTable();
                citymap[CityMap::newMapId]->showMapOperation();
            }
            break;
        }
        case(2):
        {
            readPokemonList(pokemonList);
            vector <CityMap *> citymap(10);
            int index = 0;
            citymap[index++] = new XueFengZhen();
            citymap[index++] = new TianYuanShi();
            citymap[index++] = new YinYeShi();
            citymap[index++] = new JingShuiShi();
            citymap[index++] = new FeiLongShi();
            citymap[index++] = new JingLingLianMeng();
            citymap[index++] = new ZhanDouLeYuan();
            citymap[index++] = new MiWuSenLin();
            for(int i=0; i<index; i++)
            {
                citymap[i]->initialMap();
                if(i == 7)
                    citymap[i]->randomPokemonLocation();
            }

            int tempId;

            string line;
            ifstream saveFile[3];
            saveFile[0].open("PlayerSave1.txt", ios_base::in);
            saveFile[1].open("PlayerSave2.txt", ios_base::in);
            saveFile[2].open("PlayerSave3.txt", ios_base::in);
            gametable.showSaveFilesList(saveFile);
            char choice;
            cin >> choice;
            int num = choice - '1';
            if(!saveFile[num])
            {
                cout << "还没有游戏存档，请选择新的游戏！" << endl;
                system("pause");
                break;
            }
            else
            {
                while(!saveFile[num].eof())
                {
                    getline(saveFile[num], line);
                    istringstream is(line);
                    int saveMapId;
                    int saveMapX;
                    int saveMapY;
                    string saveName;
                    int saveLevel;          //等级
                    int saveAttack;        //攻击
                    int saveDefence; //防御
                    int saveCurrentHp;  //当前生命
                    int saveHp;         //生命
                    int saveCurrentExp;		//当前经验
                    int saveExp;       //升级所需经验
                    double saveEvd;

                    int saveHpNum;
                    int saveSupHpNum;
                    int saveAttNum;
                    int saveDefNum;
                    int saveEvdNum;
                    int saveMoney;
                    bool saveMedalOfCourage;
                    bool saveMedalOfWisdom;
                    bool saveMedalOfFriendship;
                    bool saveMedalOfHope;
                    bool saveMedalOfBrightness;

                    is >> saveMapId >> saveMapX >> saveMapY
                       >> saveName >> saveLevel >> saveAttack >> saveDefence
                       >> saveCurrentHp >> saveHp >> saveCurrentExp >> saveExp >> saveEvd
                       >> saveHpNum >> saveSupHpNum >> saveAttNum >> saveDefNum >> saveEvdNum >> saveMoney
                       >> saveMedalOfCourage >> saveMedalOfWisdom >> saveMedalOfFriendship >> saveMedalOfHope >> saveMedalOfBrightness;
                    CityMap::newMapId = saveMapId;
                    tempId = CityMap::newMapId;
                    citymap[CityMap::newMapId]->initialPlayerLocation(saveMapX,saveMapY);
                    Bag tempBag(saveHpNum,saveSupHpNum,saveAttNum,saveDefNum,saveEvdNum,saveMoney,saveMedalOfCourage,saveMedalOfWisdom,saveMedalOfFriendship,saveMedalOfHope,saveMedalOfBrightness);
                    Pikachu tempPikachu(tempBag,saveName,saveLevel,saveAttack,saveDefence,saveAttack,saveDefence,saveCurrentHp,saveHp,saveCurrentExp,saveExp,saveEvd,saveEvd);
                    pikachu = tempPikachu;
                }
            }

            cout << "正在载入游戏..." << endl;
            cout << "游戏载入完成！" << endl;
            system("pause");
            system("cls");
            char operation;
            citymap[CityMap::newMapId]->showMap();
            citymap[CityMap::newMapId]->showPosition();
            gametable.showOperationTable();
            citymap[CityMap::newMapId]->showMapOperation();
            while(cin >> operation)
            {
                switch(operation)
                {
                case('1'):
                {
                    pikachu.showBagContent();
                    pikachu.use();
                    break;
                }
                case('2'):
                {
                    MicroMap micromap;
                    micromap.showMap();
                    system("pause");
                    break;
                }
                case('3'):
                {
                    pikachu.showCondition();
                    break;
                }
                case('4'):
                {
                    gametable.showSystemTable();
                    char systemoperation;
                    while(cin >> systemoperation)
                    {
                        bool flag = 0;
                        switch(systemoperation)
                        {
                        case('1'):
                        {
                            flag = true;
                            break;
                        }
                        case('2'):
                        {
                            ofstream output;
                            fstream file[3];
                            file[0].open("PlayerSave1.txt",ios::in);
                            file[1].open("PlayerSave2.txt",ios::in);
                            file[2].open("PlayerSave3.txt",ios::in);
                            gametable.showSaveFilesList2(file);

                            char choice;
                            cin >> choice;
                            //int num = choice - '1';
                            //cout << num << endl;
                            switch(choice)
                            {
                            case('1'):
                            {
                                char operation;
                                if(file[0])
                                {
                                    cout << "该存档已存在，是否覆盖？" << endl;
                                    cout << "  1.是    2.否" << endl;
                                    cout << "请输入：";
                                    cin >> operation;
                                    if(operation == '1')
                                    {
                                        output.open("PlayerSave1.txt");
                                        output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                               << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                               << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                               << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                               << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                        output.close();
                                        cout << "正在存档，请不要关闭游戏..." << endl;
                                        system("pause");
                                        cout << "游戏保存成功！" << endl;
                                        system("pause");
                                        break;
                                    }
                                    else if(operation == '2')
                                        break;
                                }
                                else
                                {
                                    output.open("PlayerSave1.txt");
                                    output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                           << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                           << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                           << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                           << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                    output.close();
                                    cout << "正在存档，请不要关闭游戏..." << endl;
                                    system("pause");
                                    cout << "游戏保存成功！" << endl;
                                    system("pause");
                                }
                                break;
                            }

                            case('2'):
                            {
                                char operation;
                                if(file[1])
                                {
                                    cout << "该存档已存在，是否覆盖？" << endl;
                                    cout << "  1.是    2.否" << endl;
                                    cout << "请输入：";
                                    cin >> operation;
                                    if(operation == '1')
                                    {
                                        output.open("PlayerSave2.txt");
                                        output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                               << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                               << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                               << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                               << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                        output.close();
                                        cout << "正在存档，请不要关闭游戏..." << endl;
                                        system("pause");
                                        cout << "游戏保存成功！" << endl;
                                        system("pause");
                                        break;
                                    }
                                    else if(operation == '2')
                                        break;
                                }
                                else
                                {
                                    output.open("PlayerSave2.txt");
                                    output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                           << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                           << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                           << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                           << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                    output.close();
                                    cout << "正在存档，请不要关闭游戏..." << endl;
                                    system("pause");
                                    cout << "游戏保存成功！" << endl;
                                    system("pause");
                                }
                                break;
                            }
                            case('3'):
                            {
                                char operation;
                                if(file[2])
                                {
                                    cout << "该存档已存在，是否覆盖？" << endl;
                                    cout << "  1.是    2.否" << endl;
                                    cout << "请输入：";
                                    cin >> operation;
                                    if(operation == '1')
                                    {
                                        output.open("PlayerSave3.txt");
                                        output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                               << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                               << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                               << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                               << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                        output.close();
                                        cout << "正在存档，请不要关闭游戏..." << endl;
                                        system("pause");
                                        cout << "游戏保存成功！" << endl;
                                        system("pause");
                                        break;
                                    }
                                    else if(operation == '2')
                                        break;
                                }
                                else
                                {
                                    output.open("PlayerSave3.txt");
                                    output << CityMap::newMapId << " " << citymap[CityMap::newMapId]->getX() << " " << citymap[CityMap::newMapId]->getY() << " "
                                           << pikachu.getNameValue() << " " << pikachu.getLevelValue() << " " << pikachu.getAttackValue() << " " <<pikachu.getDefenceValue() << " "
                                           << pikachu.getCurrentHpValue() << " " << pikachu.getHpValue() << " " << pikachu.getCurrentExpValue() << " " << pikachu.getExp() << " " << pikachu.getEvdValue() << " "
                                           << pikachu.getBagHpnum() << " " << pikachu.getBagSupHpnum() << " " << pikachu.getBagAttnum() << " " << pikachu.getBagDefnum() << " " << pikachu.getBagEvdnum() << " " << pikachu.getBagMoney() << " "
                                           << pikachu.getMedalOfCourage() << " " << pikachu.getMedalOfWisdom() << " " << pikachu.getMedalOfFriendship() << " " << pikachu.getMedalOfHope() << " " << pikachu.getMedalOfBrightness();
                                    output.close();
                                    cout << "正在存档，请不要关闭游戏..." << endl;
                                    system("pause");
                                    cout << "游戏保存成功！" << endl;
                                    system("pause");
                                }
                                break;
                            }
                            default:
                            {
                                cout << "输入有误，请重新输入！" << endl;
                                system("pause");
                                system("cls");
                            }
                            }
                            break;
                        }
                        case('3'):
                        {
                            cout << "正在读取游戏存档..." << endl;
                            string line;
                            ifstream saveFile[3];
                            saveFile[0].open("PlayerSave1.txt", ios_base::in);
                            saveFile[1].open("PlayerSave2.txt", ios_base::in);
                            saveFile[2].open("PlayerSave3.txt", ios_base::in);
                            gametable.showSaveFilesList(saveFile);
                            char choice;
                            cin >> choice;
                            int num = choice - '1';
                            if(!saveFile[num])
                            {
                                cout << "该存档不存在！" << endl;
                                system("pause");
                                break;
                            }
                            else
                            {
                                while(!saveFile[num].eof())
                                {
                                    getline(saveFile[num], line);
                                    istringstream is(line);
                                    int saveMapId;
                                    int saveMapX;
                                    int saveMapY;
                                    string saveName;
                                    int saveLevel;          //等级
                                    int saveAttack;        //攻击
                                    int saveDefence; //防御
                                    int saveCurrentHp;  //当前生命
                                    int saveHp;         //生命
                                    int saveCurrentExp;		//当前经验
                                    int saveExp;       //升级所需经验
                                    double saveEvd;

                                    int saveHpNum;
                                    int saveSupHpNum;
                                    int saveAttNum;
                                    int saveDefNum;
                                    int saveEvdNum;
                                    int saveMoney;
                                    bool saveMedalOfCourage;
                                    bool saveMedalOfWisdom;
                                    bool saveMedalOfFriendship;
                                    bool saveMedalOfHope;
                                    bool saveMedalOfBrightness;

                                    is >> saveMapId >> saveMapX >> saveMapY
                                       >> saveName >> saveLevel >> saveAttack >> saveDefence
                                       >> saveCurrentHp >> saveHp >> saveCurrentExp >> saveExp >> saveEvd
                                       >> saveHpNum >> saveSupHpNum >> saveAttNum >> saveDefNum >> saveEvdNum >> saveMoney
                                       >> saveMedalOfCourage >> saveMedalOfWisdom >> saveMedalOfFriendship >> saveMedalOfHope >> saveMedalOfBrightness;
                                    citymap[CityMap::newMapId]->deletePlayerLocation();
                                    CityMap::newMapId = saveMapId;
                                    tempId = CityMap::newMapId;
                                    citymap[CityMap::newMapId]->initialPlayerLocation(saveMapX,saveMapY);
                                    Bag tempBag(saveHpNum,saveSupHpNum,saveAttNum,saveDefNum,saveEvdNum,saveMoney,saveMedalOfCourage,saveMedalOfWisdom,saveMedalOfFriendship,saveMedalOfHope,saveMedalOfBrightness);
                                    Pikachu tempPikachu(tempBag,saveName,saveLevel,saveAttack,saveDefence,saveAttack,saveDefence,saveCurrentHp,saveHp,saveCurrentExp,saveExp,saveEvd,saveEvd);
                                    pikachu = tempPikachu;
                                    cout << "读取游戏存档成功！" << endl;
                                    system("pause");
                                }
                            }
                            break;
                        }

                        case('4'):
                        {
                            cout << "游戏结束，正在退出游戏..." << endl;
                            return 0;
                        }

                        default:
                        {
                            cout << "你的输入有误，请重新输入！" << endl;
                            system("pause");
                            break;
                        }

                        }
                        if(flag)
                            break;
                        gametable.showSystemTable();
                    }
                    break;
                }
                default:
                {
                    citymap[CityMap::newMapId]->mov(operation);
                    break;
                }
                }
                if(tempId != CityMap::newMapId)
                {
                    citymap[tempId]->deletePlayerLocation();
                    citymap[CityMap::newMapId]->initialPlayerLocation(CityMap::newMapX,CityMap::newMapY);
                    if(CityMap::newMapId == 7)
                    {
                        citymap[CityMap::newMapId]->deletePokemonLocation();
                        citymap[CityMap::newMapId]->randomPokemonLocation();
                    }
                    tempId = CityMap::newMapId;
                }
                system("cls");
                citymap[CityMap::newMapId]->showMap();
                citymap[CityMap::newMapId]->showPosition();
                gametable.showOperationTable();
                citymap[CityMap::newMapId]->showMapOperation();
            }
            break;
        }
        case(3):
        {
            cout << "游戏结束，正在退出游戏..." << endl;
            return 0;
        }
        default:
        {
            cout << "您的输入有误，请重新输入！" << endl;
            break;
        }
        }
        gametable.showGameTable();
    }
    return 0;
}
