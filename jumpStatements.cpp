#include <iostream>
#include <vector>
#include <string>

int main()
{

    /**
     * @brief
     *  Write a program to read a sequence of strings from the
    standard input until either the same word occurs twice in succession or all
    the words have been read. Use a while loop to read the text one word at a
    time. Use the break statement to terminate the loop if a word occurs twice
    in succession. Print the word if it occurs twice in succession, or else print a
    message saying that no word was repeated.
     */

    /**
     * @brief
     * 1. Reads a sequence of strings.
     * 2. until a same word occurs (meaning break if same words occur), or if all words have been read.
     * 3. use a while loop to read the text one word at a time.
     */

    std::string str;
    std::string prevStr;
    int cnt = 0;

    while (std::cin >> str)
    {
        if (str == prevStr)
        {
            cnt++;
            std::cout << str << std::endl;
            break;
        }
        else
        {
            cnt = 1;
            prevStr = str;
        }
    }

    if (cnt < 2)
    {
        std::cout << "No word was repeated" << std::endl;
    }

    return 0;
}

// * correct, but I could have also used boolean, => bool hasRepeat = false, then if there is a repeat then the bool is set to false