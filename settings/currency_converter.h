#ifndef CURRENCY
#define CURRENCY

#include "struct.h"
#include <vector>

//Function : int findIndexOfDefaultCurrency
//Input : string defaultCurrency
//Output : int which represent the index of current defaultCurrency in the array called country
int findIndexOfDefaultCurrency(string defaultCurrency);

//Function : void show_Currencies
//Input : None
//Output : None (void type)
//         Display all possible currencies that can be used by user to the screen
void show_Currencies();

//Function : void convert
//Input : -a vector of records named data
//        -string defaultCurrency (pass-by-reference)
//Output : None (void type)
//Change the value of defaultCurrency based on user preference and
//Apply new defaultCurrency to all existing records in data
void convert(vector <record> &data, string &defaultCurrency);


#endif
