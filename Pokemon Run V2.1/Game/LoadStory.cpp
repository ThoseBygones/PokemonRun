#include <iostream>
#include <iomanip>
#include "LoadStory.h"
using namespace std;

void Story::showPassages()
{
    cout << "************************************************************************************************************" << endl;
    cout << "*                                                                                                          *" << endl;
    cout << "*    " << left << setw(100) << passage << "  *" << endl;
    cout << "*                                                                                                          *" << endl;
    cout << "************************************************************************************************************" << endl;
}
