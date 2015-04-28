/******************************************************************************
 Title: Amazon Books, Redesigned and Improved
 Name: John Bell
 Course: CSCI241
 Instructor: Jordan Ringenberg
 Due Date: Monday, February 16th, 2015

 Description: This class file implements all of the functions and constructors
 to be called by the BookStore.cpp and Book Inventory file.


******************************************************************************/

#include "Book.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//default constructor implimentation
Book::Book(){
  setBook("xxyyxx", "YY, XX", "New", 1.01);
}
//overloaded constructor implimentation
Book::Book(string n, string a, string con, double p){
  setBook(n, a, con, p);
}
//getters and setters
string Book::getName(){
  return name;
}
string Book::getAuthor(){
  return author;
}
string Book::getCond(){
  return condition;
}
double Book::getPrice(){
  return price;
}
void Book::setName(string n){
  name = n;
}
void Book::setAuthor(string a){
  author = a;
}
void Book::setCond(string con){
  condition = con;
}
void Book::setPrice(double p){
  price = p;
}
void Book::setBook(string n, string a, string con, double p){
  name      = n;
  author    = a;
  condition = con;
  price     = p;
}
//print function that allows for proper formatting/spacing
void Book::print(){
  cout << endl;
  cout << left
       << setw(45) << getName()
       << setw(25) << getAuthor()
       << setw(10) << getCond()
       << right    << showpoint  << setprecision(2) << fixed
       << setw(8)  << getPrice()
       << endl;
}
