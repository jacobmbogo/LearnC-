
#include <iostream>
#include <vector>
#include <string>

/**
 * @file isPrefix.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-12-30
 *
 * @copyright Copyright (c) 2022
 *
 *
 * : Given two vectors of ints, write a program to determine
whether one vector is a prefix of the other. For vectors of unequal
length, compare the number of elements of the smaller vector. For
example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
8, respectively your program should return true.
 */

/**
 * @brief
 * thought process
 *
 * If the order will always be that the smaller vector is the first input then
 * there is no need for swapping, but if no particular order is followed then we need to enable swapping in our function
 */

bool isPrefix(std::vector<int> &v, std::vector<int> &u)
{
    // assumption is made that the smaller vector will always be the first input,
    // if that is not the case recall the function - to swap the order
    if (v.size() > u.size())
    {
        return isPrefix(u, v);
    }

    for (size_t ix = 0; ix < v.size(); ++ix)
    {
        if (v[ix] != u[ix])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::vector<int> v1{1, 1, 2, 3};
    std::vector<int> v2{1, 1, 2, 3, 4, 5};

    std::cout << std::boolalpha << isPrefix(v1, v2) << std::endl;
    return 0;
}

/**
 * @brief
 * //* what is std::boolalpha:: used to manipulate the output of boolean values, by default they are outputted as 0 for false and 1 for true
 * //* std::boolalpha converts them to 'false and true' respectively
 *
 * //* std::noboolalpha switches it back to outputting 0 or 1
 */
