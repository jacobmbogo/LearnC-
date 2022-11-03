#include <iostream>
#include <vector>
#include <string>
using std::vector;
//**Defining and initializing vectors
void vectorstudy()
{
    vector<int> ivec;                 // ivec holds objects of type int;
    vector<vector<std::string>> file; //
};

void vectorstudy2()
{
    vector<std::string> svec;
    vector<int> ivec;        // copy elements of ivec into ivec2
    vector<int> ivec2(ivec); // copy elements of ivec into ivec3
    // vector<std::string> svec(ivec2); //error: svec holds strings, not ints
}

//**List initializing an initializer
void listing()
{
    vector<std::string> articles = {"a", "an", "the"};
    vector<std::string> v1{"a", "an", "the"};
    // vector<std::string> v2("a","an","the"); this is an error
};

//**creating a specified number of elements
void numberofelements()
{
    vector<int> ivec(10, -1);            // ten int elements each initialized to -1;
    vector<std::string> svec(10, "hi!"); // tens strings, each elements is "hi!";
}

//**value initialization
void valueinit()
{
    vector<int> ivec(10);         // ten elements, each initialized to 0
    vector<std::string> svec(10); // ten elements each an empty string;
    // vector<int> dvec = 19; // error: direct initialization must be used to supply a size
}

//**Adding elements to a vector
void pushback()
{
    vector<int> v2;
    for (int i = 0; i != 100; ++i)
        v2.push_back(i);
};

void storage()
{
    int age;
    vector<int> ages;
    while (std::cin >> age)
        ages.push_back(age);

    for (const auto &k : ages)
        std::cout << k << " " << std::endl;
};

// NB subscripting a vector does not add elements to a vector.
void storegrades()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (std::cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade / 10];
    }

    for (auto &k : scores)
        std::cout << k << std::endl;
}

void cannot()
{
    vector<int> ivec;
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
        ivec[ix] = ix; // disaster:ivec has no elements. if you want this to work, you must initialize the vector to hold the amount of ints you want to add to it.
    // the correct way to add is using ivec.push_back(ix); // adds new elements with value ix;
    for (auto k : ivec)
        std::cout << k << std::endl;
}

void question316()
{
    std::string s;
    vector<std::string> words;

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

    for (decltype(words.size()) i = 0; i != words.size(); ++i)
    {
        std::cout << words[i] << '\t';
        if ((i + i) % 8 == 0)
            std::cout << std::endl;
    }
};

void islegal()
{
    vector<int> ivec;
    ivec.push_back(42);

    for (auto k : ivec)
        std::cout << k << std::endl;
}

void last()
{
    int num;
    vector<int> numbers;

    while (std::cin >> num)
        numbers.push_back(num);

    for (decltype(numbers.size()) i = 0, j = numbers.size() - 1; i < numbers.size() - 1; ++i, --j)
    {
        int sum;
        if (numbers.size() % 2 != 0)
        {
            if (i == j)
            {
                std::cout << numbers[j] << std::endl;
                break;
            }
            else
            {
                sum = numbers[i] + numbers[j];
                std::cout << sum << std::endl;
            }
        }
        else
        {
            int center = numbers.size() / 2;
            sum = numbers[i] + numbers[j];
            std::cout << sum << std::endl;
            if (i == center - 1)
            {
                break;
            }
        }
    }
};

int main()
{
    last();
    return 0;
}