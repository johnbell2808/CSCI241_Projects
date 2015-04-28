/******************************************************************************
 Title: Amazon Books, Redesigned and Improved
 Name: John Bell
 Course: CSCI241
 Instructor: Jordan Ringenberg
 Due Date: Monday, February 16th, 2015

 Description: The class file that implements most of the projects functions.
 With most of the original Book class fils/header remaining the same,
 the use of dynamic arrays is being stressed throughout this
 update. A BookInventory class is created, and changes in max
 number of elements allowed in respect to the parameters
 specified (if the number of books entered equals the max,
 the array allocates more space) while the user is
 entering book information specified. The user can sort
 the list of books that is stored, do a search of the
list, and delete the cheapest book, print the list out,
and close the program and write to the output file.

Input:Data is initially read using the ReadFromFile function.
Users enter a menu choice accordingly to the menu given.
The addBook function allows for entering of books and the
corresponding information being prompted. If the book is
not successfully added, the user is notified. This function
keeps track of the number of books in the array as well
as the maximum number of elements. A search query is asked
if the user chooses, and they are also asked if they would
like to delete the cheapest book.

Output: The data read in from the file is displayed for the user to see
with all string fields converted to upper case. The user is
continuously printed a menu that allows them to utilize different
portions of the program. Input fields are specified accordingly.
Functions are primarily derived functions of the previous project,
except output is saved to a file.


******************************************************************************/

#include "Book.h"
#include "BookInventory.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;


//constructor that takes parameter for max
BookInventory::BookInventory(int m){

  numBooks  = 0;
  maxBooks  = m;
  bookArray = new Book[maxBooks];
  
}
//default constructor
BookInventory::BookInventory(){
  numBooks = 0;
  maxBooks = 20;
  bookArray = new Book[maxBooks];
}

//deconstructor
BookInventory::~BookInventory(){
  delete[]bookArray;
}

void BookInventory::addBook(){

  double fac = 1.5;
  string n;
  string a;
  string con;
  double p;
  

  //checks to see if the array needs resized
  if (numBooks >= maxBooks){
    UpdateMaxBooks(fac);
  }
  cout    << endl;
  //clears buffer from previous cin statement
  cin.ignore();
  cout  << "Please enter a the book name: " ;
  getline(cin, n);
  //converts all strings to uppercase
  StringToUpper(n);
  cout    << endl;
  cout    << "Please enter the author of the book: " ;
  getline(cin, a);
  StringToUpper(a);
  cout    << endl;
  cout    << "Please enter the condition of the book: ";
  getline(cin, con);
  StringToUpper(con);
  cout    << endl;
  cout    << "Please enter the price of the book: ";
  cin     >> p;
  //passes all input values to book object in array
  bookArray[numBooks].setBook(n, a, con, p);
  
  //if input fails, user is notified
  if(cin.fail()){
    cout << "Book Adding Failed." << endl;
  }
  else{
    cout << "Book Adding Successful!" << endl;
    numBooks++;

  }
}

void BookInventory::sortList(){

  //bubble sort function used to sort alphabetically
  for(int i = 0; i < numBooks; i++){
    for(int j = (numBooks-1); j >= i; j--){
      if(bookArray[i].getName() > bookArray[j].getName()){
	//passes to swap book function if i is > j
	swapBooks(bookArray[i], bookArray[j]);
      }
      //if book names are same, check price and sort by ascending
      if(bookArray[i].getName() == bookArray[j].getName()){
	if(bookArray[i].getPrice() > bookArray[j].getPrice()){
	  swapBooks(bookArray[i], bookArray[j]);
	}
      }
    }
  }

}



