#include <string>
using namespace std;

struct Flower
{
  virtual string str() = 0;
};

struct Rose : Flower
{
  string str() override {
    string retStr = "A rose";
    return retStr;
  }
};

struct RedFlower : Flower
{
    Flower& flower;
    
    RedFlower(Flower &flower): flower(flower){}
    
    string str() override {
        auto retStr = flower.str();
        if (retStr.find("red") != string::npos)
             return retStr;
        if (retStr.find("blue") != string::npos)
             return retStr + " and red";
        return retStr + " that is red";
  }
};

struct BlueFlower : Flower
{
    Flower& flower;
    
    BlueFlower(Flower &flower): flower(flower){}
    
    string str() override {
        auto retStr = flower.str();
        if (retStr.find("blue") != string::npos)
             return retStr;
        if (retStr.find("red") != string::npos)
             return retStr + " and blue";
        return retStr + " that is blue";
  }
};
