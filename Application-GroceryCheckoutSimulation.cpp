//==========================================================
//
// Title:      Grocery Checkout Simluation
// Author:     Dan Ouellette
// Description:
//   This C++ console application simulates a checkout lane
// at a grocery store.  It uses a queue data structure to
// represent the lane.  A menu enables the user to set the
// number of simulation cycles and the probability that a 
// customer enters, rather than exits, the queue.  The 
// application requires three files:
//   -This file
//   -Class-Customer-Header.h
//   -Class-Customer-Implementation.cpp
//
//==========================================================
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include "Class-Customer-Header.h"
using namespace std;  // So "std::cout" may be abbreviated to "cout"

//==========================================================
// Globals
//==========================================================
const int COLFMT = 22;
Customer *head = NULL;
Customer *tail = NULL;
int listSize = 0;

//==========================================================
// addNodeToBack
//==========================================================
void addNodeToBack(Customer* ptr)
{

  // Test if list empty
  if (head == NULL)
  {
    head = ptr;
    tail = ptr;
  }
  else
  {

    // Add node to back of list
    tail->setNext(ptr);
    tail = ptr;

  }

  // Print add message and update list size
  cout << "Node added to back of list: ["
    << ptr->getItems() << ", " << ptr->getItemCost() << "]"
    << endl;
  listSize = listSize + 1;

}

//==========================================================
// clearList
//==========================================================
void clearList()
{

  // Declare variables
  Customer* ptr = NULL;

  // Loop to delete nodes
  ptr = head;
  while (ptr != NULL)
  {
    head = ptr->getNext();
    delete ptr;
    ptr = head;
  }

  // Initialize list pointers
  head = NULL;
  tail = NULL;

  // Print clear message and update list size
  cout << "\nList cleared." << endl;
  listSize = 0;
  cout << "List size: " << listSize << endl;

}

//==========================================================
// deleteNodeFromFront
//==========================================================
Customer* deleteNodeFromFront()
{

  // Declare variables
  Customer* ptr = NULL;

  // Test if list empty
  if (listSize == 0)
    cout
      << "The list is empty.  "
      << "There is no node to delete." << endl;
  else if (head == tail)
  {

    // Get pointer to deleted node
    ptr = head;
    head = NULL;
    tail = NULL;

  }
  else
  {

    // Get pointer to deleted node
    ptr = head;
    head = head->getNext();

  }

  // Test if node deleted
  if (ptr != NULL)
  {

    // Print delete message and update list size
    cout << "Node deleted from front of list: ["
      << ptr->getItems() << ", " << ptr->getItemCost() << "]"
      << endl;
    listSize = listSize - 1;

  }

  return ptr;

}

//==========================================================
// menuOption
//==========================================================
int menuOption()
{

  // Declare varibles
  int option;

  // Show menu
  cout << "\nGrocery Checkout Simulation Menu" << endl;
  cout << "1 - Set simulation cycles" << endl;
  cout << "2 - Set add-remove level" << endl;
  cout << "3 - Run simulation" << endl;
  cout << "4 - Print list" << endl;
  cout << "5 - Clear list" << endl;
  cout << "0 - Exit" << endl;
  cout << "Enter an option: ";
  cin >> option;
  return option;

}

//==========================================================
// printList
//==========================================================
void printList()
{

  // Declare variables
  Customer* ptr = NULL;
  int totalItems;
  double totalItemCost;

  // Test if list is empty
  if (head == NULL)
    cout << "\nThe list is empty." << endl;
  else
  {

    // Print column headings
    cout << endl << "Current Checkout Lane" << endl;
    cout << setw(COLFMT) << left << "ID"
      << setw(COLFMT) << right << "Items"
      << setw(COLFMT) << right << "Item Cost ($)"
      << endl;

    // Loop to print node values
    ptr = head;
    totalItems = 0;
    totalItemCost = 0;
    while (ptr != NULL)
    {

      // Test if ptr at head
      if (head == tail)
        cout << setw(COLFMT) << left 
          << to_string(ptr->getID()) + " (head & tail)";
      else if (ptr == head)
        cout << setw(COLFMT) << left 
          << to_string(ptr->getID()) + " (head)";
      else if (ptr == tail)
        cout << setw(COLFMT) << left 
          << to_string(ptr->getID()) + " (tail)";
      else
        cout << setw(COLFMT) << left << ptr->getID();
      cout 
        << setw(COLFMT) << right << ptr->getItems()
        << setw(COLFMT) << right << ptr->getItemCost()
        << endl;

      // Update totals
      totalItems = totalItems + ptr->getItems();
      totalItemCost = totalItemCost + ptr->getItemCost();

      // Get next node
      ptr = ptr->getNext();

    }

    // Print totals
    cout << "List size: " << listSize << endl << endl;
    cout << setw(COLFMT) << left << "Total items: "
      << setw(COLFMT) << right << totalItems << endl;
    cout << setw(COLFMT) << left << "Total item cost ($): "
      << setw(COLFMT) << right << totalItemCost << endl;

  }

}

