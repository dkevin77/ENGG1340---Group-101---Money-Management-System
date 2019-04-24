#include <iostream>
#include <vector>
#include "add\add.h"
#include "print.h"
#include "sort.h"
#include "statistic.h"
#include "display_options.h"
#include "settings\settings.h"
#include "edit.h"
using namespace std;

int main()
{
  vector <record> data;
  string username="",prefix="",defaultCurrency;
  int defaultCurrencyIndex;

  //Starting point for user
  cout<<"WELCOME TO WEALTH MANAGEMENT SYSTEM 101 !"<<endl;
  if(username=="")
  {
    cout<<"Before we start, let us know more a little bit about you"<<endl;
    cout<<"1.Mr"<<endl<<"2.Mrs"<<endl<<"Please choose (1/2) : ";
    cin>>prefix;
    if(prefix=="1")
      prefix="Mr.";
    else
      prefix="Mrs.";
    cout<<"Please enter 6-12 characters as your username : ";
    cin.ignore();
    getline(cin,username);
    cout<<endl<<"Welcome "<<prefix<<username<<"!"<<endl<<endl;
  }
  showCurrencies();
  cin>>defaultCurrencyIndex;
  cout<<endl;
  defaultCurrency=country[defaultCurrencyIndex-1];
  int input=1;
  //Functionality
  while(input)
  {
    display_option();
    cin>>input;
    cout<<endl;
    switch (input)
    {
      case 0 :
        break;
      case 1:
        add(data);
        break;
      case 2:
        print(data,username,defaultCurrency);
        break;
      case 3:
        sort(data);
        break;
      case 4:
        statistic(data,username);
        break;
      case 5:
        setting(data,defaultCurrency,username);
        break;
    }
  }






}
