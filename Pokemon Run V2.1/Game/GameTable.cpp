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
    cout << "*                                          ���汦����ð��                                          *" << endl;
    cout << "*                                            ���İ�V1.0                                            *" << endl;
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
    cout << "      *    1.��������루����Ϸ��    2.�����������������Ϸ��    3.�������루�˳���Ϸ��    *" << endl;
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
    cout << "   *    1.����    2.��ͼ    3.״̬    4.ϵͳ    *" << endl;
    cout << "   *                                            *" << endl;
    cout << "   **********************************************" << endl;
}

void GameTable::showSystemTable()
{
    system("cls");
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*                                      *" << endl;
    cout << "*      1.������Ϸ      2.������Ϸ      *" << endl;
    cout << "*      3.��ȡ��Ϸ      4.�˳���Ϸ      *" << endl;
    cout << "*                                      *" << endl;
    cout << "****************************************" << endl;
    cout << "��ѡ��";
}

void GameTable::showSaveFilesList(ifstream inFile[])
{
    system("cls");
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*                                      *" << endl;
    if(inFile[0])
        cout << "*    1. ð�ռ�¼1                      *" << endl;
    else
        cout << "*    1. �յĴ浵                       *" << endl;
    cout << "*                                      *" << endl;
    if(inFile[1])
        cout << "*    2. ð�ռ�¼2                      *" << endl;
    else
        cout << "*    2. �յĴ浵                       *" << endl;
    cout << "*                                      *" << endl;
    if(inFile[2])
        cout << "*    3. ð�ռ�¼3                      *" << endl;
    else
        cout << "*    3. �յĴ浵                       *" << endl;
    cout << "*                                      *" << endl;
    cout << "****************************************" << endl;
    cout << "��ѡ��";
}

void GameTable::showSaveFilesList2(fstream file[])
{
    system("cls");
    cout << endl;
    cout << "****************************************" << endl;
    cout << "*                                      *" << endl;
    if(file[0])
        cout << "*    1. ð�ռ�¼1                      *" << endl;
    else
        cout << "*    1. �յĴ浵                       *" << endl;
    cout << "*                                      *" << endl;
    if(file[1])
        cout << "*    2. ð�ռ�¼2                      *" << endl;
    else
        cout << "*    2. �յĴ浵                       *" << endl;
    cout << "*                                      *" << endl;
    if(file[2])
        cout << "*    3. ð�ռ�¼3                      *" << endl;
    else
        cout << "*    3. �յĴ浵                       *" << endl;
    cout << "*                                      *" << endl;
    cout << "****************************************" << endl;
    cout << "��ѡ��";
}
