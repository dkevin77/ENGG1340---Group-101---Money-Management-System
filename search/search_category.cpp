#include <iostream>
#include <vector>
#include <iomanip>
#include "struct.h"
using namespace std;

struct search_category_record
{
  int date,month,year,index;
  double amount;
  string category,currency,incomeOrExpense,note;
};

vector <search_category_record> collect_categoryRecord;

int categoryData(vector <record> data, string categoryName)
{
  int dataCounter = 0;
  for (int i=0;i<data.size();++i)
  {
    if (categoryName == data[i].category)
    {
      search_category_record info_data;
      info_data.date = data[i].date;
      info_data.month = data[i].month;
      info_data.year = data[i].year;
      info_data.index = i;
      info_data.amount = data[i].amount;
      info_data.category = data[i].category;
      info_data.currency = data[i].currency;
      info_data.incomeOrExpense = data[i].incomeOrExpense;
      info_data.note = data[i].note;
      collect_categoryRecord.push_back(info_data);
      dataCounter++;
    }
  }
  return dataCounter;
}

void search_category (vector <record> data)
{
  char loop_control = 'Y';
  while (loop_control=='Y')
  {
    cout << "Please input the name of category you wish to search (Salary, Bank_loan, Prize, Gift, Food, Clothes, Entertainment, Transportation, Other): ";
    string categoryName;
    cin >> categoryName;
    if (categoryName == "Other")
    {
      cout << "Please input the name of category that is not mentioned in the above: ";
      string category_otherName;
      cin.ignore();
      getline(cin, category_otherName);
      categoryName = category_otherName;
    }
    else if (categoryName == "Bank_loan")
    {
      categoryName = "Bank loan";
    }
    else
    {
      categoryName = categoryName;
    }
    int data_Counter = categoryData(data, categoryName);
    if (data_Counter == 0)
    {
      cout << "Sorry, we don't have any record on " << "\"" << categoryName << "\" " << "yet. Do you wish to search other category? (Y/N) ";
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
      cout << endl;
      cout << "We found " << collect_categoryRecord.size() << " record(s) on " << "\"" << categoryName << "\". The detail is as follows:" << endl;
      cout << endl;
      cout << setw(5) << "Data" << setw(10) << "    **Date**" << setw(30) << "    **Type(I/E)**" << setw(20) << "       **Amount**" << setw(59) << "   **Additional Notes**" << endl;
      for (int i=0;i<collect_categoryRecord.size();++i)
      {
        string hari = to_string(collect_categoryRecord[i].date);
        string bulan = to_string(collect_categoryRecord[i].month);
        string tahun = to_string(collect_categoryRecord[i].year);
        string col2 = hari + "/" + bulan + "/" + tahun;
        string col3 = collect_categoryRecord[i].category + " (" + collect_categoryRecord[i].incomeOrExpense + ")";
        string col4 = collect_categoryRecord[i].currency;
        double col4b = collect_categoryRecord[i].amount;
        string col5 = collect_categoryRecord[i].note;
        cout << setw(5) << i+1 << ". ";
        cout << setw(10) << col2 ;
        cout << setw(30) << col3;
        cout << setw(7) << col4 << " " << fixed << setprecision(2) << setw(13) << col4b << defaultfloat;
        cout << setw(60) << col5;
        cout << endl;
      }
      cout << endl;
      cout << "Do you want to search another category? (Y/N): ";
      char option;
      cin >> option;
      if (option == 'Y')
      {
        loop_control = 'Y';
        collect_categoryRecord.clear();
      }
      else
      {
        loop_control = 'N';
        collect_categoryRecord.clear();
      }
    }
  }
}
