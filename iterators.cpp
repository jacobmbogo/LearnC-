#include <iostream>
#include <vector>
#include <string>

// Iterator operations
void capitalize()
{
    std::string s("some string");
    if (s.begin() != s.end())
    {                        // makes sure s is not empty
        auto it = s.begin(); // it denotes dthe first character in s

        *it = toupper(*it); // make that character uppercase
    }
    std::cout << s << std::endl;
};

//*NB Iterators use the increment(++) operator to move from one element to then next.Incrementing iterator is logically similar
// to operation to incrementing an integer.

//*Because the iterator returned from end does not denote an element,it may not be incremented or dereferenced.
void capitalize2()
{
    std::string s("some shitty string");
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);

    std::cout << s << std::endl;
}

// NB As with size_type, the library types that have iterators define types named iterator and
// const_iterator that represent actual iterator types:
void explanation()
{
    std::vector<int>::iterator it;        // it can read and write vector<int> elements.
    std::string::iterator it2;            // it2 can read and write characters in a strign.
    std::vector<int>::const_iterator it3; // It can read but not write elements
    std::string::const_iterator it4;      // it4 can read but not write characters in a string
}
// If a vector or string is const, we may use only its const_iterator type. With a non const vector
// or string, we can use either iterator or const_iterator.

void iterators()
{
    std::vector<int> v;
    const std::vector<int> cv;
    auto it1 = v.begin();  // it1 has type vector<int>::iterator
    auto it2 = cv.begin(); // it2 has type vector<int>::const_iterator
    auto it3 = v.cbegin(); // it3 has type vector<int>::const_iterator

    // combining dereference and member access
    // Assuming that **it** is an iterator into this vector, we can check whether the
    // string that it denotes es empty as follows:

    //(*it1).empty();  //dereferences it and calls the meber empty on the resulting object
    // *it.empty() // error: attempts to fetch the member named empty from it but it is an iterator
    // and has no member named empty.

    // it ->mem is a synonym for (*it ).mem;
    /**

    for(auto it = text.cbegin(); it != text.cend() && !it->emtpy(); ++it)
         cout << *it << endl;

    */

    //? some vector operations invalidate iterators.
}

void question316()
{
    std::string s;
    std::vector<std::string> words;

    while (std::cin >> s)
    {
        words.push_back(s);
        if (s == "end")
            break;
    }
    for (auto &k : words)
    {
        for (auto &c : k)
        {
            c = toupper(c);
        }
    }

    auto it2 = words.cend();
    for (auto it1 = words.cbegin(); it1 != it2; ++it1)
    {
        std::cout << *it1 << '\t' << std::endl;
    }
};

void printtext()
{
    std::vector<std::string> text{"Imran", "love", "you", "so", "much"};
    for (auto it = text.begin(); it != text.end() & !it->empty(); ++it)
    {
        for (auto &c : *it)
        {
            c = toupper(c);
        }
        std::cout << *it << std::endl;
    }
}

void doubleValues()
{
    std::vector<int> numbers;
    // write a program to create a vector with 10 int elements;
    for (decltype(numbers.size()) i = 0; i < 10; i++)
    {
        numbers.push_back(i + 1);
    }

    // double the values of each element of the vector
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        *it = *it * 2;
    }
    // read the new values of the vector
    for (auto &n : numbers)
    {
        std::cout << n << std::endl;
    }
}

//* Iterator Arithmetic
void binarySearch(int sought)
{
    std::vector<int> text{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2;

    while (mid != end && *mid != sought)
    {
        if (sought < *mid)
            end = mid - 1;
        else
            beg = mid + 1;

        mid = beg + (end - beg) / 2;
    }

    if (*mid == sought)
        std::cout << "Found at index " << *mid << std::endl;
};

void last_exercise()
{
    int num;
    std::vector<int> numbers;
    while (std::cin >> num)
        numbers.push_back(num);

    auto end = numbers.end();

    for (auto beg = numbers.begin(); beg != end - 1; ++beg)
    {
        std::cout << *beg + *(beg + 1) << std::endl;
    }
}
void last_exercise2()
{
    int num;
    std::vector<int> numbers;
    while (std::cin >> num)
        numbers.push_back(num);

    auto mid = numbers.begin() + numbers.size() / 2;

    for (auto beg = numbers.begin(), end = numbers.end() - 1; beg < end; ++beg, --end)
    {
        std::cout << *beg + *end << std::endl;
        if (beg == mid)
        {
            std::cout << *beg << std::endl;
            break;
        }
    }
}

void gradeCluster()
{
    int grade;
    std::vector<int> grades(11, 0);

    while (std::cin >> grade)
    {
        auto gradePosition = grades.begin() + grade / 10;
        ++(*gradePosition);
    }

    for (auto &c : grades)
    {
        std::cout << c << std::endl;
    }
}

int main()
{
    gradeCluster();
    return 0;
}