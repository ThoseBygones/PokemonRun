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
    cout << "      *    1.����    2.��ͼ    3.״̬    4.ϵͳ    *" << endl;
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
        cout << "����������Ϸ..." << endl;
        system("pause");
        system("cls");
        gametable.loadStory();
        gametable.showOperationTable();
        break;
    }
    case(2):
    {
        cout << "����������Ϸ..." << endl;
        system("pause");
        break;
    }
    case(3):
    {
        cout << "��Ϸ�����������˳���Ϸ..." << endl;
        return 0;
    }
    default:
    {
        cout << "���������������������룡" << endl;
        break;
    }
    }
    gametable.showGameTable();
    //}
    return 0;
}
