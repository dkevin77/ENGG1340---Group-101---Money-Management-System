#ifndef MONTHLY
#define MONTHLY

#include <vector>
#include "struct.h"

using namespace std;

//Function : void getYear
//Input : int year (pass-by-reference)
//Output : None (void type)
//Change the value of year based on user input
void getYear(int &year);

//Function : void getMonth
//Input : int monthIndex (pass-by-reference)
//Output : None (void type)
//Change the value of monthIndex based on user input
void getMonth(int &monthIndex);

//Function : void countData
//Input : -vector of records named data
//        -int monthIndex
//        -int year
//        -int dataCount (pass-by-reference)
//Output : None (void type)
//Change the value of dataCount based on the occurences of record in data
//that have .month==monthIndex and .year=year
void countData(vector<record> data, int monthIndex,int year,int &dataCount);

//Function : void getMonthlyStat
//Input : -vector of records named data
//        -int monthIndex
//        -int year
//        -int dataCount (pass-by-reference)
//        -string username
//Output : None (void type)
//Present statistical report of partiular month to a file
void getMonthlyStat(vector<record> data,int monthIndex, int year,int dataCount,string username);

#endif
