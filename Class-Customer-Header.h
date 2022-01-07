//==========================================================
//
// Title: Class-Customer-Header
// Description:
//   This C++ header defines the function prototypes for 
// the functions implemented in file 
// Class-Customer-Implementation.cpp.
//
//==========================================================
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
using namespace std;  // So "std::cout" may be abbreviated to "cout", for example.

//----------------------------------------------------------
// Customer class
//----------------------------------------------------------
class Customer
{

  //--------------------------------------------------------
  // Private members
  //--------------------------------------------------------
  private:

    //------------------------------------------------------
    // Fields
    //------------------------------------------------------
    int id = -10;  // In-line initialization
    int items = -10;  // In-line initialization
    double itemCost = -10;  // In-line initialization
    Customer *next = NULL;  // In-line initialization

  //--------------------------------------------------------
  // Public members
  //--------------------------------------------------------
  public:

    //------------------------------------------------------
    // Constructor and destructor prototypes
    //------------------------------------------------------

    Customer();
    Customer(int id, int items, double itemCost);

    //------------------------------------------------------
    // Getter prototypes
    //------------------------------------------------------
    int getID() const;
    int getItems() const;
    double getItemCost() const;
    Customer *getNext() const;

    //------------------------------------------------------
    // Setter prototypes
    //------------------------------------------------------
    void setID(int id);
    void setItems(int items);
    void setItemCost(double itemCost);
    void setNext(Customer *next);

};
