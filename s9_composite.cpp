#include "exercise.h"

int sum(const vector<SomeValues*> items)
{
    int ret{0};
    for (auto itemPtr : items){
        ret += itemPtr->getSum();
    }
    return ret;
}
