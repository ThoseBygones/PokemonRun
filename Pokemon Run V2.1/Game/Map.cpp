#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include "Map.h"
#include "PokemonStore.h"
#include "Bag.h"
#include "Pokemon.h"
#define LENGTH 25
#define WIDTH 51
using namespace std;

enum status {BLANK,WALL,POKECENTER,POKESTORE,HOME,NPC,WILDPOKE,GYM1,GYM2,GYM3,GYM4,POKEUNION,ZONE1,ZONE2,ZONE3,ZONE4,LEFTLINK,RIGHTLINK,UPLINK,DOWNLINK};
char buildingName[11][20] = {"POKEMONSTORE","POKEMONCENTER","HOME","GYM","POKEMONUNION","Pokemon","Zone","Level 1-2","Level 3-4","Level 5","Level 6"};

extern Pikachu pikachu;
extern vector <Pokemon *> pokemonList;
extern void ramdonWildPokemon(vector <Pokemon *> &pokemonList);

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
        status[13][j] = GYM1;
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
        status[9][j] = GYM2;
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
        status[19][j] = GYM3;
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
        status[14][j] = GYM4;
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
        status[11][j] = POKEUNION;
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
        status[9][j] = ZONE1;
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
        status[9][j] = ZONE2;
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
        status[21][j] = ZONE3;
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
        status[21][j] = ZONE4;
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

