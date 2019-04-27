#include <iostream>
#include <vector>
#include "struct.h"
#include "add\add.h"
#include "settings\settings.h"
#include "statistics\statistic.h"
#include "print.h"
#include "sort.h"
#include "display_options.h"
#include "edit\edit.h"
#include "remove\remove.h"
#include "search\search.h"
using namespace std;

string countries[10]={"HKD","USD","GBP","JPY","RMB","IDR","INR","AUD","SGD","KRW"};
void showCurrencies()
{
  cout<<"Please select one of the options below (1-10) : "<<endl;
  cout<<"1. Hong Kong Dollar"<<endl;
  cout<<"2. United States Dollar"<<endl;
  cout<<"3. Great Britain Poundsterling"<<endl;
  cout<<"4. Japanese Yuan"<<endl;
  cout<<"5. Chinese Yuan Renminbi"<<endl;
  cout<<"6. Indonesian Rupiah"<<endl;
  cout<<"7. Indian Rupee"<<endl;
  cout<<"8. Australian Dollar"<<endl;
  cout<<"9. Singapore Dollar"<<endl;
  cout<<"10. South Korean Won"<<endl;
  cout<<"Your choice : ";
  return;
}
int main()
{
  vector <record> data;
  string username="",prefix="",defaultCurrency;
  int defaultCurrencyIndex;

  cout<<"WELCOME TO WEALTH MANAGEMENT SYSTEM 101 !"<<endl;

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

  showCurrencies();
  cin>>defaultCurrencyIndex;
  cout<<endl;
  defaultCurrency=countries[defaultCurrencyIndex-1];
  int input=1;

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
        add(data,defaultCurrency);
        break;
      case 2:
        print(data,username);
        break;
      case 3:
        sort(data);
        break;
      case 4:
        search(data);
        break;
      case 5:
        edit(data);
        break;
      case 6:
        remove(data);
        break;
      case 7:
        statistic(data,username);
        break;
      case 8:
        setting(data,defaultCurrency,username);
        break;
    }
  }
}
