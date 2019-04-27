#ifndef REMOVE
#define REMOVE

#include "struct.h"
#include <vector>
using namespace std;

//Function : int removeData
//Input : -a vector of record named data
//        -int dateYear
//        -int dateMonth
//        -int dateDay
//Output : int
//What does the function do?
//To search the data based on user input, store it on a smaller vector.
int removeData(vector <record> &data, int dateYear, int dateMonth, int dateDay);

//Function : void removalProcess
//Input : -a vector of record named data
//        -int dataNumber
//Output : None (void type)
//What does the function do?
//To remove the data from the main vector "data", based on the information stored in a smaller vector.
void removalProcess(int dataNumber, vector <record> &data);

//Function : void remove
//Input : -a vector of record named data
//Output : None (void type)
//What does the function do?
//The whole process of collecting the searched data, putting on a smaller vector, followed by scanning the main vector "data" and finally remove it.
void remove(vector <record> &data);

#endif
