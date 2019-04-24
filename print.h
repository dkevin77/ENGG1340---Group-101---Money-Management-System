#ifndef PRINT
#define PRINT
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "struct.h"
using namespace std;
void addCurency(vector <record> &data,string defaultCurrency)
{
  for(int i=0;i<data.size();++i)
    data.at(i).currency=defaultCurrency;
}
bool file_is_empty(string filename,string username)
{
  ifstream fin(filename.c_str());
  if(fin.fail())
  {
    fin.close();
    return true;
  }
  string input;
  fin>>input;
  if(input==(username+"'s"))
  {
    fin.close();
    return false;
  }
  else
  {
    fin.close();
    return true;
  }
}
void print(vector <record> data,string username,string defaultCurrency)
{
  addCurency(data,defaultCurrency);
  string filename;
  cout<<"Please specify the name of the output file : ";
  cin>>filename;
  cout<<endl;
  ofstream fout;
  fout.open(filename.c_str());
  fout<<setprecision(2)<<fixed;
  if(file_is_empty(filename,username))
    fout<<username<<"'s records data"<<endl<<endl;
  for(int i=0;i<data.size();++i)
  {
    record output=data.at(i);
    fout<<"Date : "<<output.date<<'/'<<output.month<<'/'<<output.year<<endl;
    fout<<"Category : "<<output.category<<" ("<<output.incomeOrExpense<<")"<<endl;
    fout<<"Amount : "<<output.currency<<' '<<output.amount<<endl;
    fout<<"Note : "<<output.note<<endl<<endl;
  }
  cout<<"All records have been succesfully appended to "<<filename<<endl<<endl;

  fout.close();
  return;
}

#endif
