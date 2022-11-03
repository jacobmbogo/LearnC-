#include <iostream>

using namespace std;
int main(){
    const int i = 42;
    auto j = i; //j is int;
    const auto &k = i; //k is constant int &
    cout << k << endl;
    auto *p = &i; //p is int *
    cout << *p << endl;
    const auto j2 = i, &k2 = i;

    //decltype - handls top-level const and references differently from the way auto does
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; // x has type const int;
    decltype(cj) y = x; // y has type const int& is bound to x
    // decltype(cj) z; error: z is a reference and must be initialized

    //It is worth noting that decltype is the only context in which a variable defined asa reference is not treated as a synonym for the object to which it refers.


    return 0;

}