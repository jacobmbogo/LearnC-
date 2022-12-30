#include <iostream>
#include <string>
#include <vector>

void doWhile()
{

    std::string rsp; // used in the condition; can't be defined inside the do
    do
    {
        std::cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        std::cin >> val1 >> val2;
        std::cout << "The sum of " << val1 << " and " << val2 << " = " << val1 + val2 << "\n\n"
                  << "More? Enter yes or no: ";
        std::cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
}

int main()
{
    doWhile();
}