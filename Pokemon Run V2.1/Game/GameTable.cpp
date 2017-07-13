#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "GameTable.h"
#include "Error.h"
#include "LoadStory.h"
using namespace std;

void GameTable::showGameTable()
{
    cout << "****************************************************************************************************" << endl;
    cout << "*                                                                                                  *" << endl;
    cout << "*                                                                                                  *" << endl;
    cout << "*        @@@@@@@@@    @@@@@@@@   @       @@  @@@@@@@@@@  @        @   @@@@@@@@   @        @        *" << endl;
    cout << "*        @        @  @        @  @     @@    @           @@      @@  @        @  @@       @        *" << endl;
    cout << "*        @        @  @        @  @   @@      @           @ @    @ @  @        @  @ @      @        *" << endl;
    cout << "*        @        @  @        @  @ @@        @           @  @  @  @  @        @  @  @     @        *" << endl;
    cout << "*        @@@@@@@@@   @        @  @@@         @@@@@@@     @   @@   @  @        @  @   @@   @        *" << endl;
    cout << "*        @           @        @  @ @@        @           @        @  @        @  @     @  @        *" << endl;
    cout << "*        @           @        @  @   @@      @           @        @  @        @  @      @ @        *" << endl;
    cout << "*        @           @        @  @     @@    @           @        @  @        @  @       @@        *" << endl;
    cout << "*        @            @@@@@@@@   @       @@  @@@@@@@@@@  @        @   @@@@@@@@   @        @        *" << endl;
    cout << "*                                                                                                  *" << endl;
    cout << "*                                                                                                  *" << endl;
    cout << "*                                          神奇宝贝大冒险                                          *" << endl;
    cout << "*                                            中文版V1.0                                            *" << endl;
    cout << "*                                                                                                  *" << endl;
    cout << "*                                                                                                  *" << endl;
    cout << "*                                @@@@@@@@@   @        @  @        @                                *" << endl;
    cout << "*                                @        @  @        @  @@       @                                *" << endl;
    cout << "*                                @        @  @        @  @ @      @                                *" << endl;
    cout << "*                                @        @  @        @  @  @     @                                *" << endl;
    cout << "*                                @@@@@@@@@   @        @  @   @@   @                                *" << endl;
    cout << "*                                @ @@        @        @  @     @  @                                *" << endl;
    cout << "*                                @   @@      @        @  @      @ @                                *" << endl;
    cout << "*                                @     @@    @        @  @       @@                                *" << endl;
    cout << "*                                @       @@   @@@@@@@@   @        @                                *" << endl;
    cout << "*                                                                                                  *" << endl;
    cout << "*                                                                                                  *" << endl;
    cout << "****************************************************************************************************" << endl;
    cout << endl;
    cout << "      ****************************************************************************************" << endl;
    cout << "      *                                                                                      *" << endl;
    cout << "      *    1.最初的梦想（新游戏）    2.梦想的延续（载入游戏）    3.完结的梦想（退出游戏）    *" << endl;
    cout << "      *                                                                                      *" << endl;
    cout << "      ****************************************************************************************" << endl;
}

void GameTable::loadStory()
{
    string line;
    ifstream myFile;
    vector <Story *> passagesSave(25);
    //stack <Story *> passagesShow;
    int index = 0;
    myFile.open("StoryAtTheVeryBegining.txt", ios_base::in);
    try
    {
        if(!myFile)
        {
            throw runtime_error("The file does not exist!");
        }
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    if(myFile)
    {
        while(!myFile.eof())
        {
            getline(myFile, line);
            istringstream is(line);
            string passage;
            is >> passage;
            passagesSave[index] = new Story(passage);
            passagesSave[index]->showPassages();
            index++;
            system("pause");
            system("cls");
        }
    }
    myFile.close();
}

void GameTable::showOperationTable()
{
    cout << endl;
    cout << "   **********************************************" << endl;
    cout << "   *                                            *" << endl;
    cout << "   *    1.背包    2.地图    3.状态    4.系统    *" << endl;
    cout << "   *                                            *" << endl;
    cout << "   **********************************************" << endl;
}

void GameTable::showSystemTable()
{
    system("cls");
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*                                      *" << endl;
    cout << "*      1.继续游戏      2.保存游戏      *" << endl;
    cout << "*      3.读取游戏      4.退出游戏      *" << endl;
    cout << "*                                      *" << endl;
    cout << "****************************************" << endl;
    cout << "请选择：";
}

void GameTable::showSaveFilesList(ifstream inFile[])
{
    system("cls");
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*                                      *" << endl;
    if(inFile[0])
        cout << "*    1. 冒险记录1                      *" << endl;
    else
        cout << "*    1. 空的存档                       *" << endl;
    cout << "*                                      *" << endl;
    if(inFile[1])
        cout << "*    2. 冒险记录2                      *" << endl;
    else
        cout << "*    2. 空的存档                       *" << endl;
    cout << "*                                      *" << endl;
    if(inFile[2])
        cout << "*    3. 冒险记录3                      *" << endl;
    else
        cout << "*    3. 空的存档                       *" << endl;
    cout << "*                                      *" << endl;
    cout << "****************************************" << endl;
    cout << "请选择：";
}

void GameTable::showSaveFilesList2(fstream file[])
{
    system("cls");
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*                                      *" << endl;
    if(file[0])
        cout << "*    1. 冒险记录1                      *" << endl;
    else
        cout << "*    1. 空的存档                       *" << endl;
    cout << "*                                      *" << endl;
    if(file[1])
        cout << "*    2. 冒险记录2                      *" << endl;
    else
        cout << "*    2. 空的存档                       *" << endl;
    cout << "*                                      *" << endl;
    if(file[2])
        cout << "*    3. 冒险记录3                      *" << endl;
    else
        cout << "*    3. 空的存档                       *" << endl;
    cout << "*                                      *" << endl;
    cout << "****************************************" << endl;
    cout << "请选择：";
}
