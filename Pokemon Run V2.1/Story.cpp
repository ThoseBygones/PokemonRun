#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
//#include <stack>
using namespace std;

class GameTable
{
public:
    void showGameTable();
    void showOperationTable();
    void loadStory();
};

class Story
{
public:
    Story(string passage): passage(passage) {}
    void showPassages();
private:
    string passage;
};

class FileNotFoundException: public std::runtime_error
{
public:
    FileNotFoundException(const string& errormsg): runtime_error(errormsg) {}
};


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
    vector <Story *> passagesSave(20);
    //stack <Story *> passagesShow;
    int index = 0;
    myFile.open("Story.txt", ios_base::in);
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
    cout << "      **********************************************" << endl;
    cout << "      *                                            *" << endl;
    cout << "      *    1.背包    2.地图    3.状态    4.系统    *" << endl;
    cout << "      *                                            *" << endl;
    cout << "      **********************************************" << endl;
}

void Story::showPassages()
{
    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*    " << left << setw(60) << passage << "  *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
}

int main()
{
    GameTable gametable;
    gametable.showGameTable();
    int gameIndex;
    //while(cin >> gameIndex)
    //{
    cin >> gameIndex;
    system("cls");
    switch(gameIndex)
    {
    case(1):
    {
        cout << "正在载入游戏..." << endl;
        system("pause");
        system("cls");
        gametable.loadStory();
        gametable.showOperationTable();
        break;
    }
    case(2):
    {
        cout << "正在载入游戏..." << endl;
        system("pause");
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
    //}
    return 0;
}
