#ifndef STRUCT
#define STRUCT

#include <string>
using namespace std;
//Definition of a new object named record
//This object will hold basic informations about monetary record inputted by user
//It contains important data such as date, category, money, notes, etc
struct record
{
  int date,month,year;
  double amount;
  string category,currency,incomeOrExpense,note;
};

#endif
