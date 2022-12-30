#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string str = "1 2 3 4 5";
    std::stringstream ss(str);

    int x;
    while (ss >> x)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
