#include <iostream>

int absoluteValue(int val)
{
    if (val < 0)
    {
        return -val;
    }
    return val;
}

int main()
{
    int j = absoluteValue(5);
    std::cout << j << std::endl;
}