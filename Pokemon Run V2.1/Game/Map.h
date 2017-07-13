#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <string>
#include "Pikachu.h"
#include "Bag.h"
#include "PokemonStore.h"
#define LENGTH 25
#define WIDTH 51
using namespace std;

//int newMapId,newMapX,newMapY;

class CityMap
{
public:
    CityMap(int cityId, string cityName): x(12), y(12), cityId(cityId), cityName(cityName) {}
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void showPosition();
    void showMapOperation();
    void showMap();
    void showStory(string);
    //virtual void readMap() = 0;
    virtual void randomPokemonLocation() = 0;
    virtual void deletePokemonLocation() = 0;
    virtual void initialMap() = 0;
    void initialPlayerLocation(int newX, int newY);
    void deletePlayerLocation();
    void mov(char direction);
    bool inMap(int x,int y);
    char city[LENGTH][WIDTH];
    int status[LENGTH][WIDTH];
    virtual void leftExit() = 0;
    virtual void rightExit() = 0;
    virtual void upExit() = 0;
    virtual void downExit() = 0;
    static int newMapId;
    static int newMapX;
    static int newMapY;

private:
    PokemonStore pokemonshop;
    int x;
    int y;
    int cityId;
    string cityName;
};

class XueFengZhen: public CityMap
{
public:
    XueFengZhen(int cityId = 0, string cityName = "雪枫镇地图"): CityMap(cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit()
    {
        newMapId = 1;
        newMapX = 49;
        newMapY = 12;
    }
    void rightExit() {}
    void upExit()
    {
        newMapId = 6;
        newMapX = 25;
        newMapY = 23;
    }
    void downExit() {}
};

class TianYuanShi: public CityMap
{
public:
    TianYuanShi(int cityId = 1, string cityName = "田园市地图"): CityMap(cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit() {}
    void rightExit()
    {
        newMapId = 0;
        newMapX = 1;
        newMapY = 12;
    }
    void upExit()
    {
        newMapId = 2;
        newMapX = 25;
        newMapY = 23;
    }
    void downExit() {}
};

class YinYeShi: public CityMap
{
public:
    YinYeShi(int cityId = 2, string cityName = "银叶市地图"): CityMap(cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit() {}
    void rightExit()
    {
        newMapId = 6;
        newMapX = 1;
        newMapY = 12;
    }
    void upExit()
    {
        newMapId = 3;
        newMapX = 25;
        newMapY = 23;
    }
    void downExit()
    {
        newMapId = 1;
        newMapX = 25;
        newMapY = 1;
    }
};

class JingShuiShi: public CityMap
{
public:
    JingShuiShi(int cityId = 3, string cityName = "静水市地图"): CityMap(cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit()
    {
        newMapId = 7;
        newMapX = 49;
        newMapY = 12;
    }
    void rightExit() {}
    void upExit() {}
    void downExit()
    {
        newMapId = 2;
        newMapX = 25;
        newMapY = 1;
    }
};

class FeiLongShi: public CityMap
{
public:
    FeiLongShi(int cityId = 4, string cityName = "飞龙市地图"): CityMap(cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit() {}
    void rightExit()
    {
        newMapId = 7;
        newMapX = 1;
        newMapY = 12;
    }
    void upExit() {}
    void downExit() {}
};

class JingLingLianMeng: public CityMap
{
public:
    JingLingLianMeng(int cityId = 5, string cityName = "精灵联盟地图"): CityMap(cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit() {}
    void rightExit() {}
    void upExit()
    {
        newMapId = 7;
        newMapX = 25;
        newMapY = 23;
    }
    void downExit() {}
};

class ZhanDouLeYuan: public CityMap
{
public:
    ZhanDouLeYuan(int cityId = 6, string cityName = "战斗乐园地图"): CityMap(cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit()
    {
        newMapId = 2;
        newMapX = 49;
        newMapY = 12;
    }
    void rightExit() {}
    void upExit() {}
    void downExit()
    {
        newMapId = 0;
        newMapX = 25;
        newMapY = 1;
    }
};

class MiWuSenLin: public CityMap
{
public:
    MiWuSenLin(int cityId = 7, string cityName = "迷雾森林地图"): CityMap(cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation();
    void deletePokemonLocation();
    void leftExit()
    {
        newMapId = 4;
        newMapX = 49;
        newMapY = 12;
    }
    void rightExit()
    {
        newMapId = 3;
        newMapX = 1;
        newMapY = 12;
    }
    void upExit() {}
    void downExit()
    {
        newMapId = 5;
        newMapX = 25;
        newMapY = 1;
    }
    int randomX[6];
    int randomY[6];
};

#endif // MAP_H_INCLUDED
