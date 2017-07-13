#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#define LENGTH 25
#define WIDTH 51
using namespace std;

enum status {BLANK,WALL,POKECENTER,GYM,POKESTORE,HOME,NPC,WILDPOKE,LEFTLINK,RIGHTLINK,UPLINK,DOWNLINK};
char buildingName[11][20] = {"POKEMONSTORE","POKEMONCENTER","HOME","GYM","POKEMONUNION","Pokemon","Zone","Level 1-2","Level 3-4","Level 5","Level 6"};
int newId,newX,newY;

class CityMap
{
public:
    CityMap(int x, int y, int cityId, string cityName): x(x), y(y), cityId(cityId), cityName(cityName) {}
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
    //virtual void readMap() = 0;
    virtual void randomPokemonLocation() = 0;
    virtual void deletePokemonLocation() = 0;
    virtual void initialMap() = 0;
    void initialPlayerLocation(int newX, int newY);
    void mov(char direction);
    bool inMap(int x,int y);
    char city[LENGTH][WIDTH];
    int status[LENGTH][WIDTH];
    virtual void leftExit() = 0;
    virtual void rightExit() = 0;
    virtual void upExit() = 0;
    virtual void downExit() = 0;

private:
    int cityId;
    string cityName;
    int x;
    int y;
};

