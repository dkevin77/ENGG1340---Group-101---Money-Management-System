#include <iostream>
#include "struct.h"
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include "display_options_search.h"
#include "search_date.h"
#include "search_income_expense.h"
#include "search_category.h"
using namespace std;

void search(vector<record> data)
{
  int input = 1;
  while (input)
  {
    display_option_search();
    cin >> input;
    cout << endl;
    switch(input)
    {
      case 0 :
        break;
      case 1 :
        search_date(data);
        break;
      case 2 :
        search_income_expense(data);
        break;
      case 3 :
        search_category(data);
        break;
    }
  }
}
