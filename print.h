#ifndef PRINT
#define PRINT

#include <vector>
#include "struct.h"
using namespace std;

//Function : bool file_is_empty
//Input : string filename and string username
//Output : return true if filename.txt doesn't exist
//         or if it does but contains no data inside
//         return false if filename.txt does exist and contain
//         the string "username"+"\'s\'" as its first data
bool file_is_empty(string filename,string username);

//Function : void print
//Input : vector of records named data and string username
//Output : None
//         print out all the records in data to user-desired filename
void print(vector <record> data,string username);

#endif
