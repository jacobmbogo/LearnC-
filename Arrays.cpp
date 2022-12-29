#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cstring>

//*Array is a data structure that is similar to the library <vector> but offers a different trade-off between performance
//*And flexibility.

//^Unlike a vector, arrays have fixed size in C++ (different from javascript); We cannot add elements to an array.
//*They sometimes offer better run-time perormance for specialized applications. However, that run-time advantage comes at the cost of lost flexibility.

//* An array declarator has the form a[d];
//* The number of elements in an array is part of the array's type. As a result, the dimenstion must be known at compile time
//* which means that the dimenstion must be a constant expression.
//* There is no array of references.

auto get_size()
{
    return 0;
};
void arrayIntro()
{
    unsigned cnt = 42;          // not a constant expression
    constexpr unsigned sz = 42; // constant expression

    int arr[10];                  // array of ten ints
    int *parr[sz];                // array of 42 pointers
    std::string bad[cnt];         // error cnt is not a constant expression
    std::string strs[get_size()]; // ok if get_size is constexpr, error otherwise
};

//& NB: When we define array, we must specify a type for the array. We cannot use auto to deduce the type from a list of
//& initializers.

//? auto babies[7]; error(the dimension of an array must be known at compile time)

//* Explicitly initializing array elements
void initialization()
{
    const unsigned sz = 3;
    int ial[sz] = {0, 1, 2};           // An array of three ints with values 0,1 2,
    int a2[] = {0, 1, 2};              // An array of dimension 3;
    int a3[5] = {0, 1, 2};             // equivalent to a3[] = {0,1,2,0,0};
    std::string a4[3] = {"hi", "bye"}; // same as a4[] = { "hi", "bye", ""}
    //* int a5[2] = {0,1,2}; //error: too many initializers.

    //* Character arrays are special
    char a1[] = {'C', '+', '+'};       // list initialization, no null
    char a6[] = {'C', '+', '+', '\0'}; // list initialization, explicit null
    char a7[] = "C++";                 // null terminator added automatically
    //* const char a4[6]  = "Daniel"; //error: no space for then null!

    //& No copy or assignment
    //* We cannot initialize an array as a copy of another array, nor is it legal to assign one array to assign one array to another;

    int a[] = {0, 1, 2, 3};
    //* int a2[] = a; //*Error cannot initialize one array with another
    //* a2 = a; //* error: cannot assign one array to

    //& Complicated array declarations
    int *ptrs[10]; // ptrs is an array of ten pointers to int
    //* int &refs[10];  /* ? */ // error: no arrays of references
    // int (*Parray) [10] = &arr; //* Parray points to an array of ten ints
    // int (&arrRef) [10] = arr; //* arrRef refers to an array of ten ints
};

void arrayAccess()
{
    unsigned scores[11] = {};
    unsigned grade;

    while (std::cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade / 10];
    }

    for (auto i : scores)
        std::cout << i << " ";

    std::cout << std::endl;
}

void test()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 1; ix <= array_size; ++ix)
        ia[ix] = ix;
};

void newArray()
{
    int ten[10];
    for (size_t ix = 0; ix <= 10; ++ix)
    {
        ten[ix] = ix + 1;
    }

    int anotherArray[10];
    for (size_t j = 0; j <= 10; ++j)
    {
        anotherArray[j] = ten[j];
    }

    for (auto i : anotherArray)
        std::cout << i << " ";

    std::cout << std::endl;
};

void vectors()
{
    std::vector<int> ten;
    for (decltype(ten.size()) i = 0; i < 10; ++i)
        ten.push_back(i + 1);

    std::vector<int> ten2(ten);

    for (auto &c : ten2)
        std::cout << c << " ";

    std::cout << std::endl;
}

