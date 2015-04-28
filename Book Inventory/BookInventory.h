 /****************************************************************************
Title:    Amazon Books, Redesigned and Improved
  Name:    John Bell
  Course:    CSCI241
  Instructor:Jordan Ringenberg
  Due Date:    Monday, February 16th, 2015
  
  Description: Header that declares the BookInventory, delcares its private
  members, and declares functions to be accessed by the BookInventory.cpp.
  
  
  ****************************************************************************/
#include <iostream>
#include <string>
  
  using namespace std;

class BookInventory{
 private: 
  int     numBooks;
  int     maxBooks;
  Book   *bookArray;
  void    swapBooks(Book&, Book&);
  void    UpdateMaxBooks(double);
  void    StringToUpper(string&); 
 public:
  BookInventory();
  BookInventory(int);
  ~BookInventory();
  void    addBook();
  void    sortList();
  void    searchList();
  void    printList();
  void    ReadFromFile(string);
  void    WriteToFile(string);
  void    removeBook(int);
};
