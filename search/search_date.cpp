#include <iostream>
#include "struct.h"
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct searchRecord
{
  int date,month,year,index;
  double amount;
  string category,currency,incomeOrExpense,note;
};

vector <searchRecord> collect_searchRecord;

int searchData(vector <record> &data, int dateYear, int dateMonth, int dateDay)
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
          searchRecord info_data;
          info_data.date = dateDay;
          info_data.month = dateMonth;
          info_data.year = dateYear;
          info_data.index = i;
          info_data.amount = data[i].amount;
          info_data.category = data[i].category;
          info_data.currency = data[i].currency;
          info_data.incomeOrExpense = data[i].incomeOrExpense;
          info_data.note = data[i].note;
          collect_searchRecord.push_back(info_data);
          dataCounter++;
        }
      }
    }
  }
  return dataCounter;
}

void search_date(vector <record> data)
{
  char loop_control = 'Y';
  while (loop_control == 'Y')
  {
    cout<<"Please input the date of the record you wish to search (DD/MM/YYYY): ";
    string dateSearch;
    cin>>dateSearch;
    cout << endl;
    int dateYear = stoi(dateSearch.substr(6,4));
    int dateMonth = stoi(dateSearch.substr(3,2));
    int dateDay = stoi(dateSearch.substr(0,2));
    int data_Counter = searchData(data, dateYear, dateMonth, dateDay);

    if (data_Counter==0)
    {
      cout << "You have no record on " << dateSearch << "!" << endl;
      cout << endl;
      cout << "Do you want to search another record by date? (Y/N): ";
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
      cout << "We found " << collect_searchRecord.size() << " record(s) in " << dateSearch << ". The detail is as follows:" << endl;
      cout << endl;
      cout << setw(5) << "Data" << setw(10) << "    **Date**" << setw(30) << "    **Type(I/E)**" << setw(20) << "       **Amount**" << setw(59) << "   **Additional Notes**" << endl;
      for (int i=0;i<collect_searchRecord.size();++i)
      {
        string hari = to_string(collect_searchRecord[i].date);
        string bulan = to_string(collect_searchRecord[i].month);
        string tahun = to_string(collect_searchRecord[i].year);
        string col2 = hari + "/" + bulan + "/" + tahun;
        string col3 = collect_searchRecord[i].category + " (" + collect_searchRecord[i].incomeOrExpense + ")";
        string col4 = collect_searchRecord[i].currency;
        double col4b = collect_searchRecord[i].amount;
        string col5 = collect_searchRecord[i].note;
        cout << setw(5) << i+1 << ". ";
        cout << setw(10) << col2 ;
        cout << setw(30) << col3;
        cout << setw(7) << col4 << " " << fixed << setprecision(2) << setw(13) << col4b << defaultfloat;
        cout << setw(60) << col5;
        cout << endl;
      }
      cout << endl;
      cout << "Do you want to search another record by date? (Y/N): ";
      char option;
      cin >> option;
      if (option == 'Y')
      {
        loop_control = 'Y';
        collect_searchRecord.clear();
      }
      else
      {
        loop_control = 'N';
        collect_searchRecord.clear();
      }
    }
  }
}
