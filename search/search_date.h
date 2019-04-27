#ifndef SEARCH_DATE
#define SEARCH_DATE

#include "struct.h"
#include <vector>
using namespace std;

//Function : int searchData
//Input : -a vector of records named data
//        -int dateYear
//        -int dateMonth
//        -int dateDay
//Output : int
//What does the function do?
//To search the data based on user-inputted date, and then store it to a smaller vector
int searchData(vector <record> &data, int dateYear, int dateMonth, int dateDay);

//Function : void search_date
//Input : -a vector of records named data
//Output : None (void type)
//What does the function do?
//To print out the data that has certain data, based on user input
void search_date(vector <record> data);

#endif
