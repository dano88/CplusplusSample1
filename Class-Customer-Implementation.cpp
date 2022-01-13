//==========================================================
//
// Title: Class-Customer-Implementation
// Description:
//   This C++ implementation implements the functions for the
// prototypes defined in file Class-Customer-Header.h.
//
//==========================================================
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include "Class-Customer-Header.h"
using namespace std;

//----------------------------------------------------------
// Function implementations
//----------------------------------------------------------

//----------------------------------------------------------
// Constructors and destructor
//----------------------------------------------------------

// Zero-parameter constructor
Customer::Customer()
{
  id = -20;
  items = -20;
  itemCost = -20;
}

// Three-parameter constructor
Customer::Customer(int id, int items, double itemCost)
{
  this->id = id;
  this->items = items;
  this->itemCost = itemCost;
}

//--------------------------------------------------------
// Getters
//--------------------------------------------------------

// getID
int Customer::getID() const
{
  return id;
}

// getItems
int Customer::getItems() const
{
  return items;
}

// getItemCost
double Customer::getItemCost() const
{
  return itemCost;
}

// getNext
Customer* Customer::getNext() const
{
  return next;
}

//--------------------------------------------------------
// Setters
//--------------------------------------------------------

// setID
void Customer::setID(int id)
{
  this->id = id;
}

// setItems
void Customer::setItems(int items)
{
  if (items < 1 || items > 200)
    cout << "Error: items must be between 1 and 200." 
      << endl;
  else
    this->items = items;
}

// setItemCost
void Customer::setItemCost(double itemCost)
{
  if (itemCost < 100 || itemCost > 1000)
    cout << "Error: itemCost must be between 100 and 1000." 
      << endl;
  else
    this->itemCost = itemCost;
}

// setNext
void Customer::setNext(Customer *next)
{
  this->next = next;
}
