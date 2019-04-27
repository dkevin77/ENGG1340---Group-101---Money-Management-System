#ifndef STAT
#define STAT

#include <vector>
#include "struct.h"
using namespace std;

//Function : void showStatistic
//Input : None
//Output : None (void type)
//print out all options to be chosen by user
void showStatistic();

//Function : void statistic
//Input : vector of records named data and string username
//Output : None (void type)
//Do statistical calculations based on user preference
void statistic(vector<record> &data, string username);

#endif
