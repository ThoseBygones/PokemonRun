#ifndef GAMETABLE_H_INCLUDED
#define GAMETABLE_H_INCLUDED

#include <fstream>
#include <sstream>
using namespace std;

class GameTable
{
public:
    void showGameTable();
    void showOperationTable();
    void loadStory();
    void showSystemTable();
    void showSaveFilesList(ifstream inFile[]);
    void showSaveFilesList2(fstream file[]);
};

#endif // GAMETABLE_H_INCLUDED
