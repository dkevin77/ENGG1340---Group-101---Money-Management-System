#ifndef EDIT
#define EDIT
#include <iostream>
#include "struct.h"
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct findRecord
{
  int date,month,year,index;
  double amount;
  string category,currency,incomeOrExpense,note;
};

vector <findRecord> collectRecord;

int moveData(vector <record> &data, int dateYear, int dateMonth, int dateDay, string defaultCurrency)
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
          findRecord info_data;
          info_data.date = dateDay;
          info_data.month = dateMonth;
          info_data.year = dateYear;
          info_data.index = i;
          info_data.amount = data[i].amount;
          info_data.category = data[i].category;
          info_data.currency = defaultCurrency;
          info_data.incomeOrExpense = data[i].incomeOrExpense;
          info_data.note = data[i].note;
          collectRecord.push_back(info_data);
          dataCounter++;
        }
      }
    }
  }
  return dataCounter;
}

void editProcess(int dataNumber, vector <record> &data)
{
  int currentIndex = collectRecord[dataNumber-1].index;
  cout << "Edit the date to (DD/MM/YYYY): ";
  string editDate;
  cin >> editDate;
  int editDay = stoi(editDate.substr(0,2));
  int editMonth = stoi(editDate.substr(3,2));
  int editYear = stoi(editDate.substr(6,4));
  data[currentIndex].date = editDay;
  data[currentIndex].month = editMonth;
  data[currentIndex].year = editYear;
  cout << "Edit type of record to (Income/Expense): ";
  string editIncomeExpense;
  cin >> editIncomeExpense;
  if (editIncomeExpense == "Income")
  {
    data[currentIndex].incomeOrExpense = "Income";
    cout << "Edit the category to (Salary, Bank loan, Prize, Gift, Other): ";
    string editIncomeCategory;
    cin.ignore();
    getline(cin,editIncomeCategory);
    if (editIncomeCategory == "Other")
    {
      cout << "Please specify the Category: ";
      string newCategory;
      cin,getline(cin,newCategory);
      data[currentIndex].category = newCategory;
    }
    else
      data[currentIndex].category = editIncomeCategory;
  }
  else
  {
    data[currentIndex].incomeOrExpense = "Expense";
    cout << "Edit the category to (Food, Clothes, Entertainment, Transportation, Other): ";
    string editExpenseCategory;
    cin.ignore();
    getline(cin,editExpenseCategory);
    if (editExpenseCategory == "Other")
    {
      cout << "Please specify the Category: ";
      string newCategory;
      cin,getline(cin,newCategory);
      data[currentIndex].category = newCategory;
    }
    else
      data[currentIndex].category = editExpenseCategory;
  }
  cout << "Edit the amount to: ";
  double editAmount;
  cin >> editAmount;
  data[currentIndex].amount = editAmount;
  cout << "Edit the note to: ";
  string editNote;
  cin.ignore();
  getline(cin, editNote);
  data[currentIndex].note = editNote;
  cout << "Your data has been edited succesfully!" << endl;
}

void edit(vector <record> &data, string defaultCurrency)
{
  char loop_control = 'Y';
  while (loop_control == 'Y')
  {
    cout<<"Please input the date of the record you wish to edit (DD/MM/YYYY): ";
    string dateSearch;
    cin>>dateSearch;
    cout << endl;
    int dateYear = stoi(dateSearch.substr(6,4));
    int dateMonth = stoi(dateSearch.substr(3,2));
    int dateDay = stoi(dateSearch.substr(0,2));
    int data_Counter = moveData(data, dateYear, dateMonth, dateDay, defaultCurrency);

    if (data_Counter==0)
    {
      cout << "You have no record on " << dateSearch << "!" << endl;
      cout << endl;
      cout << "Do you want to edit another record? (Y/N): ";
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
      for (int i=0;i<collectRecord.size();++i)
      {
        cout << setw(4) << i+1 << ". " << collectRecord[i].date << '/' << collectRecord[i].month << '/' << collectRecord[i].year << ' ';
        if (collectRecord[i].incomeOrExpense == "Income")
        {
          cout << setw(18) << collectRecord[i].category << " (";
          cout << collectRecord[i].incomeOrExpense << ')' << ' ';
        }
        else
        {
          cout << setw(18) << collectRecord[i].category << '(';
          cout << collectRecord[i].incomeOrExpense << ')' << ' ';
        }
        cout << setw(4) << collectRecord[i].currency << ' ' << collectRecord[i].amount << ' ';
        cout << setw(30) << collectRecord[i].note << endl;
      }
      int dataNumber;
      cout << endl;
      cout << "Please input the data number you wish to edit: ";
      cin >> dataNumber;
      editProcess(dataNumber, data);
      cout << endl;
      cout << "Do you want to edit another record? (Y/N): ";
      char option;
      cin >> option;
      if (option == 'Y')
      {
        loop_control = 'Y';
        collectRecord.clear();
      }
      else
      {
        loop_control = 'N';
        collectRecord.clear();
      }
    }
  }
}


#endif
