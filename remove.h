#ifndef REMOVE
#define REMOVE
#include <iostream>
#include "struct.h"
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct deleteRecord
{
  int date,month,year,index;
  double amount;
  string category,currency,incomeOrExpense,note;
};

vector <deleteRecord> removeRecord;

int removeData(vector <record> &data, int dateYear, int dateMonth, int dateDay, string defaultCurrency)
{
  int dataCounter = 0;
  for (int i=0;i<data.size();++i)
  {
    if (data[i].year == dateYear)
    {
      if (data[i].month == dateMonth)
      {
        if (data[i].date == dateDay)
        {
          deleteRecord info_data;
          info_data.date = dateDay;
          info_data.month = dateMonth;
          info_data.year = dateYear;
          info_data.index = i;
          info_data.amount = data[i].amount;
          info_data.category = data[i].category;
          info_data.currency = defaultCurrency;
          info_data.incomeOrExpense = data[i].incomeOrExpense;
          info_data.note = data[i].note;
          removeRecord.push_back(info_data);
          dataCounter++;
        }
      }
    }
  }
  return dataCounter;
}

void removalProcess(int dataNumber, vector <record> &data)
{
  int currentIndex = removeRecord[dataNumber-1].index;
  data.erase(data.begin()+currentIndex);
  cout << "Your data has been removed succesfully!" << endl;
}

void remove(vector <record> &data, string defaultCurrency)
{
  char loop_control = 'Y';
  while (loop_control == 'Y')
  {
    cout<<"Please input the date of the record you wish to remove (DD/MM/YYYY): ";
    string dateSearch;
    cin>>dateSearch;
    cout << endl;
    int dateYear = stoi(dateSearch.substr(6,4));
    int dateMonth = stoi(dateSearch.substr(3,2));
    int dateDay = stoi(dateSearch.substr(0,2));
    int data_Counter = removeData(data, dateYear, dateMonth, dateDay, defaultCurrency);

    if (data_Counter==0)
    {
      cout << "You have no record on " << dateSearch << "!" << endl;
      cout << endl;
      cout << "Do you want to remove another record? (Y/N): ";
      char option;
      cin >> option;
      if (option == 'Y')
      {
        loop_control = 'Y';
      }
      else
      {
        loop_control = 'N';
      }
    }
    else
    {
      cout << "Your record on " << dateSearch << " is as follows:" << endl;
      cout << endl;
      cout << "Data  " << "**Date**" << setw(28) << "**Type(I/E)**" << "  Amount         " << "Additional Notes" << endl;
      for (int i=0;i<removeRecord.size();++i)
      {
        cout << setw(4) << i+1 << ". " << removeRecord[i].date << '/' << removeRecord[i].month << '/' << removeRecord[i].year << ' ';
        if (removeRecord[i].incomeOrExpense == "Income")
        {
          cout << setw(18) << removeRecord[i].category << " (";
          cout << removeRecord[i].incomeOrExpense << ')' << ' ';
        }
        else
        {
          cout << setw(18) << removeRecord[i].category << '(';
          cout << removeRecord[i].incomeOrExpense << ')' << ' ';
        }
        cout << setw(4) << removeRecord[i].currency << ' ' << removeRecord[i].amount << ' ';
        cout << setw(30) << removeRecord[i].note << endl;
      }
      int dataNumber;
      cout << endl;
      cout << "Please input the data number you wish to remove: ";
      cin >> dataNumber;
      removalProcess(dataNumber, data);
      cout << endl;
      cout << "Do you want to remove another record? (Y/N): ";
      char option;
      cin >> option;
      if (option == 'Y')
      {
        loop_control = 'Y';
        removeRecord.clear();
      }
      else
      {
        loop_control = 'N';
        removeRecord.clear();
      }
    }
  }
}

#endif
