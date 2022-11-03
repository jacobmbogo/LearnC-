#include <iostream>
using namespace std;
int main(){

    /* It is worth noting that decltype is the only context in which a variable defined
        * as a variable is not treated as a synonym for the object to which it refers.
    */

   //decltype and References
   //decltype of an expression can be a reference type
    int i = 42, *p = &i, &r = i;
    //decltype(r + 0) b;  ok: addition yields an int; b is an (uninitialized) int
    // decltype(*p) c; error: c is int& and must be initialized


    cout << r << *p << endl;
    // they type deduced by decltype(*p) is int&, not plain int
    // decltype of a parenthesized variable is always a reference
    
    // decltype((i)) d;
    decltype (i) e; // ok: e is an (uninitialized) int but can be a reference only if variable is a reference

    //?Exercise 2.36

    int a = 3, b = 4; //a is int, b is int
    decltype(a) c = a; // c is int
    decltype (a = b) d = a; // d is int&

    int numbers(3);
    cout << numbers << endl;



        return 0;
}