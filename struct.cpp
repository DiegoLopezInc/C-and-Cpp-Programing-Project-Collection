// Diego Lopez
#include <cmath>
#include <iostream>
using namespace std;

// Initalize the struct
struct CartesianCoordinate {
  float x;
  float y;
};

float calculateDistance(CartesianCoordinate *x, CartesianCoordinate *y) {
  // Dereference the stuct pointers and use the square root and power methods in
  // the formula to calculate the distance
  float distance = sqrt(pow(x->x - y->x, 2) + pow(x->y - y->y, 2));
  return distance;
}

int main(void) {
  // Initialize two CartesianCoordinate objects p1 and p2
  CartesianCoordinate p1, p2;

  // Asks the user to enter the coordinates of the first point
  cout << "Enter the x and y coordinates for p1: ";
  cin >> p1.x >> p1.y;

  // // Asks the user to enter the coordinates of the second point
  cout << "Enter the x and y coordinates for p2: ";
  cin >> p2.x >> p2.y;

  // Function call
  float distance = calculateDistance(&p1, &p2);

  // Display result
  cout << "The distance between the two points is: " << distance << endl;

  return 0;
}