class XueFengZhen: public CityMap
{
public:
    XueFengZhen(int x, int y, int cityId = 0, string cityName = "雪枫镇地图"): CityMap(x, y, cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit()
    {
        newId = 1;
        newX = 49;
        newY = 12;
    }
    void rightExit() {}
    void upExit()
    {
        newId = 6;
        newX = 25;
        newY = 23;
    }
    void downExit() {}
};

class TianYuanShi: public CityMap
{
public:
    TianYuanShi(int x, int y, int cityId = 1, string cityName = "田园市地图"): CityMap(x, y, cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit() {}
    void rightExit()
    {
        newId = 0;
        newX = 1;
        newY = 12;
    }
    void upExit()
    {
        newId = 2;
        newX = 25;
        newY = 23;
    }
    void downExit() {}
};

class YinYeShi: public CityMap
{
public:
    YinYeShi(int x, int y, int cityId = 2, string cityName = "银叶市地图"): CityMap(x, y, cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit() {}
    void rightExit()
    {
        newId = 6;
        newX = 1;
        newY = 12;
    }
    void upExit()
    {
        newId = 3;
        newX = 25;
        newY = 23;
    }
    void downExit()
    {
        newId = 1;
        newX = 25;
        newY = 1;
    }
};

class JingShuiShi: public CityMap
{
public:
    JingShuiShi(int x, int y, int cityId = 3, string cityName = "静水市地图"): CityMap(x, y, cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit()
    {
        newId = 7;
        newX = 49;
        newY = 12;
    }
    void rightExit() {}
    void upExit() {}
    void downExit()
    {
        newId = 2;
        newX = 25;
        newY = 1;
    }
};

class FeiLongShi: public CityMap
{
public:
    FeiLongShi(int x, int y, int cityId = 4, string cityName = "飞龙市地图"): CityMap(x, y, cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit() {}
    void rightExit()
    {
        newId = 7;
        newX = 1;
        newY = 12;
    }
    void upExit() {}
    void downExit() {}
};

class JingLingLianMeng: public CityMap
{
public:
    JingLingLianMeng(int x, int y, int cityId = 5, string cityName = "精灵联盟地图"): CityMap(x, y, cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit() {}
    void rightExit() {}
    void upExit()
    {
        newId = 7;
        newX = 25;
        newY = 23;
    }
    void downExit() {}
};

class ZhanDouLeYuan: public CityMap
{
public:
    ZhanDouLeYuan(int x, int y, int cityId = 6, string cityName = "战斗乐园地图"): CityMap(x, y, cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation() {}
    void deletePokemonLocation() {}
    void leftExit()
    {
        newId = 2;
        newX = 49;
        newY = 12;
    }
    void rightExit() {}
    void upExit() {}
    void downExit()
    {
        newId = 0;
        newX = 25;
        newY = 1;
    }
};

class MiWuSenLin: public CityMap
{
public:
    MiWuSenLin(int x, int y, int cityId = 7, string cityName = "迷雾森林地图"): CityMap(x, y, cityId, cityName) {}
    void initialMap();
    //void readMap();
    void randomPokemonLocation();
    void deletePokemonLocation();
    void leftExit()
    {
        newId = 4;
        newX = 49;
        newY = 12;
    }
    void rightExit()
    {
        newId = 3;
        newX = 1;
        newY = 12;
    }
    void upExit() {}
    void downExit()
    {
        newId = 5;
        newX = 25;
        newY = 1;
    }
    int randomX[6];
    int randomY[6];
};

void XueFengZhen::initialMap()
{
    memset(city,'\0',sizeof(city));
    memset(status,BLANK,sizeof(status));

    /*初始化玩家位置*/
    //city[getY()][getX()] = '*';

    /*初始化雪枫镇城市外墙*/
    for(int i=0; i<12; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int i=13; i<LENGTH; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int i=0; i<LENGTH; i++)
    {
        city[i][WIDTH-1] = '#';
        status[i][WIDTH-1] = WALL;
    }
    for(int j=0; j<24; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }
    for(int j=27; j<WIDTH; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }
    for(int j=0; j<WIDTH; j++)
    {
        city[LENGTH-1][j] = '#';
        status[LENGTH-1][j] = WALL;
    }

    /*初始化雪枫镇的出口*/
    for(int j=24; j<=26; j++)
    {
        status[0][j] = UPLINK;
    }
    status[12][0] = LEFTLINK;

    /*初始化精灵商店*/
    for(int j=17; j<=29; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=17; j<=21; j++)
    {
        city[8][j] = '#';
        status[8][j] = WALL;
    }
    for(int j=25; j<=29; j++)
    {
        city[8][j] = '#';
        status[8][j] = WALL;
    }
    for(int j=22; j<=24; j++)
    {
        city[8][j] = '=';
        status[8][j] = POKESTORE;
    }
    for(int i=4; i<=7; i++)
    {
        city[i][16] = '#';
        status[i][16] = WALL;
        city[i][30] = '#';
        status[i][30] = WALL;
    }
    int cnt=0;
    for(int j=20; j<=26; j++)
    {
        city[5][j] = buildingName[0][cnt++];
    }
    for(int j=21; j<=25; j++)
    {
        city[6][j] = buildingName[0][cnt++];
    }

    /*初始化精灵的家*/
    for(int j=37; j<=46; j++)
    {
        city[17][j] = '#';
        status[17][j] = WALL;
    }
    for(int j=37; j<=40; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=43; j<=46; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=41; j<=42; j++)
    {
        city[21][j] = '=';
        status[21][j] = HOME;
    }
    for(int i=17; i<=21; i++)
    {
        city[i][37] = '#';
        status[i][37] = WALL;
        city[i][46] = '#';
        status[i][46] = WALL;
    }
    cnt=0;
    for(int j=40; j<=43; j++)
    {
        city[19][j] = buildingName[2][cnt++];
    }

    /*初始化精灵中心*/
    for(int j=5; j<=24; j++)
    {
        city[14][j] = '#';
        status[14][j] = WALL;
    }
    for(int j=5; j<=12; j++)
    {
        city[19][j] = '#';
        status[19][j] = WALL;
    }
    for(int j=17; j<=24; j++)
    {
        city[19][j] = '#';
        status[19][j] = WALL;
    }
    for(int j=13; j<=16; j++)
    {
        city[19][j] = '=';
        status[19][j] = POKECENTER;
    }
    for(int i=14; i<=19; i++)
    {
        city[i][5] = '#';
        status[i][5] = WALL;
        city[i][24] = '#';
        status[i][24] = WALL;
    }
    cnt=0;
    for(int j=12; j<=18; j++)
    {
        city[16][j] = buildingName[1][cnt++];
    }
    for(int j=12; j<=17; j++)
    {
        city[17][j] = buildingName[1][cnt++];
    }
}

void TianYuanShi::initialMap()
{
    memset(city,'\0',sizeof(city));
    memset(status,BLANK,sizeof(status));

    /*初始化玩家位置*/
    //city[getY()][getX()] = '*';

    /*初始化田园市城市外墙*/
    for(int i=0; i<12; i++)
    {
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int i=13; i<LENGTH; i++)
    {
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int i=0; i<LENGTH; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int j=0; j<24; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }
    for(int j=27; j<WIDTH; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }
    for(int j=0; j<WIDTH; j++)
    {
        city[LENGTH-1][j] = '#';
        status[LENGTH-1][j] = WALL;
    }

    /*初始化田园市的出口*/
    for(int j=24; j<=26; j++)
    {
        status[0][j] = UPLINK;
    }
    status[12][WIDTH - 1] = RIGHTLINK;

    /*初始化精灵商店*/
    for(int j=26; j<=38; j++)
    {
        city[16][j] = '#';
        status[16][j] = WALL;
    }
    for(int j=26; j<=30; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=34; j<=38; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=31; j<=33; j++)
    {
        city[21][j] = '=';
        status[21][j] = POKESTORE;
    }
    for(int i=17; i<=20; i++)
    {
        city[i][25] = '#';
        status[i][25] = WALL;
        city[i][39] = '#';
        status[i][39] = WALL;
    }
    int cnt=0;
    for(int j=29; j<=35; j++)
    {
        city[18][j] = buildingName[0][cnt++];
    }
    for(int j=30; j<=34; j++)
    {
        city[19][j] = buildingName[0][cnt++];
    }

    /*初始化精灵中心*/
    for(int j=28; j<=47; j++)
    {
        city[2][j] = '#';
        status[2][j] = WALL;
    }
    for(int j=28; j<=35; j++)
    {
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=39; j<=47; j++)
    {
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=36; j<=38; j++)
    {
        city[7][j] = '=';
        status[7][j] = POKECENTER;
    }
    for(int i=2; i<=7; i++)
    {
        city[i][28] = '#';
        status[i][28] = WALL;
        city[i][47] = '#';
        status[i][47] = WALL;
    }
    cnt=0;
    for(int j=35; j<=41; j++)
    {
        city[4][j] = buildingName[1][cnt++];
    }
    for(int j=35; j<=40; j++)
    {
        city[5][j] = buildingName[1][cnt++];
    }

    /*初始化精灵道馆*/
    for(int j=3; j<=7; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
        city[11][j] = '#';
        status[11][j] = WALL;
    }
    for(int j=11; j<=15; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
        city[11][j] = '#';
        status[11][j] = WALL;
    }
    for(int j=7; j<=11; j++)
    {
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=8; j<=10; j++)
    {
        city[13][j] = '=';
        status[13][j] = GYM;
    }
    city[8][7] = '#';
    status[8][7] = WALL;
    city[8][11] = '#';
    status[8][11] = WALL;
    city[10][3] = '#';
    status[10][3] = WALL;
    city[10][15] = '#';
    status[10][15] = WALL;
    for(int i=12; i<=13; i++)
    {
        city[i][7] = '#';
        status[i][7] = WALL;
        city[i][11] = '#';
        status[i][11] = WALL;
    }
    cnt=0;
    for(int j=8; j<=10; j++)
    {
        city[10][j] = buildingName[3][cnt++];
    }
}

void YinYeShi::initialMap()
{
    memset(city,'\0',sizeof(city));
    memset(status,BLANK,sizeof(status));

    /*初始化玩家位置*/
    //city[getY()][getX()] = '*';

    /*初始化银叶市城市外墙*/
    for(int i=0; i<12; i++)
    {
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int i=13; i<LENGTH; i++)
    {
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int i=0; i<LENGTH; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int j=0; j<24; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }
    for(int j=27; j<WIDTH; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }

    /*初始化银叶市的出口*/
    status[12][WIDTH - 1] = RIGHTLINK;
    for(int j=24; j<=26; j++)
    {
        status[0][j] = UPLINK;
        status[LENGTH - 1][j] = DOWNLINK;
    }

    /*初始化精灵商店*/
    for(int j=7; j<=19; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=7; j<=11; j++)
    {
        city[8][j] = '#';
        status[8][j] = WALL;
    }
    for(int j=15; j<=19; j++)
    {
        city[8][j] = '#';
        status[8][j] = WALL;
    }
    for(int j=12; j<=14; j++)
    {
        city[8][j] = '=';
        status[8][j] = POKESTORE;
    }
    for(int i=4; i<=7; i++)
    {
        city[i][6] = '#';
        status[i][6] = WALL;
        city[i][20] = '#';
        status[i][20] = WALL;
    }
    int cnt=0;
    for(int j=10; j<=16; j++)
    {
        city[5][j] = buildingName[0][cnt++];
    }
    for(int j=11; j<=15; j++)
    {
        city[6][j] = buildingName[0][cnt++];
    }

    /*初始化精灵中心*/
    for(int j=5; j<=24; j++)
    {
        city[16][j] = '#';
        status[16][j] = WALL;
    }
    for(int j=5; j<=12; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=17; j<=24; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=13; j<=16; j++)
    {
        city[21][j] = '=';
        status[21][j] = POKECENTER;
    }
    for(int i=16; i<=21; i++)
    {
        city[i][5] = '#';
        status[i][5] = WALL;
        city[i][24] = '#';
        status[i][24] = WALL;
    }
    cnt=0;
    for(int j=12; j<=18; j++)
    {
        city[18][j] = buildingName[1][cnt++];
    }
    for(int j=12; j<=18; j++)
    {
        city[19][j] = buildingName[1][cnt++];
    }

    /*初始化精灵道馆*/
    for(int j=33; j<=37; j++)
    {
        city[5][j] = '#';
        status[5][j] = WALL;
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=41; j<=45; j++)
    {
        city[5][j] = '#';
        status[5][j] = WALL;
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=37; j<=41; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=38; j<=40; j++)
    {
        city[9][j] = '=';
        status[9][j] = GYM;
    }
    city[4][37] = '#';
    status[8][37] = WALL;
    city[4][41] = '#';
    status[8][41] = WALL;
    city[6][33] = '#';
    status[6][33] = WALL;
    city[6][45] = '#';
    status[6][45] = WALL;
    for(int i=8; i<=9; i++)
    {
        city[i][37] = '#';
        status[i][37] = WALL;
        city[i][41] = '#';
        status[i][41] = WALL;
    }
    cnt=0;
    for(int j=38; j<=40; j++)
    {
        city[6][j] = buildingName[3][cnt++];
    }
}

void JingShuiShi::initialMap()
{
    memset(city,'\0',sizeof(city));
    memset(status,BLANK,sizeof(status));

    /*初始化玩家位置*/
    //city[getY()][getX()] = '*';

    /*初始化静水市城市外墙*/
    for(int i=0; i<12; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int i=13; i<LENGTH; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int i=0; i<LENGTH; i++)
    {
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int j=0; j<24; j++)
    {
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }
    for(int j=27; j<WIDTH; j++)
    {
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }
    for(int j=0; j<WIDTH; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }

    /*初始化静水市的出口*/
    status[12][0] = LEFTLINK;
    for(int j=24; j<=26; j++)
    {
        status[LENGTH - 1][j] = DOWNLINK;
    }

    /*初始化精灵商店*/
    for(int j=5; j<=17; j++)
    {
        city[16][j] = '#';
        status[16][j] = WALL;
    }
    for(int j=5; j<=9; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=13; j<=17; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=10; j<=12; j++)
    {
        city[21][j] = '=';
        status[21][j] = POKESTORE;
    }
    for(int i=17; i<=20; i++)
    {
        city[i][4] = '#';
        status[i][4] = WALL;
        city[i][18] = '#';
        status[i][18] = WALL;
    }
    int cnt=0;
    for(int j=8; j<=14; j++)
    {
        city[18][j] = buildingName[0][cnt++];
    }
    for(int j=9; j<=13; j++)
    {
        city[19][j] = buildingName[0][cnt++];
    }

    /*初始化精灵中心*/
    for(int j=28; j<=47; j++)
    {
        city[2][j] = '#';
        status[2][j] = WALL;
    }
    for(int j=28; j<=35; j++)
    {
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=40; j<=47; j++)
    {
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=36; j<=39; j++)
    {
        city[7][j] = '=';
        status[7][j] = POKECENTER;
    }
    for(int i=2; i<=7; i++)
    {
        city[i][28] = '#';
        status[i][28] = WALL;
        city[i][47] = '#';
        status[i][47] = WALL;
    }
    cnt=0;
    for(int j=35; j<=41; j++)
    {
        city[4][j] = buildingName[1][cnt++];
    }
    for(int j=35; j<=40; j++)
    {
        city[5][j] = buildingName[1][cnt++];
    }

    /*初始化精灵道馆*/
    for(int j=30; j<=34; j++)
    {
        city[15][j] = '#';
        status[15][j] = WALL;
        city[17][j] = '#';
        status[17][j] = WALL;
    }
    for(int j=38; j<=42; j++)
    {
        city[15][j] = '#';
        status[15][j] = WALL;
        city[17][j] = '#';
        status[17][j] = WALL;
    }
    for(int j=34; j<=38; j++)
    {
        city[13][j] = '#';
        status[13][j] = WALL;
    }
    for(int j=35; j<=37; j++)
    {
        city[19][j] = '=';
        status[19][j] = GYM;
    }
    city[14][34] = '#';
    status[14][34] = WALL;
    city[14][38] = '#';
    status[14][38] = WALL;
    city[16][30] = '#';
    status[16][30] = WALL;
    city[16][42] = '#';
    status[16][42] = WALL;
    for(int i=18; i<=19; i++)
    {
        city[i][34] = '#';
        status[i][34] = WALL;
        city[i][38] = '#';
        status[i][38] = WALL;
    }
    cnt=0;
    for(int j=35; j<=37; j++)
    {
        city[16][j] = buildingName[3][cnt++];
    }
}

void FeiLongShi::initialMap()
{
    memset(city,'\0',sizeof(city));
    memset(status,BLANK,sizeof(status));

    /*初始化玩家位置*/
    //city[getY()][getX()] = '*';

    /*初始化飞龙市城市外墙*/
    for(int i=0; i<12; i++)
    {
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int i=13; i<LENGTH; i++)
    {
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int i=0; i<LENGTH; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int j=0; j<WIDTH; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }

    /*初始化飞龙市的出口*/
    status[12][WIDTH - 1] = RIGHTLINK;

    /*初始化精灵商店*/
    for(int j=4; j<=16; j++)
    {
        city[2][j] = '#';
        status[2][j] = WALL;
    }
    for(int j=4; j<=8; j++)
    {
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=12; j<=16; j++)
    {
        city[7][j] = '#';
        status[7][j] = WALL;
    }
    for(int j=9; j<=11; j++)
    {
        city[7][j] = '=';
        status[7][j] = POKESTORE;
    }
    for(int i=3; i<=6; i++)
    {
        city[i][3] = '#';
        status[i][3] = WALL;
        city[i][17] = '#';
        status[i][17] = WALL;
    }
    int cnt=0;
    for(int j=7; j<=13; j++)
    {
        city[4][j] = buildingName[0][cnt++];
    }
    for(int j=8; j<=12; j++)
    {
        city[5][j] = buildingName[0][cnt++];
    }

    /*初始化精灵中心*/
    for(int j=5; j<=24; j++)
    {
        city[15][j] = '#';
        status[15][j] = WALL;
    }
    for(int j=5; j<=12; j++)
    {
        city[20][j] = '#';
        status[20][j] = WALL;
    }
    for(int j=17; j<=24; j++)
    {
        city[20][j] = '#';
        status[20][j] = WALL;
    }
    for(int j=13; j<=16; j++)
    {
        city[20][j] = '=';
        status[20][j] = POKECENTER;
    }
    for(int i=15; i<=20; i++)
    {
        city[i][5] = '#';
        status[i][5] = WALL;
        city[i][24] = '#';
        status[i][24] = WALL;
    }
    cnt=0;
    for(int j=12; j<=18; j++)
    {
        city[17][j] = buildingName[1][cnt++];
    }
    for(int j=12; j<=17; j++)
    {
        city[18][j] = buildingName[1][cnt++];
    }

    /*初始化精灵道馆*/
    for(int j=30; j<=34; j++)
    {
        city[10][j] = '#';
        status[10][j] = WALL;
        city[12][j] = '#';
        status[12][j] = WALL;
    }
    for(int j=38; j<=42; j++)
    {
        city[10][j] = '#';
        status[10][j] = WALL;
        city[12][j] = '#';
        status[12][j] = WALL;
    }
    for(int j=34; j<=38; j++)
    {
        city[8][j] = '#';
        status[8][j] = WALL;
    }
    for(int j=35; j<=37; j++)
    {
        city[14][j] = '=';
        status[14][j] = GYM;
    }
    city[9][34] = '#';
    status[9][34] = WALL;
    city[9][38] = '#';
    status[9][38] = WALL;
    city[11][30] = '#';
    status[11][30] = WALL;
    city[11][42] = '#';
    status[11][42] = WALL;
    for(int i=13; i<=14; i++)
    {
        city[i][34] = '#';
        status[i][34] = WALL;
        city[i][38] = '#';
        status[i][38] = WALL;
    }
    cnt=0;
    for(int j=35; j<=37; j++)
    {
        city[11][j] = buildingName[3][cnt++];
    }
}

void JingLingLianMeng::initialMap()
{
    memset(city,'\0',sizeof(city));
    memset(status,BLANK,sizeof(status));

    /*初始化玩家位置*/
    //city[getY()][getX()] = '*';

    /*初始化精灵联盟城市外墙*/
    for(int i=0; i<LENGTH; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int j=0; j<WIDTH; j++)
    {
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }
    for(int j=0; j<=23; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }
    for(int j=27; j<WIDTH; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }

    /*初始化精灵联盟的出口*/
    for(int j=24; j<=26; j++)
    {
        status[0][j] = UPLINK;
    }

    /*初始化精灵商店*/
    for(int j=33; j<=45; j++)
    {
        city[16][j] = '#';
        status[16][j] = WALL;
    }
    for(int j=33; j<=37; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=41; j<=45; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=38; j<=40; j++)
    {
        city[21][j] = '=';
        status[21][j] = POKESTORE;
    }
    for(int i=17; i<=20; i++)
    {
        city[i][32] = '#';
        status[i][32] = WALL;
        city[i][46] = '#';
        status[i][46] = WALL;
    }
    int cnt=0;
    for(int j=36; j<=42; j++)
    {
        city[18][j] = buildingName[0][cnt++];
    }
    for(int j=37; j<=41; j++)
    {
        city[19][j] = buildingName[0][cnt++];
    }

    /*初始化精灵中心*/
    for(int j=3; j<=22; j++)
    {
        city[16][j] = '#';
        status[16][j] = WALL;
    }
    for(int j=3; j<=10; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=15; j<=22; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=11; j<=14; j++)
    {
        city[21][j] = '=';
        status[21][j] = POKECENTER;
    }
    for(int i=16; i<=21; i++)
    {
        city[i][3] = '#';
        status[i][3] = WALL;
        city[i][22] = '#';
        status[i][22] = WALL;
    }
    cnt=0;
    for(int j=10; j<=16; j++)
    {
        city[18][j] = buildingName[1][cnt++];
    }
    for(int j=10; j<=15; j++)
    {
        city[19][j] = buildingName[1][cnt++];
    }

    /*初始化精灵道馆*/
    for(int j=15; j<=35; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=15; j<=21; j++)
    {
        city[8][j] = '#';
        status[8][j] = WALL;
    }
    for(int j=29; j<=35; j++)
    {
        city[8][j] = '#';
        status[8][j] = WALL;
    }
    for(int j=21; j<=23; j++)
    {
        city[11][j] = '#';
        status[11][j] = WALL;
    }
    for(int j=27; j<=29; j++)
    {
        city[11][j] = '#';
        status[11][j] = WALL;
    }
    for(int j=24; j<=26; j++)
    {
        city[11][j] = '=';
        status[11][j] = GYM;
    }
    for(int i=9; i<=10; i++)
    {
        city[i][21] = '#';
        status[i][21] = WALL;
        city[i][29] = '#';
        status[i][29] = WALL;
    }
    for(int i=3; i<=8; i++)
    {
        city[i][15] = '#';
        status[i][15] = WALL;
        city[i][35] = '#';
        status[i][35] = WALL;
    }
    cnt=0;
    for(int j=22; j<=28; j++)
    {
        city[5][j] = buildingName[4][cnt++];
    }
    for(int j=23; j<=27; j++)
    {
        city[6][j] = buildingName[4][cnt++];
    }
}

void ZhanDouLeYuan::initialMap()
{
    memset(city,'\0',sizeof(city));
    memset(status,BLANK,sizeof(status));

    /*初始化玩家位置*/
    //city[getY()][getX()] = '*';

    /*初始化战斗乐园外墙*/
    for(int i=0; i<12; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int i=13; i<LENGTH; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
    }
    for(int i=0; i<LENGTH; i++)
    {
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int j=0; j<24; j++)
    {
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }
    for(int j=27; j<WIDTH; j++)
    {
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }
    for(int j=0; j<WIDTH; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }

    /*初始化战斗乐园的出口*/
    status[12][0] = LEFTLINK;
    for(int j=24; j<=26; j++)
    {
        status[LENGTH - 1][j] = DOWNLINK;
    }

    /*初始化左上角房间*/
    for(int j=5; j<=18; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=5; j<=9; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
    }
    for(int j=14; j<=18; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
    }
    for(int j=10; j<=13; j++)
    {
        city[9][j] = '=';
        status[9][j] = WILDPOKE;
    }
    for(int i=3; i<=9; i++)
    {
        city[i][5] = '#';
        status[i][5] = WALL;
        city[i][18] = '#';
        status[i][18] = WALL;
    }
    int cnt=0;
    for(int j=8; j<=16; j++)
    {
        city[5][j] = buildingName[7][cnt++];
    }
    cnt = 0;
    for(int j=9; j<=15; j++)
    {
        city[6][j] = buildingName[5][cnt++];
    }
    cnt = 0;
    for(int j=10; j<=13; j++)
    {
        city[7][j] = buildingName[6][cnt++];
    }

    /*初始化右上角房间*/
    for(int j=32; j<=45; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=32; j<=36; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
    }
    for(int j=41; j<=45; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
    }
    for(int j=37; j<=40; j++)
    {
        city[9][j] = '=';
        status[9][j] = WILDPOKE;
    }
    for(int i=3; i<=9; i++)
    {
        city[i][32] = '#';
        status[i][32] = WALL;
        city[i][45] = '#';
        status[i][45] = WALL;
    }
    cnt=0;
    for(int j=35; j<=43; j++)
    {
        city[5][j] = buildingName[8][cnt++];
    }
    cnt = 0;
    for(int j=36; j<=42; j++)
    {
        city[6][j] = buildingName[5][cnt++];
    }
    cnt = 0;
    for(int j=37; j<=40; j++)
    {
        city[7][j] = buildingName[6][cnt++];
    }

    /*初始化左下角房间*/
    for(int j=5; j<=18; j++)
    {
        city[15][j] = '#';
        status[15][j] = WALL;
    }
    for(int j=5; j<=9; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=14; j<=18; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=10; j<=13; j++)
    {
        city[21][j] = '=';
        status[21][j] = WILDPOKE;
    }
    for(int i=15; i<=21; i++)
    {
        city[i][5] = '#';
        status[i][5] = WALL;
        city[i][18] = '#';
        status[i][18] = WALL;
    }
    cnt=0;
    for(int j=9; j<=15; j++)
    {
        city[17][j] = buildingName[9][cnt++];
    }
    cnt = 0;
    for(int j=9; j<=15; j++)
    {
        city[18][j] = buildingName[5][cnt++];
    }
    cnt = 0;
    for(int j=10; j<=13; j++)
    {
        city[19][j] = buildingName[6][cnt++];
    }

    /*初始化右下角房间*/
    for(int j=32; j<=45; j++)
    {
        city[15][j] = '#';
        status[15][j] = WALL;
    }
    for(int j=32; j<=36; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=41; j<=45; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=37; j<=40; j++)
    {
        city[21][j] = '=';
        status[21][j] = WILDPOKE;
    }
    for(int i=15; i<=21; i++)
    {
        city[i][32] = '#';
        status[i][32] = WALL;
        city[i][45] = '#';
        status[i][45] = WALL;
    }
    cnt=0;
    for(int j=36; j<=42; j++)
    {
        city[17][j] = buildingName[10][cnt++];
    }
    cnt = 0;
    for(int j=36; j<=42; j++)
    {
        city[18][j] = buildingName[5][cnt++];
    }
    cnt = 0;
    for(int j=37; j<=40; j++)
    {
        city[19][j] = buildingName[6][cnt++];
    }
}

void MiWuSenLin::initialMap()
{
    memset(city,'\0',sizeof(city));
    memset(status,BLANK,sizeof(status));

    /*初始化玩家位置*/
    //city[getY()][getX()] = '*';

    /*初始化迷雾森林外墙*/
    for(int i=0; i<12; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int i=13; i<LENGTH; i++)
    {
        city[i][0] = '#';
        status[i][0] = WALL;
        city[i][WIDTH - 1] = '#';
        status[i][WIDTH - 1] = WALL;
    }
    for(int j=0; j<WIDTH; j++)
    {
        city[0][j] = '#';
        status[0][j] = WALL;
    }
    for(int j=0; j<24; j++)
    {
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }
    for(int j=27; j<WIDTH; j++)
    {
        city[LENGTH - 1][j] = '#';
        status[LENGTH - 1][j] = WALL;
    }

    /*初始化迷雾森林出口*/
    status[12][0] = LEFTLINK;
    status[12][WIDTH - 1] = RIGHTLINK;
    for(int j=24; j<=26; j++)
    {
        status[LENGTH - 1][j] = DOWNLINK;
    }

    /*初始化迷宫内部*/
    for(int j=5; j<=14; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=20; j<=23; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=28; j<=33; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=38; j<=45; j++)
    {
        city[3][j] = '#';
        status[3][j] = WALL;
    }
    for(int j=10; j<=16; j++)
    {
        city[6][j] = '#';
        status[6][j] = WALL;
    }
    for(int j=33; j<=43; j++)
    {
        city[6][j] = '#';
        status[6][j] = WALL;
    }
    for(int j=5; j<=11; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
    }
    for(int j=16; j<=28; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
    }
    for(int j=33; j<=38; j++)
    {
        city[9][j] = '#';
        status[9][j] = WALL;
    }
    for(int j=43; j<=49; j++)
    {
        city[10][j] = '#';
        status[10][j] = WALL;
    }
    for(int j=15; j<=32; j++)
    {
        city[12][j] = '#';
        status[12][j] = WALL;
    }
    for(int j=45; j<=49; j++)
    {
        city[14][j] = '#';
        status[14][j] = WALL;
    }
    for(int j=15; j<=31; j++)
    {
        city[15][j] = '#';
        status[15][j] = WALL;
    }
    for(int j=1; j<=5; j++)
    {
        city[18][j] = '#';
        status[18][j] = WALL;
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=10; j<=23; j++)
    {
        city[18][j] = '#';
        status[18][j] = WALL;
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=39; j<=45; j++)
    {
        city[18][j] = '#';
        status[18][j] = WALL;
    }
    for(int j=29; j<=34; j++)
    {
        city[20][j] = '#';
        status[20][j] = WALL;
    }
    for(int j=34; j<=39; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }
    for(int j=45; j<=49; j++)
    {
        city[21][j] = '#';
        status[21][j] = WALL;
    }

    for(int i=1; i<=3; i++)
    {
        city[i][20] = '#';
        status[i][20] = WALL;
        city[i][45] = '#';
        status[i][45] = WALL;
    }
    for(int i=3; i<=6; i++)
    {
        city[i][5] = '#';
        status[i][5] = WALL;
        city[i][10] = '#';
        status[i][10] = WALL;
        city[i][28] = '#';
        status[i][28] = WALL;
        city[i][33] = '#';
        status[i][33] = WALL;
    }
    for(int i=3; i<=7; i++)
    {
        city[i][23] = '#';
        status[i][23] = WALL;
    }
    for(int i=7; i<=8; i++)
    {
        city[i][11] = '#';
        status[i][11] = WALL;
        city[i][16] = '#';
        status[i][16] = WALL;
    }
    for(int i=10; i<=15; i++)
    {
        city[i][5] = '#';
        status[i][5] = WALL;
    }
    city[17][5] = '#';
    status[17][5] = WALL;
    for(int i=13; i<=17; i++)
    {
        city[i][10] = '#';
        status[i][10] = WALL;
    }
    for(int i=22; i<=23; i++)
    {
        city[i][10] = '#';
        status[i][10] = WALL;
    }
    for(int i=13; i<=14; i++)
    {
        city[i][15] = '#';
        status[i][15] = WALL;
    }
    for(int i=18; i<=21; i++)
    {
        city[i][23] = '#';
        status[i][23] = WALL;
    }
    for(int i=20; i<=22; i++)
    {
        city[i][29] = '#';
        status[i][29] = WALL;
    }
    for(int i=16; i<=19; i++)
    {
        city[i][31] = '#';
        status[i][31] = WALL;
    }
    for(int i=10; i<=14; i++)
    {
        city[i][38] = '#';
        status[i][38] = WALL;
    }
    for(int i=19; i<=20; i++)
    {
        city[i][39] = '#';
        status[i][39] = WALL;
    }
    for(int i=9; i<=11; i++)
    {
        city[i][43] = '#';
        status[i][43] = WALL;
    }
    for(int i=15; i<=17; i++)
    {
        city[i][45] = '#';
        status[i][45] = WALL;
    }
}

void MiWuSenLin::randomPokemonLocation()
{
    for(int i=0; i<=4; i++)
    {
        randomX[i] = rand() % 49 + 1;
        randomY[i] = rand() % 23 + 1;
        while(status[randomY[i]][randomX[i]] != BLANK)
        {
            randomX[i] = rand() % 49 + 1;
            randomY[i] = rand() % 23 + 1;
        }
        city[randomY[i]][randomX[i]] = '@';
        status[randomY[i]][randomX[i]] = WILDPOKE;
    }
}

void MiWuSenLin::deletePokemonLocation()
{
    for(int i=0; i<=4; i++)
    {
        city[randomY[i]][randomX[i]] = '\0';
        status[randomY[i]][randomX[i]] = BLANK;
    }
}

void CityMap::initialPlayerLocation(int newX, int newY)
{
    x = newX;
    y = newY;
    city[y][x] = '*';
}

bool CityMap::inMap(int x,int y)
{
    if(x < 0 || x >= WIDTH || y < 0 || y >= LENGTH)
        return false;
    return true;
}

void CityMap::mov(char direction)
{
    int newX,newY;
    //int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
    switch(direction)
    {
    case ('w'):
    {
        newX = x;
        newY = y - 1;
        break;
    }
    case ('s'):
    {
        newX = x;
        newY = y + 1;
        break;
    }
    case ('a'):
    {
        newX = x - 1;
        newY = y;
        break;
    }
    case ('d'):
    {
        newX = x + 1;
        newY = y;
        break;
    }
    default:
    {
        cout << "您的输入有误，请重新输入！" << endl;
        system("pause");
        break;
    }
    }
    if(inMap(newX,newY))
    {
        switch(status[newY][newX])
        {
        case(BLANK):
        {
            city[y][x]='\0';
            city[newY][newX]='*';
            y=newY;
            x=newX;
            break;
        }
        case(WALL):
        {
            cout << "无法移动到目标坐标！" << endl;
            system("pause");
            break;
        }
        case(POKESTORE):
        {
            cout << "进入商店！" << endl;
            system("pause");
            break;
        }
        case(HOME):
        {
            cout << "回家！" << endl;
            system("pause");
            break;
        }
        case(POKECENTER):
        {
            cout << "进入建筑物~" << endl;
            system("pause");
            break;
        }
        case(WILDPOKE):
        {
            cout << "一只精灵跳了出来！" << endl;
            system("pause");
            break;
        }
        case(LEFTLINK):
        {
            cout << "进入下一个城市" << endl;
            system("pause");
            leftExit();
            //initialPlayerLocation(newX,newY);
            break;
        }
        case(RIGHTLINK):
        {
            cout << "进入下一个城市" << endl;
            system("pause");
            rightExit();
            //initialPlayerLocation(newX,newY);
            break;
        }
        case(UPLINK):
        {
            cout << "进入下一个城市" << endl;
            system("pause");
            upExit();
            //initialPlayerLocation(newX,newY);
            break;
        }
        case(DOWNLINK):
        {
            cout << "进入下一个城市" << endl;
            system("pause");
            downExit();
            //initialPlayerLocation(newX,newY);
            break;
        }
        case(NPC):
        {
            cout << "***********************" << endl;
            cout << "*                     *" << endl;
            cout << "*  是否跟该NPC对话？  *" << endl;
            cout << "*                     *" << endl;
            cout << "*  1.是    2.否       *" << endl;
            cout << "*                     *" << endl;
            cout << "***********************" << endl;
            int num;
            cout << "请输入：";
            while(cin >> num)
            {
                system("cls");
                if(num == 1)
                {
                    cout << "***************************" << endl;
                    cout << "*                         *" << endl;
                    cout << "*  NPC: 你是个傻逼！！！  *" << endl;
                    cout << "*                         *" << endl;
                    cout << "***************************" << endl;
                    system("pause");
                    break;
                }
                else if(num == 2)
                    break;
                else
                {
                    cout << "您的输入有误，请重新输入：" << endl;
                    cout << "是否跟该NPC对话？" << endl;
                    cout << "1.是    2.否" << endl;
                }
            }
            break;
        }
        }
    }
}

void CityMap::showMapOperation()
{
    cout << endl;
    cout << "方向控制提示  ——  [w] 向上    [s] 向下    [a] 向左    [d] 向右" << endl;
    cout << "请输入操作：";
}

void CityMap::showMap()
{
    cout << setw(cityName.length()+6) << setfill('*') << "*" << endl;
    cout << "*  " << cityName << "  *" << endl;
    cout << setw(cityName.length()+6) << setfill('*') << "*" << endl;
    for(int i=0; i<LENGTH; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            cout << city[i][j];
        }
        cout << endl;
    }
}

void CityMap::showPosition()
{
    cout << "您现在的坐标为 ( " << x << " , " << y << " );" << endl;
}

int main()
{
    vector <CityMap *> citymap(10);
    int index = 0;
    int x;
    int y;
    string cityName;
    citymap[index++] = new XueFengZhen(x,y);
    citymap[index++] = new TianYuanShi(x,y);
    citymap[index++] = new YinYeShi(x,y);
    citymap[index++] = new JingShuiShi(x,y);
    citymap[index++] = new FeiLongShi(x,y);
    citymap[index++] = new JingLingLianMeng(x,y);
    citymap[index++] = new ZhanDouLeYuan(x,y);
    citymap[index++] = new MiWuSenLin(x,y);
    for(int i=0; i<index; i++)
    {
        citymap[i]->initialMap();
        if(i == 7)
            citymap[i]->randomPokemonLocation();
    }
    char operation;
    citymap[newId]->initialPlayerLocation(41,22);
    citymap[newId]->showMap();
    citymap[newId]->showPosition();
    citymap[newId]->showMapOperation();
    int tempId = newId;
    while(cin >> operation)
    {
        citymap[newId]->mov(operation);
        if(tempId != newId)
        {
            citymap[newId]->initialPlayerLocation(newX,newY);
            if(newId == 7)
            {
                citymap[newId]->deletePokemonLocation();
                citymap[newId]->randomPokemonLocation();
            }
            tempId = newId;
        }
        system("cls");
        citymap[newId]->showMap();
        citymap[newId]->showPosition();
        citymap[newId]->showMapOperation();
    }
    return 0;
}

/*int main()
{
    int index = 0;
    int x;
    int y;
    MiWuSenLin c(x,y);
    c.initialMap();
    c.randomPokemonLocation();
    c.showMap();
    return 0;
}*/

