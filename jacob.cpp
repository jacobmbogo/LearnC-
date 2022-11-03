#include <iostream>
using namespace std;

int main()
{
  // typedef double wages;
  // typedef wages base, *p;
  // base grade = 3.14;
  // p love = &grade;

  // cout << grade << *love << endl;

  typedef char *pstring;
  const pstring cstr = 0;
  const pstring *ps;

  int val1, val2;
  val1 = 3;
  val2 = 4;

  auto item = val1 + val2;
  cout << item << endl;

  // auto sz = 0, pi = 3.14; error: inconsistent types for sz and pi;

  int i = 0, &r = i;
  auto a = r;
  const int ci = i, &cr = ci;
  auto b = ci;
  auto c = cr;
  auto d = &i;
  auto e = &ci;
  const auto f = ci;
  auto &g = ci;
  const auto &j = 42;
  auto k = ci, &l = i;
  auto &m = ci, *p = &ci;

  // a = 42; //ok
  // b = 42; //ok
  // c = 42; //ok
  // //d = 42; //error a value of type int cannot be assigned to int *
  // //e = 42; //a value of type int cannot be assigned to const int*
  // // g = 42; g must be a modifiable value

  cout << "a: before = " << a;
  a = 42; // OK
  cout << "\tafter = " << a << endl;
  cout << "b: before = " << b;
  b = 42; // OK
  cout << "\tafter = " << b << endl;
  cout << "c: before = " << c;
  c = 42; // OK
  cout << "\tafter = " << c << endl;
  cout << "d: before = " << d;
  // d = 42;  // Error
  cout << "\tafter = " << d << endl;
  cout << "e: before = " << e;
  // e = 42;  // Error
  cout << "\tafter = " << e << endl;
  cout << "f: before = " << f;
  // f = 42;  // Error
  cout << "\tafter = " << f << endl;
  cout << "g: before = " << g;
  // g = 42;  // Error
  cout << "\tafter = " << g << endl;

  return 0;
}