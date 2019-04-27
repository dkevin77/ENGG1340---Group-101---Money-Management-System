#ifndef ADD
#define ADD

#include <vector>
#include "struct.h"

using namespace std;

//Function : void add
//Input : -vector of records named data
//        -string default Currency
//Output : None
//What does the function do?
//The function add basically provides 2 ways for user to add record(s) to the vector
//User can input their record(s) manually or by file.
void add(vector <record> &data,string defaultCurrency);

#endif