void pointerArrays()
{
    std::string nums[] = {"one", "two", "three"};
    std::string *p = &nums[0]; // p points to the first element in nums

    std::string *p2 = nums; // equivalent to p2 = &nums[0]
    std::cout << *p << std::endl;

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ia2(ia); // ia2 is an int* that points to the first element in ia
    //* ia2 = 42; ia2 is a pointer, and we can't assign an int to a pointer

    //& it is worth noting that this conversion does not happen when we use decltype
    decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 9;
    ia3[4] = i; // okay assign the value of i to an element in ia3

    //^ Pointers are Iterators
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p3 = arr; // p points to the first element in arr
    ++p3;          // p points to arr[1];

    int *e = &arr[10];
    for (int *b = arr; b != e; ++b)
        std::cout << *b << " "; // print the elements in arr;

    std::cout << std::endl;

    //* the library begin and end functions

    int *beg = std::begin(ia); // pointer to the first element in ia
    int *last = std::end(ia);  // pointer to the last element in ia

    // std::cout << *last << std::endl;

    //* Pointers Arithmetic
    constexpr size_t sz = 5;
    int arr2[sz] = {1, 2, 3, 4, 5};
    int *ip = arr2;
    int *ip2 = ip + 4; // ipw points to arr[4], the last element in arr

    // ok: arr is converted to a pointer to its first element; p points one past the end of arr
    int *p4 = arr2 + sz; // use caution -- do not dereference!
    int *p5 = arr2 + 10; // error; arr has only 5 elements; p5 has undefined value

    auto n = std::end(arr2) - std::begin(arr2);
    std::cout << n << std::endl;

    //* We can use the relational operators to compare pointers that point to elements of an array, or one past the last
    //* element in that array.
    // for instance
    int *b = arr2, *f = arr2 + sz;
    while (b < f)
    {
        // use *b
        std::cout << *b << std::endl;
        ++b;
    }

    //* We cannot use the relational operators on pointers to two unrelated objects
    int j = 0, sz2 = 42;
    int *q = &j, *e2 = &sz2;

    //* undefined: p and e2 are unrelated; comparison is meaningless!
    //^ while(q < e2);

    //* Interaction between Dereference and Pointer Arithmetic
    int ja[] = {0, 1, 2, 3, 4, 5}; // array with 5 elements of type int
    int llast = *(ja + 4);         // ok: initializes llast to 8, the value of ja[4];

    //* Subscripts and Pointers
    int k = ja[2]; // ja is converted to a pointer to the first element in ja
                   // ja[2] fetches the element to which (ja + 2) points
};

void subscriptsPointers()
{
    //* Interaction between Dereference and Pointer Arithmetic
    int ia[] = {0, 1, 2, 3, 4, 5}; // array with 5 elements of type int
    int last = *(ia + 4);          // ok: initializes last to 5, the value of ja[4];

    //* Subscripts and Pointers
    int i = ia[2]; // ia is converted to a pointer to the first element in ia
                   // ia[2] fetches the element to which (ia + 2) points

    int *p = ia;  // p points to the first element in ia
    i = *(p + 2); // equivalent to i = ia[2]

    int *q = &ia[2]; // 1 points to the element indexed by 2
    int j = q[1];    // q[1] is equivalent to *(p+1)
                     // p[1] is the same element as ia[3]
    int k = p[-2];   // p[-2] is the same element as ia[0]
}

void exercise334()
{
    int arr[4] = {2, 3, 12, 99};
    int *p1 = arr + 2, *p2 = arr + 3;
    p1 += p2 - p1;

    std::cout << *p1 << " " << *p2 << std::endl;
}

void exercise335()
{
    int arr[5] = {};
    int *start = std::begin(arr);
    int *end = std::end(arr);

    while (start < end)
    {
        *start = 2;
        ++start;
    }

    std::cout << arr[4] << std::endl;
}

// comparing two arrays
void exercise336()
{
    int arr1[6] = {2, 3, 4, 3};
    int arr2[6] = {2, 4, 4, 3};

    int *start = std::begin(arr1);
    int *end = std::end(arr1);
    int i = 0;
    int *start2 = arr2;

    while (start < end && i < 4)
    {
        if (*start == *(start2 + i))
        {

            std::cout << "yes"
                      << "";
        }
        else
        {
            std::cout << "false"
                      << "";
        }

        ++start;
        ++i;
        std::cout << std::endl;
    }
}

void exercise337()
{
    std::vector<int> jac = {3, 4, 5, 3};
    std::vector<int> jac2 = {3, 2, 5, 3};

    if (jac == jac2)
    {
        std::cout << "The vectors are equal"
                  << "";
    }
    else
    {
        std::cout << "The vectors aren't equal"
                  << "";
    }
}

