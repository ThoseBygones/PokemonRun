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

    /*��ʼ�����λ��*/
    //city[getY()][getX()] = '*';

    /*��ʼ��ѩ���������ǽ*/
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

    /*��ʼ��ѩ����ĳ���*/
    for(int j=24; j<=26; j++)
    {
        status[0][j] = UPLINK;
    }
    status[12][0] = LEFTLINK;

    /*��ʼ�������̵�*/
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

    /*��ʼ������ļ�*/
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

    /*��ʼ����������*/
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

    /*��ʼ�����λ��*/
    //city[getY()][getX()] = '*';

    /*��ʼ����԰�г�����ǽ*/
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

    /*��ʼ����԰�еĳ���*/
    for(int j=24; j<=26; j++)
    {
        status[0][j] = UPLINK;
    }
    status[12][WIDTH - 1] = RIGHTLINK;

    /*��ʼ�������̵�*/
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

    /*��ʼ����������*/
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

    /*��ʼ���������*/
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

    /*��ʼ�����λ��*/
    //city[getY()][getX()] = '*';

    /*��ʼ����Ҷ�г�����ǽ*/
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

    /*��ʼ����Ҷ�еĳ���*/
    status[12][WIDTH - 1] = RIGHTLINK;
    for(int j=24; j<=26; j++)
    {
        status[0][j] = UPLINK;
        status[LENGTH - 1][j] = DOWNLINK;
    }

    /*��ʼ�������̵�*/
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

    /*��ʼ����������*/
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

    /*��ʼ���������*/
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

    /*��ʼ�����λ��*/
    //city[getY()][getX()] = '*';

    /*��ʼ����ˮ�г�����ǽ*/
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

    /*��ʼ����ˮ�еĳ���*/
    status[12][0] = LEFTLINK;
    for(int j=24; j<=26; j++)
    {
        status[LENGTH - 1][j] = DOWNLINK;
    }

    /*��ʼ�������̵�*/
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

    /*��ʼ����������*/
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

    /*��ʼ���������*/
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

    /*��ʼ�����λ��*/
    //city[getY()][getX()] = '*';

    /*��ʼ�������г�����ǽ*/
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

    /*��ʼ�������еĳ���*/
    status[12][WIDTH - 1] = RIGHTLINK;

    /*��ʼ�������̵�*/
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

    /*��ʼ����������*/
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

    /*��ʼ���������*/
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

    /*��ʼ�����λ��*/
    //city[getY()][getX()] = '*';

    /*��ʼ���������˳�����ǽ*/
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

    /*��ʼ���������˵ĳ���*/
    for(int j=24; j<=26; j++)
    {
        status[0][j] = UPLINK;
    }

    /*��ʼ�������̵�*/
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

    /*��ʼ����������*/
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

    /*��ʼ���������*/
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

    /*��ʼ�����λ��*/
    //city[getY()][getX()] = '*';

    /*��ʼ��ս����԰��ǽ*/
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

    /*��ʼ��ս����԰�ĳ���*/
    status[12][0] = LEFTLINK;
    for(int j=24; j<=26; j++)
    {
        status[LENGTH - 1][j] = DOWNLINK;
    }

    /*��ʼ�����ϽǷ���*/
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

    /*��ʼ�����ϽǷ���*/
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

    /*��ʼ�����½Ƿ���*/
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

    /*��ʼ�����½Ƿ���*/
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

    /*��ʼ�����λ��*/
    //city[getY()][getX()] = '*';

    /*��ʼ������ɭ����ǽ*/
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

    /*��ʼ������ɭ�ֳ���*/
    status[12][0] = LEFTLINK;
    status[12][WIDTH - 1] = RIGHTLINK;
    for(int j=24; j<=26; j++)
    {
        status[LENGTH - 1][j] = DOWNLINK;
    }

    /*��ʼ���Թ��ڲ�*/
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
        cout << "���������������������룡" << endl;
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
            cout << "�޷��ƶ���Ŀ�����꣡" << endl;
            system("pause");
            break;
        }
        case(POKESTORE):
        {
            cout << "�����̵꣡" << endl;
            system("pause");
            pokemonshop.showShop(pikachu);
            pikachu.addItems();
            break;
        }
        case(HOME):
        {
            cout << "�ؼң�" << endl;
            system("pause");
            break;
        }
        case(POKECENTER):
        {
            cout << "���뾫�����ģ�" << endl;
            system("pause");
            system("cls");
            cout << "******************************" << endl;
            cout << "*   �Ƿ�Ҫ�ظ��������ֵ��   *" << endl;
            cout << "*       1.��    2.��         *" << endl;
            cout << "******************************" << endl;
            cout << "�����룺";
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
                    cout << "��ӭ����~" << endl;
                    system("pause");
                    break;
                }
                case('2'):
                {
                    flag = true;
                    cout << "û�����˾ͱ���ǿ�Լ�����ӭ����~" << endl;
                    system("pause");
                    break;
                }
                default:
                {
                    cout << "��������������������룡" << endl;
                    system("pause");
                    system("cls");
                    cout << "******************************" << endl;
                    cout << "*   �Ƿ�Ҫ�ظ��������ֵ��   *" << endl;
                    cout << "*       1.��    2.��         *" << endl;
                    cout << "******************************" << endl;
                    cout << "�����룺";
                }
                }
                if(flag)
                    break;
            }
            break;
        }
        case(WILDPOKE):
        {
            cout << "һֻ�������˳�����" << endl;
            system("pause");
            int id = rand() % 10 + 22;
            Pokemon wildpokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(wildpokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...����һ��ج��...��");
            }
            else
                system("pause");
            break;
        }
        case(GYM1):
        {
            cout << "��ս��԰�е��ݣ�" << endl;
            if(!pikachu.getMedalOfCourage())
            {
                showStory("������֯-�磺���������ľ��飬�������������Ͻ��߿����ⲻ��������ĵط�����");
                showStory("�㣺������ݵ������е���ְ���Ӧ�þ��ǰ��С�������Щ���е�һ���ˡ�");
                showStory("������֯-�硰�Ͻ��߿����ٲ����ҾͲ������ˣ���");
                showStory("�㣺��...��");
            }
            Pokemon gym1pokemon = *pokemonList[32];
            bool loseflag = pikachu.combat(gym1pokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...��ս����ʧ������...�´�һ��Ҫ�ɹ�����");
            }
            else
            {
                system("pause");
            }
            break;
        }
        case(GYM2):
        {
            cout << "��ս��Ҷ�е��ݣ�" << endl;
            if(!pikachu.getMedalOfWisdom())
            {
                showStory("������֯-�֣���һֻƤ����...����������");
                showStory("������֯-�֣���Ƥ����...�ѵ������������Ǹ������𣿡�");
                showStory("�㣺�����������Ϣ����ͨ��...��");
                showStory("�㣺������ά��������~��");
                showStory("������֯-�֣�������˼����������������ʲô���£���");
            }
            Pokemon gym2pokemon = *pokemonList[33];
            bool loseflag = pikachu.combat(gym2pokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...��ս����ʧ������...�´�һ��Ҫ�ɹ�����");
            }
            else
                system("pause");
            break;
        }
        case(GYM3):
        {
            cout << "��ս��ˮ�е��ݣ�" << endl;
            if(!pikachu.getMedalOfFriendship())
            {
                showStory("������֯-�𣺡����������㣬��֯�ﶼ��˵������ˡ���");
                showStory("������֯-�𣺡����Ѿ�����֯�����ˣ���û�뵽��������ô�ã���ô��Ϳ��Խ�����ˣ���");
                showStory("�㣺���������ܱ�����֯ͨ���������ǿ���������Ҳû������ء���");
                showStory("������֯-�𣺡��Ҹ������������ɲ�һ����С���ҿ���Ҫ�Կ��ģ���");
                showStory("�㣺��...��");
            }
            Pokemon gym3pokemon = *pokemonList[34];
            bool loseflag = pikachu.combat(gym3pokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...��ս����ʧ������...�´�һ��Ҫ�ɹ�����");
            }
            else
                system("pause");
            break;
        }
        case(GYM4):
        {
            cout << "��ս�����е��ݣ�" << endl;
            if(!pikachu.getMedalOfHope())
            {
                showStory("������֯-ɽ�������˲��ð�����Ȼ�ܴ���������������");
                showStory("������֯-ɽ�����������ǲ���С���㰡����");
                showStory("�㣺����ô���ˣ�����������ô˵�ˣ���");
                showStory("������֯-ɽ������̫�����ˣ��������������ڣ���");
                showStory("�㣺��...��");
            }
            Pokemon gym4pokemon = *pokemonList[35];
            bool loseflag = pikachu.combat(gym4pokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...��ս����ʧ������...�´�һ��Ҫ�ɹ�����");
            }
            else
                system("pause");
            break;
        }
        case(POKEUNION):
        {
            cout << "��ս�������ˣ�" << endl;
            if(!pikachu.getMedalOfHope())
            {
                showStory("������֯-���ף����е���˼�������㲢����һֻ��ͨ��Ƥ���𡣡�");
                showStory("������֯-���ף���������������Σ����ǲ�����սʤ�ҵġ���");
                showStory("������֯-���ף����Ҷ��������Ȥ������Ϊ�����°ɣ���ô������");
                showStory("�㣺��...��ֻ��˵����̫���ˣ���");
                showStory("������֯-���ף����ǿ���ֻ�������շ����ˣ���");
            }
            Pokemon pokeunionpokemon = *pokemonList[36];
            bool loseflag = pikachu.combat(pokeunionpokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...��ս��������ʧ������...�´�һ��Ҫ�ɹ�����");
            }
            else
                system("pause");
            break;
        }
        case(ZONE1):
        {
            cout << "�����ս����԰1-2����������" << endl;
            system("pause");
            int id = rand() % 6;
            Pokemon zone1pokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(zone1pokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...����һ��ج��...��");
            }
            else
                system("pause");
            break;
        }
        case(ZONE2):
        {
            cout << "�����ս����԰3-4����������" << endl;
            system("pause");
            int id = rand() % 8 + 6;
            Pokemon zone2pokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(zone2pokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...����һ��ج��...��");
            }
            else
                system("pause");
            break;
        }
        case(ZONE3):
        {
            cout << "�����ս����԰5����������" << endl;
            system("pause");
            int id = rand() % 4 + 14;
            Pokemon zone3pokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(zone3pokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...����һ��ج��...��");
            }
            else
                system("pause");
            break;
        }
        case(ZONE4):
        {
            cout << "�����ս����԰6����������" << endl;
            system("pause");
            int id = rand() % 4 + 18;
            Pokemon zone4pokemon = *pokemonList[id];
            bool loseflag = pikachu.combat(zone4pokemon);
            if(loseflag)
            {
                showStory("�����ǰһ��...");
                showStory("......");
                showStory("���ոշ�����ʲô����...����һ��ج��...��");

            }
            else
                system("pause");
            break;
        }
        case(LEFTLINK):
        {
            cout << "������һ������" << endl;
            system("pause");
            leftExit();
            //initialPlayerLocation(newX,newY);
            break;
        }
        case(RIGHTLINK):
        {
            cout << "������һ������" << endl;
            system("pause");
            rightExit();
            //initialPlayerLocation(newX,newY);
            break;
        }
        case(UPLINK):
        {
            cout << "������һ������" << endl;
            system("pause");
            upExit();
            //initialPlayerLocation(newX,newY);
            break;
        }
        case(DOWNLINK):
        {
            cout << "������һ������" << endl;
            system("pause");
            downExit();
            //initialPlayerLocation(newX,newY);
            break;
        }
        case(NPC):
        {
            cout << "***********************" << endl;
            cout << "*                     *" << endl;
            cout << "*  �Ƿ����NPC�Ի���  *" << endl;
            cout << "*                     *" << endl;
            cout << "*  1.��    2.��       *" << endl;
            cout << "*                     *" << endl;
            cout << "***********************" << endl;
            int num;
            cout << "�����룺";
            while(cin >> num)
            {
                system("cls");
                if(num == 1)
                {
                    cout << "***************************" << endl;
                    cout << "*                         *" << endl;
                    cout << "*  NPC: ���Ǹ�ɵ�ƣ�����  *" << endl;
                    cout << "*                         *" << endl;
                    cout << "***************************" << endl;
                    system("pause");
                    break;
                }
                else if(num == 2)
                    break;
                else
                {
                    cout << "���������������������룺" << endl;
                    cout << "�Ƿ����NPC�Ի���" << endl;
                    cout << "1.��    2.��" << endl;
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
    cout << "���������ʾ  ����  [w] ����    [s] ����    [a] ����    [d] ����" << endl;
    cout << "�����������";
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
    cout << "�����ڵ�����Ϊ ( " << x << " , " << y << " );" << endl;
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
