// Diego Lopez
#include <iostream>
using namespace std;

int main() {
  // a. Declare and assign values to variables
  int myInt = 15;
  int *myPointer = &myInt;
  // b. Print to console
  cout << myPointer << *myPointer << "\n";
  cout << *myPointer << "\n";
  // c. Change values and print to console
  myInt = 10;
  cout << &myInt << myPointer << "\n";
  cout << myInt << " " << *myPointer << "\n";
  return 0;
}
