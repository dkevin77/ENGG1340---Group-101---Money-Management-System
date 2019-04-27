#ifndef EDIT
#define EDIT

#include "struct.h"
#include <vector>
using namespace std;

//Function : int moveData
//Input : -a vector of records named data
//        -int dateYear
//        -int dateMonth
//        -int dateDay
//Output : int
//What does the function do?
//To search the records based on input date (dateYear, dateMonth, dateDay), and then store the searched records to a smaller vector
int moveData(vector <record> &data, int dateYear, int dateMonth, int dateDay);

//Function : void editProcess
//Input : -a vector of records named data
//        -int dataNumber
//Output : None (void type)
//What does the function do?
//To change the data information in a smaller vector according to user input (edit), and then replace the edited information from the smaller vector to the main vector called "data".
void editProcess(int dataNumber, vector <record> &data);

//Function : void edit
//Input : -a vector of records named data
//Output : None (void type)
//What does the function do?
//The whole process of scanning and searching data based on user input, put it on a smaller vector, replace it with the updated data, and then print the new data to the console after it has been updated.
void edit(vector <record> &data);

#endif
