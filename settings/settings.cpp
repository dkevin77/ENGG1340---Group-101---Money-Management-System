#include <iostream>
#include <vector>
#include "currency_converter.h"
#include "change_username.h"
#include "struct.h"

void display_settings()
{
  cout<<"Please choose one of the options below (1-) : "<<endl;
  cout<<"1. Change Currency"<<endl;
  cout<<"2. Change username"<<endl;
  cout<<"0. Exit"<<endl;
  cout<<"Your input : ";
  return;
}

void setting(vector <record> &data,string &defaultCurrency,string &username)
{
  int input=1;
  while(input)
  {
    display_settings();
    cin>>input;
    cout<<endl;
    switch(input)
    {
      case 0:
        break;
      case 1:
        convert(data,defaultCurrency);
        break;
      case 2:
        changeUsername(username);
        break;
    }
  }
}
