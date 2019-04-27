#ifndef SETTINGS
#define SETTINGS

#include <vector>
#include "struct.h"

//Function : void display_settings
//Input : None
//Output : None (void type)
//Display all options to be chosen by user
void display_settings();

//Function : void setting
//Input : -a vector of records named data
//        -string defaultCurrency (pass-by-reference)
//        -string username (pass-by-reference)
//Output : None (void type)
//Do basic setting options based on user preference
void setting(vector <record> &data,string &defaultCurrency,string &username);

#endif