//==========================================================
// runSimulation
//==========================================================
void runSimulation(int cycles, int level)
{

  // Declare variables
  int addRemoveFlag;
  static int id = 1;
  int items;
  double itemCost;
  Customer* ptr;

  // Initialize random-number generator
  srand(time(NULL));

  // Loop to run simulation
  for (int i = 1; i <= cycles; i++)
  {

    // Print cycle number
    cout << "\n[" << i << "] ";

    // Add to or remove from the queue
    addRemoveFlag = rand() % 100 + 1;
    if (addRemoveFlag <= level)
    {

      // Generate random items between 1 and 200
      items = rand() % 200 + 1;

      // Generate random item cost between 100 and 1000
      itemCost = rand() % 901 + 100;

      // Create and add node to queue
      ptr = new Customer(id, items, itemCost);
      id = id + 1;
      addNodeToBack(ptr);
      cout << "Customer " << ptr->getID()
        << " entered checkout lane." << endl;

    }
    else
    {

      // Delete node from queue
      ptr = deleteNodeFromFront();
      if (ptr != NULL)
        cout << "Customer " << ptr->getID()
          << " left checkout lane." << endl;

    }

  }

}

//==========================================================
// setLevel
//==========================================================
int setLevel(int level)
{

  // Print current level
  cout << "\nCurrent add-remove level: " << level << endl;

  // Loop to prompt for and get level
  cout << "\nThe higher the level, the greater the "
    << "probability that a \ncustomer will enter, rather "
    << "than exit, the checkout queue." 
    << endl;
  cout << "\nEnter the add-remove level (1-100): ";
  cin >> level;
  while (level < 1 || level > 100)
  {
    cout << "Error: level must be between 1 and 100." 
      << endl;
    cout << "\nEnter the level (1-100): ";
    cin >> level;
  }

  // Print new level
  cout << "\New add-remove level: " << level << endl;
  return level;

}

//==========================================================
// setSimulationCycles
//==========================================================
int setSimulationCycles(int cycles)
{

  // Print current number of cycles
  cout << "\nCurrent number of simulation cycles: " 
    << cycles << endl;

  // Loop to prompt for and get number of cycles
  cout << "\nEnter the number of simulation cycles "
    << "(1-2000): ";
  cin >> cycles;
  while (cycles < 1 || cycles > 2000)
  {
    cout << "Error: number of simulation cycles must be "
      << "between 1 and 2000." << endl;
    cout << "\nEnter the number of simulation cycles "
      << "(1-2000): ";
    cin >> cycles;
  }

  // Print new number of cycles
  cout << "\New number of simulation cycles: "
    << cycles << endl;
  return cycles;

}

//==========================================================
// main
//==========================================================
int main()
{
  
  // Declare variables
  int option;
  int cycles = 10;
  int level = 50;
  int items;
  int itemCost;

  // Show application header
  cout << "Welcome to Grocery Checkout Simulation" << endl;
  cout << "--------------------------------------" << endl;

  // Loop to process menu options
  option = menuOption();
  while (option != 0)
  {

    // Test which option selected
    switch (option)
    {

      case 1:
        cycles = setSimulationCycles(cycles);
        break;

      case 2:
        level = setLevel(level);
        break;

      case 3:
        runSimulation(cycles, level);
        break;

      case 4:
        printList();
        break;

      case 5:
        clearList();
        break;

      default:
        cout << "Error: unknown option of " << option
          << "." << endl;

    }

    // Get next option
    option = menuOption();

  }

  // Show application close
  cout << "\nEnd of Grocery Checkout Simulation" << endl;

}
