#include <iostream>
#include <string>
#include <vector>
#include <numeric> 
using namespace std;

struct SomeValues
{
    virtual int getSum() = 0;
};

struct SingleValue : SomeValues
{
  int value{ 0 };

  SingleValue() = default;

  explicit SingleValue(const int value)
    : value{value}
  {
  }
  
  // TODO
  int getSum() override {
      //cout << "single sum " << value << endl;
      return value;
  }
};

struct ManyValues : vector<int>, SomeValues
{
  void add(const int value)
  {
    push_back(value);
  }
  
  int getSum() override { 
      int manySum = accumulate(begin(), end(), 0);
      //cout << "many sum " << manySum << endl;
      return manySum;
  }
};

int sum(const vector<SomeValues*> items);
