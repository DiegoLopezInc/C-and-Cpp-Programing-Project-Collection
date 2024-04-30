// Diego Lopez
#include <iostream>
using namespace std;

/*
 * This function swaps two integers given access
 * to via pointer parameters.
 *
 * @param pointers of two integers
 */
void swapInts(int *a, int *b) {
  int buffer = *a; // Buffer variable to hold a
  *a = *b;         // Assign value of b to a
  *b = buffer;     // Assign value of buffer to b
}

/*
Driver Code for the Assignment
*/
int main() {

  // Variabes to hold int values
  int num1, num2;

  // Output & Input for num1
  cout << "Enter a value for num1: ";
  cin >> num1;
  cout << endl;

  // Output & Input for num2
  cout << "Enter a value for num2: ";
  cin >> num2;
  cout << endl;

  // Output for num1 and num2 before swap
  cout << "Before swap: " << num1 << num2 << endl;
  swapInts(&num1, &num2);

  // Output for num1 and num2 after swap
  cout << "After swap: " << num1 << num2 << endl;

  return 0;
}
