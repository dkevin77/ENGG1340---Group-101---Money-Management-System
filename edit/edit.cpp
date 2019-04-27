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

int moveData(vector <record> &data, int dateYear, int dateMonth, int dateDay)
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
          info_data.currency = data[i].currency;
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
  int datanumberminusone = dataNumber-1;
  cout << endl;
  cout << "***Old data*** " << endl;
  cout << "Date: " << collectRecord[datanumberminusone].date << '/' << collectRecord[datanumberminusone].month << '/' << collectRecord[datanumberminusone].year << endl;
  cout << "Category: " << collectRecord[datanumberminusone].category << " (" << collectRecord[datanumberminusone].incomeOrExpense << ")" << endl;
  cout << "Amount: " << collectRecord[datanumberminusone].currency << " " << fixed << setprecision(2) << collectRecord[datanumberminusone].amount << defaultfloat << endl;
  cout << "Additional Notes: " << collectRecord[datanumberminusone].note << endl << endl;
  cout << "***New data (edited)*** " << endl;
  cout << "Date: " << data[currentIndex].date << '/' << data[currentIndex].month << '/' << data[currentIndex].year << endl;
  cout << "Category: " << data[currentIndex].category << " (" << data[currentIndex].incomeOrExpense << ")" << endl;
  cout << "Amount: " << data[currentIndex].currency << " " << fixed << setprecision(2) << data[currentIndex].amount << defaultfloat << endl;
  cout << "Additional Notes: " << data[currentIndex].note << endl;
}

void edit(vector <record> &data)
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
    int data_Counter = moveData(data, dateYear, dateMonth, dateDay);

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
      cout << "We found " << collectRecord.size() << " record(s) in " << dateSearch << ". The detail is as follows:" << endl;
      cout << endl;
      cout << setw(5) << "Data" << setw(10) << "    **Date**" << setw(30) << "    **Type(I/E)**" << setw(20) << "       **Amount**" << setw(59) << "   **Additional Notes**" << endl;
      for (int i=0;i<collectRecord.size();++i)
      {
        string hari = to_string(collectRecord[i].date);
        string bulan = to_string(collectRecord[i].month);
        string tahun = to_string(collectRecord[i].year);
        string col2 = hari + "/" + bulan + "/" + tahun;
        string col3 = collectRecord[i].category + " (" + collectRecord[i].incomeOrExpense + ")";
        string col4 = collectRecord[i].currency;
        double col4b = collectRecord[i].amount;
        string col5 = collectRecord[i].note;
        cout << setw(5) << i+1 << ". ";
        cout << setw(10) << col2 ;
        cout << setw(30) << col3;
        cout << setw(7) << col4 << " " << fixed << setprecision(2) << setw(13) << col4b << defaultfloat;
        cout << setw(60) << col5;
        cout << endl;
      }
      int dataNumber;
      cout << endl;
      cout << "Please input the data number you wish to edit (Input \'0\' if you wish to go back): ";
      cin >> dataNumber;
      if (dataNumber == 0)
      {
        cout << endl;
        collectRecord.clear();
        break;
      }
      else
      {
        editProcess(dataNumber, data);
      }
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
