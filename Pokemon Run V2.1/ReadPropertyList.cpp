#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

class Property
{
public:
    Property(int propId, string propName, string propDesc, int addAttack, int addDenfend, double addEvd, int addHP, int cost): propId(propId), propName(propName), propDesc(propDesc), addAttack(addAttack), addDenfend(addDenfend), addEvd(addEvd), addHP(addHP), cost(cost) {}
    void showInfo();
private:
    int propId;         //物品编号
    string propName;    //物品名称
    string propDesc;    //物品描述
    int addAttack;      //增加攻击
    int addDenfend;     //增加防御
    double addEvd;      //增加躲避率
    int addHP;          //增加血量
    int cost;           //购买花费（所需金钱）
};

/*void Property::showInfo()
{
    cout << p.propId << " " << p.propName << " " << p.propDesc << " " << p.addAttack << " " << p.addDenfend << " " << p.hp << " " << p.addEvd << " " << p.catchRate << " " << p.addHP << " " << p.cost << endl;
}*/

void Property::showInfo()
{
    cout << propId << "  " << propName << "  " << propDesc << "  " << addAttack << "  " << addDenfend << "  " << addEvd << "  " << addHP << "  " << cost << endl;
}

class FileNotFoundException: public std::runtime_error
{
public:
    FileNotFoundException(const string& errormsg): runtime_error(errormsg) {}
};

int main()
{
    string line;
    ifstream myFile;
    vector <Property *> propertyList(12);
    int index = 0;
    myFile.open("PropertyList.txt", ios_base::in);
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
            //fromString(line);
            istringstream is(line);
            int propId;
            string propName;
            string propDesc;
            int addAttack;
            int addDenfend;
            double addEvd;
            int addHP;
            int cost;
            is >> propId >> propName >> propDesc >> addAttack >> addDenfend >> addEvd >> addHP >> cost;
            propertyList[index] = new Property(propId, propName, propDesc, addAttack, addDenfend, addEvd, addHP, cost);
            propertyList[index]->showInfo();
            index++;
        }
    }
    myFile.close();
    return 0;
}
