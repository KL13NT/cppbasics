#include <iostream>
#define GLOBAL_TEST_CONSTANT 100

using namespace std;

int main(){
  int random = 5;
  cout << "Hello, world!\n";
  //To add a line ending, use << endl or add "\n" to the end of your string
  cout << "The global test count constant is: " << GLOBAL_TEST_CONSTANT << endl;
  cout << random++ << endl;
  cout << --random << endl;
  cout << "You can combine variables and static strings too!" << random << " " << GLOBAL_TEST_CONSTANT << endl;
}