#include <iostream>
#include <string>

using namespace std;

int main(){
  char arrayOfCharacters[256];
  cin >> arrayOfCharacters;
  cin.ignore(1000, '\n');
  cout << arrayOfCharacters << endl; //prints "Hello,", leaving the rest in the buffer
  cin.getline(arrayOfCharacters, 256); //automatically takes what's left in the buffer and doesn't allow the user to input something new for getline
  cout << arrayOfCharacters << endl; //prints " World", the leftovers

  //Now the same thing using strings!
  string myFullName;
  getline(cin, myFullName);
  cout << myFullName;
}