//* C-Style Character String Functions

void cchar()
{
    std::string s1 = "hello my friend";
    std::string s2 = "hello my friend";

    std::cout << (s1 == s2) << std::endl;
}

void arrayVectorInit()
{
    int int_arr[] = {0, 1, 66, 3, 4, 5};
    std::vector<int> ivec(std::begin(int_arr), std::end(int_arr));
    for (auto &c : ivec)
        std::cout << c << "";

    std::cout << std::endl;
}

//* multidimensional arrays
// void mulitdimensionalArrays()
// {
//     int ia[3][4]; //* Array of size 3; each element is an array of ints of size 4
//     //* array of size 10; each elment is a 20-element array whose elements are arrays of 30 ints
//     int arr[10][20][30] = {0};

//     int arr2[10] = {0};
//     std::cout << arr2[6];
//     std::cout << std::endl;

//     //*Initializing elements of a multidimensional array
//     int ja[3][4] = {
//         {0, 1, 2, 3},
//         {4, 5, 6, 7},
//         {8, 9, 10, 11}};

//     int ia2[3][4] = {
//         0,
//         1,
//         2,
//         3,
//         4,
//         5,
//         6,
//         7,
//         8,
//         9,
//         10,
//         11};

//     std::cout << ja[2][1] << std::endl;

//     //*subscripting a multidimensional array
//     ia[2][3] = arr[0][0][0];

//     constexpr size_t rowCnt = 3, colCnt = 4;
//     int ia[rowCnt][colCnt]; // 12 uninitialized elements
//     // for each row
//     for (size_t i = 0; i != rowCnt; ++i)
//     {
//         for (size_t j = 0; j != colCnt; ++j)
//         {
//             ia[i][j] = i * colCnt + j;
//         }
//     }
// }

void testGithub()
{
    std::cout << "This is Github" << std::endl;
}

void arrayTest()
{
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; ++i)
    {
        for (size_t j = 0; j != colCnt; ++j)
        {
            ia[i][j] = i * colCnt + j;
        }
    }
}
void siever()
//{} pointers and multidimensional arrays
{
    std::vector<int> ivec;
    int number;

    while (std::cin >> number && number != 0)
    {
        ivec.push_back(number);
    }
    for (auto i = ivec.begin(); i != ivec.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
}

void swithcStatement()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;

    while (std::cin >> ch)
    {
        switch (ch)
        {
        case 'a':
            ++aCnt;
            break;

        case 'e':
            ++eCnt;
            break;

        case 'i':
            ++iCnt;
            break;

        case 'o':
            ++oCnt;
            break;

        case 'u':
            ++uCnt;
            break;
        }
    }
    std::cout << "Number of vowel a: \t" << aCnt << '\n'
              << "Number of vowel e: \t" << eCnt << '\n'
              << "Number of vowel i: \t" << iCnt << '\n'
              << "Number of vowel o: \t" << oCnt << '\n'
              << "Number of vowel u: \t" << uCnt << std::endl;
}

void ifStatement()
{
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, otherVowels = 0, spaceTabs = 0;
    char ch;
    while (std::cin >> ch)
    {
        if (ch == 'a' || ch == 'A')
        {
            ++aCnt;
        }
        else if (ch == 'e' || ch == 'E')
        {
            ++eCnt;
        }
        else if (ch == 'i' || ch == 'I')
        {
            ++iCnt;
        }
        else if (ch == 'o' || ch == 'O')
        {
            ++oCnt;
        }
        else if (ch == 'u' || ch == 'U')
        {
            ++uCnt;
        }
        else if (isspace(ch))

        {
            ++spaceTabs;
        }
        else
        {
            ++otherVowels;
        }
    }

    std::cout << "Number of vowel a: \t" << aCnt << '\n'
              << "Number of vowel e: \t" << eCnt << '\n'
              << "Number of vowel i: \t" << iCnt << '\n'
              << "Number of vowel o: \t" << oCnt << '\n'
              << "Number of vowel u: \t" << uCnt << '\n'
              << "Number of other vowels : \t" << otherVowels << std::endl;

    std::cout << "Number of spaceTabs:  \t" << spaceTabs << std::endl;
}

int main()
{
    ifStatement();
}