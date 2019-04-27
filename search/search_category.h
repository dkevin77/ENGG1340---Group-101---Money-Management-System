#ifndef SEARCH_CATEGORY
#define SEARCH_CATEGORY

using namespace std;

//Function : int categoryData
//Input : -a vector of records named data
//Output : int
//What does the function do?
//To move the data that has the category based on user input, and store it on a smaller vector.
int categoryData(vector <record> data, string categoryName);

//Function : void search_category
//Input : -a vector of recrods named data
//Output : None (void type)
//What does the function do?
//To print the data on the smaller vector which contains the user-inputted category, allowing the user to view the data that has certain category.
void search_category (vector <record> data);

#endif
