#include <iostream>
#include <string>
#include "struct.h"
#include <vector>

string country[10]={"HKD","USD","GBP","JPY","RMB","IDR","INR","AUD","SGD","KRW"};
double value[10]={1,0.13,0.098,14.27,0.85,1791.5,8.87,0.18,0.17,145.5};

void show_Currencies()
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

int findIndexOfDefaultCurrency(string defaultCurrency)
{
  int output;
  for(int i=0;i<10;++i)
  {
    if(country[i]==defaultCurrency)
      output=i;
    else
      continue;
  }
  return output;
}

void convert(vector <record> &data, string &defaultCurrency)
{
  int input,IndexOfDefaultCurrency;
  IndexOfDefaultCurrency=findIndexOfDefaultCurrency(defaultCurrency);
  show_Currencies();
  cin>>input;
  defaultCurrency=country[input-1];
  cout<<endl;
  for(int i=0;i<data.size();++i)
  {
    data.at(i).currency=defaultCurrency;
    data.at(i).amount=(data.at(i).amount)*value[input-1]/value[IndexOfDefaultCurrency];
  }
  cout<<"Your records have been converted into "<<country[input-1]<<endl;
}
