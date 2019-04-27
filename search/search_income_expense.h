#ifndef SEARCH_INCOME_EXPENSE
#define SEARCH_INCOME_EXPENSE

#include <vector>
#include "struct.h"

//Function : int search_income_data
//Input : a vector of records named data
//Output : int
//What does the function do?
//To move the data that has the category "Income" and store it on a smaller vector
int search_income_data(vector <record> data);

//Function : int search_expense_data
//Input : a vector of records named data
//Output : int
//What does the function do?
//To move the data that has the category "expense" and store it on a smaller vector
int search_expense_data(vector <record> data);

//Function : void search_income_expense
//Input : a vector of records named data
//Output : None (void type)
//What does the function do?
//To print the searched data on the smaller vector, allowing the user to see the data that has the category of "Income" or "Expense"
void search_income_expense(vector <record> data);

#endif
