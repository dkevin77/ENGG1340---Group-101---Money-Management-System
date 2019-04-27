#include <iostream>
using namespace std;

void changeUsername(string &username)
{
  cout<<"Old username : "<<username<<endl;
  cout<<"Please enter new username : ";
  cin.ignore();
  getline(cin,username);
  cout<<endl<<"Username has been updated!"<<endl;
  cout<<"New username : "<<username<<endl<<endl;
  return;
}