void CityMap::deletePlayerLocation()
{
    city[y][x] = '\0';
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
            pokemonshop.showShop(pikachu);
            pikachu.addItems();
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
            cout << "进入精灵中心！" << endl;
            system("pause");
            system("cls");
            cout << "******************************" << endl;
            cout << "*   是否要回复你的生命值？   *" << endl;
            cout << "*       1.是    2.否         *" << endl;
            cout << "******************************" << endl;
            cout << "请输入：";
            char recoveroperation;
            while(cin >> recoveroperation)
            {
                bool flag = false;
                switch(recoveroperation)
                {
                case('1'):
                {
                    pikachu.recoverHp();
                    flag = true;
                    cout << "欢迎再来~" << endl;
                    system("pause");
                    break;
                }
                case('2'):
                {
                    flag = true;
                    cout << "没体力了就别勉强自己！欢迎再来~" << endl;
                    system("pause");
                    break;
                }
                default:
                {
                    cout << "你的输入有误，请重新输入！" << endl;
                    system("pause");
                    system("cls");
                    cout << "******************************" << endl;
                    cout << "*   是否要回复你的生命值？   *" << endl;
                    cout << "*       1.是    2.否         *" << endl;
                    cout << "******************************" << endl;
                    cout << "请输入：";
                }
                }
                if(flag)
                    break;
            }
            break;
        }
        case(WILDPOKE):
        {
            cout << "一只精灵跳了出来！" << endl;
            system("pause");
            int id = rand() % 10 + 22;
            Pokemon wildpokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(wildpokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...真像一场噩梦...”");
            }
            else
                system("pause");
            break;
        }
        case(GYM1):
        {
            cout << "挑战田园市道馆！" << endl;
            if(!pikachu.getMedalOfCourage())
            {
                showStory("神秘组织-风：“哪里来的精灵，看起来真弱。赶紧走开！这不是你该来的地方！”");
                showStory("你：这里道馆的主人有点奇怪啊，应该就是绑架小精灵的那些人中的一个了。");
                showStory("神秘组织-风“赶紧走开！再不走我就不客气了！”");
                showStory("你：“...”");
            }
            Pokemon gym1pokemon = *pokemonList[32];
            bool loseflag = pikachu.combat(gym1pokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...挑战道馆失败了吗...下次一定要成功！”");
            }
            else
            {
                system("pause");
            }
            break;
        }
        case(GYM2):
        {
            cout << "挑战银叶市道馆！" << endl;
            if(!pikachu.getMedalOfWisdom())
            {
                showStory("神秘组织-林：“一只皮卡丘...跑来这干嘛？”");
                showStory("神秘组织-林：“皮卡丘...难道就是你打败了那个蠢蛋吗？”");
                showStory("你：“看来你的消息很灵通嘛...”");
                showStory("你：“我来维持正义了~”");
                showStory("神秘组织-林：“有意思，让我来看看你有什么本事！”");
            }
            Pokemon gym2pokemon = *pokemonList[33];
            bool loseflag = pikachu.combat(gym2pokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...挑战道馆失败了吗...下次一定要成功！”");
            }
            else
                system("pause");
            break;
        }
        case(GYM3):
        {
            cout << "挑战静水市道馆！" << endl;
            if(!pikachu.getMedalOfFriendship())
            {
                showStory("神秘组织-火：“很厉害嘛你，组织里都听说你的事了。”");
                showStory("神秘组织-火：“你已经被组织盯上了，真没想到我运气这么好，这么快就可以解决你了！”");
                showStory("你：“真荣幸能被贵组织通缉啊，可是看起来你们也没多大本事呢。”");
                showStory("神秘组织-火：“我跟那两个蠢货可不一样，小瞧我可是要吃亏的！”");
                showStory("你：“...”");
            }
            Pokemon gym3pokemon = *pokemonList[34];
            bool loseflag = pikachu.combat(gym3pokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...挑战道馆失败了吗...下次一定要成功！”");
            }
            else
                system("pause");
            break;
        }
        case(GYM4):
        {
            cout << "挑战飞龙市道馆！" << endl;
            if(!pikachu.getMedalOfHope())
            {
                showStory("神秘组织-山：“真了不得啊，竟然能闯到我这里来。”");
                showStory("神秘组织-山：“看来真是不能小瞧你啊。”");
                showStory("你：“这么久了，终于有人这么说了！”");
                showStory("神秘组织-山：“别太嚣张了！今天就是你的死期！”");
                showStory("你：“...”");
            }
            Pokemon gym4pokemon = *pokemonList[35];
            bool loseflag = pikachu.combat(gym4pokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...挑战道馆失败了吗...下次一定要成功！”");
            }
            else
                system("pause");
            break;
        }
        case(POKEUNION):
        {
            cout << "挑战精灵联盟！" << endl;
            if(!pikachu.getMedalOfHope())
            {
                showStory("神秘组织-阴雷：“有点意思，看来你并不是一只普通的皮卡丘。”");
                showStory("神秘组织-阴雷：“不管你身世如何，你是不可能战胜我的。”");
                showStory("神秘组织-阴雷：“我对你很有兴趣，不如为我做事吧，怎么样？”");
                showStory("你：“...我只想说你想太多了！”");
                showStory("神秘组织-阴雷：“那看来只有武力收服你了！”");
            }
            Pokemon pokeunionpokemon = *pokemonList[36];
            bool loseflag = pikachu.combat(pokeunionpokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...挑战精灵联盟失败了吗...下次一定要成功！”");
            }
            else
                system("pause");
            break;
        }
        case(ZONE1):
        {
            cout << "你进入战斗乐园1-2级精灵区！" << endl;
            system("pause");
            int id = rand() % 6;
            Pokemon zone1pokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(zone1pokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...真像一场噩梦...”");
            }
            else
                system("pause");
            break;
        }
        case(ZONE2):
        {
            cout << "你进入战斗乐园3-4级精灵区！" << endl;
            system("pause");
            int id = rand() % 8 + 6;
            Pokemon zone2pokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(zone2pokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...真像一场噩梦...”");
            }
            else
                system("pause");
            break;
        }
        case(ZONE3):
        {
            cout << "你进入战斗乐园5级精灵区！" << endl;
            system("pause");
            int id = rand() % 4 + 14;
            Pokemon zone3pokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(zone3pokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...真像一场噩梦...”");
            }
            else
                system("pause");
            break;
        }
        case(ZONE4):
        {
            cout << "你进入战斗乐园6级精灵区！" << endl;
            system("pause");
            int id = rand() % 4 + 18;
            Pokemon zone4pokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(zone4pokemon);
            if(loseflag)
            {
                showStory("你的眼前一黑...");
                showStory("......");
                showStory("“刚刚发生了什么来着...真像一场噩梦...”");

            }
            else
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

void CityMap::showStory(string line)
{
    system("cls");
    cout << "************************************************************************************************************" << endl;
    cout << "*                                                                                                          *" << endl;
    cout << "*    " << setfill('\0') << left << setw(100) << line << "  *" << endl;
    cout << "*                                                                                                          *" << endl;
    cout << "************************************************************************************************************" << endl;
    system("pause");
}

/*void CityMap::ramdonWildPokemon(vector <Pokemon *> &pokemonList)
{
    int id = rand() % 10;
    wildpokemon = *pokemonList[id];
    //Pokemon wildpokemon = pokemonList[];
}
*/
