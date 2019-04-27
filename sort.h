#ifndef SORT
#define SORT

#include <vector>
#include "struct.h"
using namespace std;

//Function : bool isSmallerOrEqual
//Input : record A and record B
//        record is user-defined datatype
//Output : return true if A is chronogically less than or equal to B
//         return false if otherwise
//How does isSmallerOrEqual work?
//It compares 2 record (A and B) firstly by year
//If A.year < B.year, then no matter what the months and dates are
//A is chronogically smaller than B, the function return true
//If A.year > B.year, A is larger chronogically, the function return false
//If A.year==B.year, the function continue to month, and date
bool isSmallerOrEqual(record A, record B);

//Function : void sort
//Input : vector of records named data
//Output : None
//         Use Selection Sort algorithm to sort all the records in data chronogically
void sort(vector <record> &data);

#endif
