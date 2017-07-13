#ifndef LOADSTORY_H_INCLUDED
#define LOADSTORY_H_INCLUDED

#include <string>
using namespace std;

class Story
{
public:
    Story(string passage): passage(passage) {}
    void showPassages();
private:
    string passage;
};

#endif // LOADSTORY_H_INCLUDED
