#ifndef ADDCURRENCY
#define ADDCURRENCY
#include <vector>
#include <string>
#include "struct.h"
using namespace std;

//Function : void addCurrency
//Input : -a vector of records named data
//        -string defaultCurrency
//Output : None (void type)
//What does the function do?
//The function addCurency basically changes the value of data[i].currency to
//the same ass defaultCurrency for every records in data
void addCurency(vector <record> &data,string defaultCurrency);

#endif
