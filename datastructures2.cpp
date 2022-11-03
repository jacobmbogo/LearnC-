#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;
int main(){
    Sales_data data1, data2;

    double price = 0;

    //reading the first transaction
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    
    //reading the second transaction
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    //printing the sum of two sales_data objects
    if(data1.bookNo == data2.bookNo){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        //print: ISBN, total sold, total revenue, average price per book
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if(totalCnt != 0)
            cout << totalRevenue/totalCnt << endl;
        else 
            cout << "(no sales)" << endl;
        return 0;
    } else {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }

}