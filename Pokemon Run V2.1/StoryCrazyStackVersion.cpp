#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <stack>
using namespace std;

class GameTable
{
public:
    void showGameTable();
    void loadStory();
};

class Story
{
public:
    Story(string passage): passage(passage) {}
    void showPassages();
    void showAllButtom();
    void showPartButtom();
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
    cout << "*                                                                                                  *" << endl;
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
    stack <Story *> passagesShow;
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
            passagesSave[index++] = new Story(passage);
            //passagesSave[index]->showPassages();
            //system("pause");
        }
        index=0;
        passagesShow.push(passagesSave[index]);
        passagesShow.top()->showPassages();
        index++;
        passagesShow.top()->showPartButtom();
        char choice;
        while(cin >> choice)
        {
            if(choice == 'd' && index != 4)
            {
                passagesShow.push(passagesSave[index]);
                index++;
            }
            else if(choice == 'a' && index >= 2)
            {
                passagesShow.pop();
                index--;
            }
            else
            {
                cout << "您的输入有误，请重新输入！" << endl;
            }
            system("cls");
            passagesShow.top()->showPassages();
        }
        /*else
        {
            passagesShow.push(passagesSave[index]);
            passagesShow.top()->showPassages();
            index++;
            system("pause");
        }*/
    }
    myFile.close();
}

void Story::showPassages()
{
    cout << passage << endl;
}

void Story::showAllButtom()
{
    cout << "a.上一句    d.下一句" << endl;
}

void Story::showPartButtom()
{
    cout << "d.下一句" << endl;
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
