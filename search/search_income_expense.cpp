#include <iostream>
#include <vector>
#include <iomanip>
#include "struct.h"
using namespace std;

struct search_incomeexpense_record
{
  int date,month,year,index;
  double amount;
  string category,currency,incomeOrExpense,note;
};

vector <search_incomeexpense_record> collect_income_record;
vector <search_incomeexpense_record> collect_expense_record;

int search_income_data(vector <record> data)
{
  int dataCounter = 0;
  for (int i=0;i<data.size();++i)
  {
    if (data[i].incomeOrExpense=="Income")
    {
      search_incomeexpense_record info_data;
      info_data.date = data[i].date;
      info_data.month = data[i].month;
      info_data.year = data[i].year;
      info_data.index = i;
      info_data.amount = data[i].amount;
      info_data.category = data[i].category;
      info_data.currency = data[i].currency;
      info_data.incomeOrExpense = data[i].incomeOrExpense;
      info_data.note = data[i].note;
      collect_expense_record.push_back(info_data);
      dataCounter++;
    }
  }

  return dataCounter;
}

int search_expense_data(vector <record> data)
{
  int dataCounter = 0;
  for (int i=0;i<data.size();++i)
  {
    if (data[i].incomeOrExpense=="Expense")
    {
      search_incomeexpense_record info_data;
      info_data.date = data[i].date;
      info_data.month = data[i].month;
      info_data.year = data[i].year;
      info_data.index = i;
      info_data.amount = data[i].amount;
      info_data.category = data[i].category;
      info_data.currency = data[i].currency;
      info_data.incomeOrExpense = data[i].incomeOrExpense;
      info_data.note = data[i].note;
      collect_expense_record.push_back(info_data);
      dataCounter++;
    }
  }

  return dataCounter;
}

void search_income_expense(vector <record> data)
{
  char loop_control = 'Y';
  while (loop_control == 'Y')
  {
    cout<<"Please input the type of your record you wish to search (Income/Expense): ";
    string IESearch;
    cin>>IESearch;
    cout << endl;
    if (IESearch == "Income")
    {
      char loop_control_income = 'Y';
      while (loop_control_income == 'Y')
      {
        int data_Counter = search_income_data(data);
        if (data_Counter==0)
        {
          cout << "Sorry, we don't have any record on your income yet." << endl;
          cout << "Do you want to search another record by type? (Y/N): ";
          char option;
          cin >> option;
          cout << endl;
          if (option == 'Y')
          {
            loop_control = 'Y';
            break;
          }
          else
          {
            loop_control = 'N';
            break;
          }
        }
        else
        {
          cout << "We found " << collect_expense_record.size() << " income statement in your record. The detail is as follows:" << endl;
          cout << endl;
          cout << setw(5) << "Data" << setw(10) << "    **Date**" << setw(30) << "    **Type(I/E)**" << setw(20) << "       **Amount**" << setw(59) << "   **Additional Notes**" << endl;
          for (int i=0;i<collect_expense_record.size();++i)
          {
            string hari = to_string(collect_expense_record[i].date);
            string bulan = to_string(collect_expense_record[i].month);
            string tahun = to_string(collect_expense_record[i].year);
            string col2 = hari + "/" + bulan + "/" + tahun;
            string col3 = collect_expense_record[i].category + " (" + collect_expense_record[i].incomeOrExpense + ")";
            string col4 = collect_expense_record[i].currency;
            double col4b = collect_expense_record[i].amount;
            string col5 = collect_expense_record[i].note;
            cout << setw(5) << i+1 << ". ";
            cout << setw(10) << col2 ;
            cout << setw(30) << col3;
            cout << setw(7) << col4 << " " << fixed << setprecision(2) << setw(13) << col4b << defaultfloat;
            cout << setw(60) << col5;
            cout << endl;
          }
          cout << "Do you want to search another record by type? (Y/N): ";
          char option;
          cin >> option;
          cout << endl;
          if (option == 'Y')
          {
            loop_control = 'Y';
            collect_expense_record.clear();
            break;
          }
          else
          {
            loop_control = 'N';
            collect_expense_record.clear();
            break;
          }
        }
      }
    }
    else
    {
      char loop_control_expense = 'Y';
      while (loop_control_expense == 'Y')
      {
        int data_Counter = search_expense_data(data);
        if (data_Counter==0)
        {
          cout << "Sorry, we don't have any record on your expense yet." << endl;
          cout << "Do you want to search another record by type? (Y/N): ";
          char option;
          cin >> option;
          cout << endl;
          if (option == 'Y')
          {
            loop_control = 'Y';
            break;
          }
          else
          {
            loop_control = 'N';
            break;
          }
        }
        else
        {
          cout << "We found " << collect_expense_record.size() << " expenditure in your record. The detail is as follows:" << endl << endl;
          cout << setw(5) << "Data" << setw(10) << "    **Date**" << setw(30) << "    **Type(I/E)**" << setw(20) << "       **Amount**" << setw(59) << "   **Additional Notes**" << endl;
          for (int i=0;i<collect_expense_record.size();++i)
          {
            string hari = to_string(collect_expense_record[i].date);
            string bulan = to_string(collect_expense_record[i].month);
            string tahun = to_string(collect_expense_record[i].year);
            string col2 = hari + "/" + bulan + "/" + tahun;
            string col3 = collect_expense_record[i].category + " (" + collect_expense_record[i].incomeOrExpense + ")";
            string col4 = collect_expense_record[i].currency;
            double col4b = collect_expense_record[i].amount;
            string col5 = collect_expense_record[i].note;
            cout << setw(5) << i+1 << ". ";
            cout << setw(10) << col2 ;
            cout << setw(30) << col3;
            cout << setw(7) << col4 << " " << fixed << setprecision(2) << setw(13) << col4b << defaultfloat;
            cout << setw(60) << col5;
            cout << endl;
          }
          cout << endl;
          cout << "Do you want to search another type? (Y/N): ";
          char option;
          cin >> option;
          cout << endl;
          if (option == 'Y')
          {
            loop_control = 'Y';
            collect_expense_record.clear();
            break;
          }
          else
          {
            loop_control = 'N';
            collect_expense_record.clear();
            break;
          }
        }
      }
    }
  }
}
