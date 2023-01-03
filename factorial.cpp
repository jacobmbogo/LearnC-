#include <iostream>

int factorial(int val)
{
    if (val > 1)
    {
        return (val * factorial(val - 1));
    }
}

int main()
{
    int j = factorial(5);
    std::cout << j << std::endl;
    return 0;
}