void BookInventory::searchList(){

  int  upperLim = numBooks;
  int  lowerLim = 0;
  int  index = 0;
  int  cheapind = numBooks;
  bool found = false;
  string search;
  string input;
  //clears buffer after selection input
  cin.ignore();
  //sorts list in order to binary search
  sortList();
  cout << "Enter a term to search:";
  getline(cin, search);
  
  while(!found && lowerLim <= upperLim){
    //sets index in the middle of the array
    index = (lowerLim + upperLim) / 2;
    if (bookArray[index].getName() == search){
      found = true;
      //steps back and forward from the lowerLim to index
      for (int i = lowerLim; i < index; i++){
	if (bookArray[i].getName() == search){
	  bookArray[i].print();
	  //stores cheapest index
	  if (i < cheapind){
	    cheapind = i;
	  }
	}
      }
      bookArray[index].print();
      //steps forward in a function
      for (int i = (index + 1); i <= upperLim; i++){
	if (bookArray[i].getName() == search){
	  bookArray[i].print();

	}
      }
    }
    //Upper Limit is moved below index value if it is not in the top half
    else if (bookArray[index].getName() > search){
      upperLim = index - 1;
    }
    //Lower Limit is moved up one if index value is not in the bottom half
    else if (bookArray[index].getName() < search){
      lowerLim = index + 1;
    }
  }
  if(!found){
    cout << search << " not found." << endl;
  }
  //if results yield result, remove book option is given
  else{
    cout << "Delete the cheapest book in search results? " ;
    cin  >> input;
    if (input == "Y" || input == "y"){
      removeBook(cheapind);
    }
  }

}

void BookInventory::printList(){
  
  cin.ignore();
  cout    << left
	  << setw(45) << "Name"
	  << setw(25) << "Author"
	  << setw(10) << "Condition"
	  << right
	  << setw(8)  << "Price"
	  << endl;
  cout    << setfill('_') << setw(87) << " " << setfill(' ')
	  << endl;
  //loops through booklist and calls on print function
  for(int i = 0; i < numBooks; i++){
    bookArray[i].print();
  }
}

void BookInventory::swapBooks(Book &B, Book &C){
  //declares temporary position to hold position of pending book to be swapped
  Book temp;
  
  temp = B;
  B    = C;
  C    = temp;
}

void BookInventory::UpdateMaxBooks(double factor){
  
  //resizes maxBooks
  maxBooks =  (factor * maxBooks);
  
  //creates pointer to store dynamic array
  Book* copyArray = new Book[maxBooks];
  
  //copies over elements to pointer
  for(int i = 0; i < numBooks; i++){
    copyArray[i] = bookArray[i];
  }
  //frees up original array
  delete[] bookArray;
  //array points to new array
  bookArray = copyArray;
  

}
void BookInventory::WriteToFile(string fileName){
  //opens output file
  ofstream outFile;
  outFile.open(fileName.c_str());
  
  if (!outFile){
    cout << "\nCould not open " << outFile << endl;
  }
  //loops through array, and writes to file
  for(int i = 0; i < numBooks; i++){
    outFile << bookArray[i].getName()      << endl;
    outFile << bookArray[i].getAuthor()    << endl;
    outFile << bookArray[i].getCond()      << endl;
    outFile << bookArray[i].getPrice()     << endl;
  }
  
  outFile.close();
  
}
void BookInventory::ReadFromFile(string fileName){
  ifstream inFile;
  inFile.open(fileName.c_str());
  string line; 
  double numb = 0;
  
  
  double fac = 1.5;

  if (!inFile){
    cout << "\nNEW DATA FILE " ;
    cout << "\nPress ENTER to continue." ; 

  }
  else{
    cout << "\nPlease press enter to continue. " ;
  }
  //loops through array, and pulls stores in array
  while(getline(inFile, line)){
    StringToUpper(line);
    bookArray[numBooks].setName(line);
    getline(inFile, line);
    StringToUpper(line);
    bookArray[numBooks].setAuthor(line);
    getline(inFile, line);
    StringToUpper(line);
    bookArray[numBooks].setCond(line);
    inFile >> numb;
    bookArray[numBooks].setPrice(numb);
    numBooks++;
    inFile.ignore();
    //checks to see if array needs resizing
    if(numBooks >= maxBooks){
      UpdateMaxBooks(fac);
    }
    
  }
  
  inFile.close();
  
}

void BookInventory::removeBook(int index){
  double fac = .75;
  
  //replaces cheapest index with the one above
  //while bumping everything down
  for(int i = index; i < numBooks - 1; i++){
    bookArray[i] = bookArray[i + 1];
  }
  numBooks --; 
  //number of maximum books is shrinked by 75%
  if (numBooks <= (.5 * maxBooks)){
    UpdateMaxBooks(fac);
  }
}

void BookInventory::StringToUpper(string &str){
  for (int i = 0; i < str.length(); i++){
    str[i]=toupper(str[i]);
  }
}
