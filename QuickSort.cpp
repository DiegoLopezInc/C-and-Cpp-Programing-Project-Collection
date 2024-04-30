//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//

// Group: Diego Lopez, Denny Zhang, Santiago Orozco Buri

/**
 * @file QuickSort_Skeleton.cpp
 * Edited by Diego Lopez
 * This program Sorts a Patient List using Quick Sort
 * Source: https://www.geeksforgeeks.org/bubble-sort/
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

//  Declaring a new struct to store patient data
struct patient {
  int age;
  char name[20];
  float balance;
};

//  TODO:
//  IMPLEMENT A DISPLAY FUNCTION PRINTS THE CONTENTS OF THE PATIENT STRUCT ARRAY
//  PASSED TO IT
/**
 * A Utility function to displays the contents of the array
 */
void displayPatientList(struct patient arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << "Age: " << arr[i].age << " "
         << "Name: " << arr[i].name << " "
         << "Balance: " << arr[i].balance << endl;
  }
}

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
/**
 * A Utility function to compare the age of two patients using void pointers
 */
int comparePatientsByAge(const void *p1, const void *p2) {
  if (*(int *)p1 < *(int *)p2) {
    return -1;
  } else if (*(int *)p1 == *(int *)p2) {
    return 0;
  } else {
    return 1;
  }
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE
//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE
/**
 * A Utility function to compare the balance of two patients using void pointers
 */
int comparePatientsByBalance(const void *p1, const void *p2) {
  // Reference the balance of both patient structs and store to buffer variables
  float balance1 = (*(const patient *)p1).balance;
  float balance2 = (*(const patient *)p2).balance;
  if (balance1 < balance2) {
    return -1;
  } else if (balance1 == balance2) {
    return 0;
  } else {
    return 1;
  }
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)
/**
 * A Utility function to compare the balance of two patients using patient
 * pointers
 */
int comparePatientsByName(const patient *p1, const patient *p2) {
  // Reference the balance of both patient structs and store to buffer variables
  const char *name1 = p1->name;
  const char *name2 = p2->name;
  if (strncmp(name1, name2, 20) < 0) {
    return -1;
  } else if (strncmp(name1, name2, 20) == 0) {
    return 0;
  } else {
    return 1;
  }
}

//  The main program
int main() {
  int total_patients = 6;

  //  Storing some test data
  struct patient patient_list[6] = {
      {25, "Juan Valdez   ", 1250}, {15, "James Morris  ", 2100},
      {32, "Tyra Banks    ", 750},  {62, "Mario O'Donell", 375},
      {53, "Pablo Picasso ", 615},  {}};

  // Ask User to enter data
  cout
      << "Enter your last name (no spaces ; please use underscores if needed): "
      << endl;
  cin >> patient_list[5].name;
  cout << "Enter your age: " << endl;
  cin >> patient_list[5].age;
  cout << "Enter a balance of your choice: " << endl;
  cin >> patient_list[5].balance;

  cout << "Patient List: " << endl;

  //  TODO:
  //  IMPLEMENT THE CODE TO DISPLAY THE CONTENTS
  //  OF THE ARRAY BEFORE SORTING
  displayPatientList(patient_list, total_patients);

  cout << endl;

  cout << "Sorting..." << endl;

  //  TODO:
  //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
  qsort(patient_list, total_patients, sizeof(patient_list[0]),
        comparePatientsByAge);

  cout << "Patient List - Sorted by Age: " << endl;

  //  TODO:
  //  DISPLAY THE CONTENTS OF THE ARRAY
  //  AFTER SORTING BY AGE
  displayPatientList(patient_list, total_patients);

  cout << endl;

  cout << "Sorting..." << endl;

  //  TODO:
  //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
  qsort(patient_list, total_patients, sizeof(patient_list[0]),
        comparePatientsByBalance);

  cout << "Patient List - Sorted by Balance Due: " << endl;

  //  TODO:
  //  DISPLAY THE CONTENTS OF THE ARRAY
  //  AFTER SORTING BY BALANCE
  displayPatientList(patient_list, total_patients);

  cout << endl;

  cout << "Sorting..." << endl;

  //  TODO:
  //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME

  cout << "Patient List - Sorted by Name: " << endl;

  //  TODO:
  //  DISPLAY THE CONTENTS OF THE ARRAY
  //  AFTER SORTING BY NAME
  displayPatientList(patient_list, total_patients);

  cout << endl;

  return 0;
}
