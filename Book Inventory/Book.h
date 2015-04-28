/******************************************************************************
 Title:    Amazon Books, Redesigned and Improved
 Name:    John Bell
 Course:    CSCI241
 Instructor:Jordan Ringenberg
 Due Date:    Monday, February 16th, 2015

 Description: Header that declares the book class, delcares its private
 members, and declares functions to be accessed by the BookStore.cpp and
 BookInventory.cpp.


******************************************************************************/
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
using namespace std;

//define the Books class
class Book {
 private:
  string name;
  string author;
  string condition;
  double price;
 public:
  //default constructor
  Book();
  //overloaded constructor
  Book(string, string, string, double);
  void      setName    (string n);
  void      setAuthor  (string a);
  void      setCond    (string con);
  void      setPrice   (double p);
  string    getName();
  string    getAuthor();
  string    getCond();
  double    getPrice();
  void      print();
  void      setBook(string, string, string, double);
};
#endif

