#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int a = 1;
    double b = 0.03;
    string c = "�ɴ�Ѽ";
    ofstream output;
    output.open("Test.txt");
    output << a << " " << b << " " << c;
    output.close();
    return 0;
}
