#ifndef ADD_MANUAL
#define ADD_MANUAL

#include <vector>
#include "struct.h"
using namespace std;

//Function : void add_manual
//Input : vector of records named data
//Output : None (void type)
//What does the function do?
//The function add_manual basically provide a way for the user to input
//a record manually. It means, user can only input 1 record for each function call.
//User can also input every elements of record one-by-one
void add_manual(vector<record> &data);

#endif
