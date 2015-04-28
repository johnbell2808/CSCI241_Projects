/******************************************************************************
 Title: Amazon Books, Redesigned and Improved
 Name: John Bell
 Course: CSCI241
 Instructor: Jordan Ringenberg
 Due Date: Monday, February 16th, 2015

 Description: The main file that executes and accesses the functions from
 BookInventory.cpp. This project is an improvement of a previous project
 with the use of dynamic arrays. 
 The main function takes creates a BookInventoryobject, 
 reads in the data file, prints the data file, takes menu input from use,
 repeats until user desires to close program, and then writes BookInventory
 to OilerBookList.dat file. Credit goes to Dr. Ringenberg for writing the
 majority of the BookStore.cpp with minimal changes within the main file.

 Input: User enters menu selection, and from there, based on their selection
        they are asked for the information fields to either input info for
a book, or a search which allows them the option to delete the
cheapest book in the array.


 Output: The data read in from the file is displayed for the user to see
         with all string fields converted to upper case. The user is
 continuously printed a menu that allows them to utilize different
 portions of the program. Input fields are specified accordingly.


******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"
#include "BookInventory.h"
using namespace std;

void printMenu();

int main(){
  
  //creates BookInventory object with initial maxBooks size of 10
  BookInventory Inv(10);
  int selection = -1;
  
  //reads in list from file and prints 
  Inv.ReadFromFile("OilerBookList.dat");
  Inv.printList();
  
  while(selection != 0){
    
    printMenu();
    cin >> selection;
    
    //if user input is invalid, asks user to re-enter valid input
    while(cin.fail() || selection > 4 || selection < 0){
      printMenu();
      cin.clear();
      cin.ignore(256, '\n');
      cin >> selection;
    }
    if(selection == 1){
      Inv.addBook();
    }
    if(selection == 2){
      Inv.sortList();
      Inv.printList();
    }
    if(selection == 3){
      Inv.searchList();
    }
    if(selection == 4){
      Inv.printList();
    }
  }
  
  //writes to same file that is read in
  Inv.WriteToFile("OilerBookList.dat");

  cout << "Application Closing..." << endl;
  
  return 0;
}

//function that prints menu 
void printMenu(){
  cout << "\n--- Menu ---";
  cout << "\nPlease choose an option:";
  cout << "\n1. Enter Book";
  cout << "\n2. Sort Books by Name";
  cout << "\n3. Search for Book";
  cout << "\n4. List Books";
  cout << "\n0. Exit Bookstore\n";
}
