#include <iostream>

using namespace std;

int main(){
    //Defining out own Data Structures
    //?Data structure is a way to grup together related data elements and a strategy for using those data.
    //* For example, the Sales_item class gruops ISBN, a count of how many copies of that book had been sold,
    //* And the revenue associated with those sales.
    //* In C++ we define our own data types by defining a class.

    //Defining the Sales_item/Sales_data(writtes as sales data to avoid repetition) class

    struct Sales_data {
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };

 
 
    
}