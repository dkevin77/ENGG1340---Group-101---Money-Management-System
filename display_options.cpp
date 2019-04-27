#include <iostream>
#include "display_options.h"
using namespace std;
void display_option()
{
  cout<<"Please select one of the options below (1-8) : "<<endl;
  cout<<"1. Add Record"<<endl;
  cout<<"2. Print all Records"<<endl;
  cout<<"3. Sort records chronogically"<<endl;
  cout<<"4. Search record"<<endl;
  cout<<"5. Edit existing record"<<endl;
  cout<<"6. Remove existing record"<<endl;
  cout<<"7. Show Statistics"<<endl;
  cout<<"8. Settings"<<endl;
  cout<<"0. Exit"<<endl;
  cout<<"Your input : ";
  return;
}
