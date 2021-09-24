#include 
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
    int id;
public:
  PersonFactory():id(0){}
  
  Person create_person(const string&amp; name)
  {
    return {id++, name};
  }
};
