#ifndef YEARLY
#define YEARLY

#include <vector>
#include "struct.h"

using namespace std;

//Function : void countDataYearly
//Input : -a vector of records named data
//        -int year
//        -int dataCount (pass-by-reference)
//Output : None (void type)
//Change the value of dataCount based on the ocurrences of record
//that have .year==year
void countDataYearly(vector <record> data,int year,int &dataCount);

//Function : void getYearlyStat
//Input : -a vector of records named data
//        -int year
//        -int dataCount
//        -string username
//Output : None (void type)
//Present yearly statistical report to a file
void getYearlyStat(vector <record> data, int year,int dataCount, string username);
#endif
