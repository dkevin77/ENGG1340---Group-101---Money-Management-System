#ifndef ADD_FILE
#define ADD_FILE

#include <vector>
#include <string>
#include "struct.h"

using namespace std;

//Function : void addDate
//Input : -record dataAdded (pass by reference)
//        -string dateAdded
//Output : None (void type)
//What does the function do?
//This function basically change the value of dataAdded.date to the same as dateAdded
//Before that, we need to convert dateAdded to int type using stoi
void addDate(record &dataAdded, string dateAdded);

//Function : void addIncomeOrExpense
//Input : -record dataAdded (pass by reference)
//        -string incomeOrExpenseAdded
//Output : None (void type)
//What does the function do?
//This function basically change the value of dataAdded.incomeOrExpense to the same as incomeOrExpenseAdded
void addIncomeOrExpense(record &dataAdded, string incomeOrExpenseAdded);

//Function : void addCategory
//Input : -record dataAdded (pass by reference)
//        -string incomeOrExpense
//        -string category
//        -string if_other
//Output : int
//What does the function do?
//This function basically change the value of dataAdded.category to the same as category
int addCategory(record &dataAdded, string incomeOrExpense, string category, string if_other);

//Function : void addAmount
//Input : -record dataAdded (pass by reference)
//        -string amount
//Output : None (void type)
//What does the function do?
//This function basically change the value of dataAdded.amount to the same as amount
//Before that, we need to convert amount to double type using stod
void addAmount(record &dataAdded, string amount);

//Function : void addNote
//Input : -record dataAdded (pass by reference)
//        -string arr[]
//        -int index
//        -int num_of_element_in_line
//Output : None (void type)
//What does the function do?
//This function basically change the value of dataAdded.Note to the same as Note
//Note is stored in arr[x], where x depends on whether the user's category is other or not
void addNote(record &dataAdded, string arr[], int index, int num_of_element_in_line);

//Function : int count_element_in_line
//Input : -string line
//Output : int
//What does the function do?
//This function count how many elements are there in line (separated by space)
int count_element_in_line(string line);

//Function : void add_line_from_file
//Input : -vector of records named data
//        -string line
//Output : None (void type)
//What does the function do?
//This function basically add record to data based on each values in line
void add_line_from_file(vector <record> &data, string line);

//Function : void add_file
//Input : -vector of records named data
//        -string filename
//Output : None (void type)
//What does the function do?
//This function basically add records to data based on each lines in filename
void add_file(vector <record> &data , string filename);


#endif
