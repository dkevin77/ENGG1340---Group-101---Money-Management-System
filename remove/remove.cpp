#include <iostream>
#include "struct.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct deleteRecord
{
  int date,month,year,index;
  double amount;
  string category,currency,incomeOrExpense,note;
};

vector <deleteRecord> removeRecord;

int removeData(vector <record> &data, int dateYear, int dateMonth, int dateDay)
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
          info_data.currency = data[i].currency;
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

void remove(vector <record> &data)
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
    int data_Counter = removeData(data, dateYear, dateMonth, dateDay);

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
      cout << "We found " << removeRecord.size() << " record(s) in " << dateSearch << ". The detail is as follows:" << endl;
      cout << endl;
      cout << setw(5) << "Data" << setw(10) << "    **Date**" << setw(30) << "    **Type(I/E)**" << setw(20) << "       **Amount**" << setw(59) << "   **Additional Notes**" << endl;
      for (int i=0;i<removeRecord.size();++i)
      {
        string hari = to_string(removeRecord[i].date);
        string bulan = to_string(removeRecord[i].month);
        string tahun = to_string(removeRecord[i].year);
        string col2 = hari + "/" + bulan + "/" + tahun;
        string col3 = removeRecord[i].category + " (" + removeRecord[i].incomeOrExpense + ")";
        string col4 = removeRecord[i].currency;
        double col4b = removeRecord[i].amount;
        string col5 = removeRecord[i].note;
        cout << setw(5) << i+1 << ". ";
        cout << setw(10) << col2 ;
        cout << setw(30) << col3;
        cout << setw(7) << col4 << " " << fixed << setprecision(2) << setw(13) << col4b << defaultfloat;
        cout << setw(60) << col5;
        cout << endl;
      }
      int dataNumber;
      cout << endl;
      cout << "Please input the data number you wish to remove (Input \'0\' if you wish to go back): ";
      cin >> dataNumber;
      if (dataNumber == 0)
      {
        cout << endl;
        removeRecord.clear();
        break;
      }
      else
      {
        removalProcess(dataNumber, data);
      }
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
