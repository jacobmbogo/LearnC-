#include <iostream>
using namespace std;

int exercise()
{
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');

    string s5 = "hiya"; // copy initialization
    string s6("hiya");  // direct initialization
    string s7(10, 'c');
    string s8 = string(10, 'c');

    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
    return 0;
};

int exercise2()
{
    string s;
    cout << "Enter string :" << endl;
    cin >> s;
    cout << s << endl;
    return 0;
};

int exercise3()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2 << endl;
    return 0;
};

int exercise4()
{
    string word;
    while (cin >> word)
    {
        cout << word << endl;
    }
    return 0;
};

int exercise5()
{
    string line;
    // read input a line at a time until end-of-file
    while (getline(cin, line))
        cout << line << endl;

    return 0;
};

int exercise6()
{
    string line;
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
}

int exercise7()
{
    string line;
    while (getline(cin, line))
        if (line.size())
            cout << line << line.size() << endl;
};

int exercise8()
{
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";

    if (slang > phrase)
        cout << true << endl;
    else
        cout << false << endl;

    return 0;
}

int exercise9()
{
    string st1(10, 'c'), st2;
    st1 = st2;

    string s1 = "hello, ", s2 = "world\n";
    string s3 = s1 + s2;
    s1 += s2;
    cout << s1;
    return 0;
}

int exercise10()
{
    string s1 = "hello", s2 = "world";
    string s3 = s1 + ", " + s2 + '\n';
    string s4 = s1 + ", ";
    string s6 = "hello" + s2 + " ," + "hello" + "hello" + "hello";
    cout << s6;
}

int exercise32()
{
    string line;
    while (getline(cin, line))
        cout << line << endl;

    return 0;
}

int exercise33()
{
    string line1, line2;
    while (cin >> line1)
    {
        cin >> line2;
        if (line1 == line2)
            cout << "equal" << endl;
        else if (line1 > line2)
            cout << "line1 is larger that line2" << endl;
        else
            cout << "line2 is larger" << endl;
    }
    return 0;
};

int exercise35()
{
    string large, minis;
    while (cin >> minis)
    {
        large += minis;
        cout << large << endl;
    }
    return 0;
}

void concatenate_with_space()
{
    string total, s;
    if (cin >> total)
    {
        while (cin >> s)
            total += ' ' + s;
    }
    cout << total;
}

void returnlength(string line)
{
    cout << line.size() << endl;
}

void pritevery()
{
    string str("some string");
    for (auto c : str)
        cout << c << endl;
};

void countpunctuation()
{
    string s("hello world!!!");
    decltype(s.size()) punct_cnt = 0;

    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;

    cout << punct_cnt << " punctuation characters in " << s << endl;
};

void test_string()
{
    auto s = 'B';
    s = tolower(s);

    cout << s << endl;
}

void just_some_function()
{
    string s("Hello World!!!");
    for (auto &c : s)
        c = toupper(c);

    cout << s << endl;
};

void capitalization()
{
    string s("some string");
    if (!s.empty())
        s[0] = toupper(s[0]);

    cout << s << endl;
};

void firstword_to_capital(string s)
{
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]);
    cout << s << endl;
};

void convert_to_hexa()
{
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15 "
         << "separated by spaces> Hit ENTER when finished: " << endl;
    string result;
    string::size_type n;

    while (cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];
        else
            result = "Hex number is out of range";
    cout << "Your hex number is: " << result << endl;
}

void exercise36()
{
    string s = "hellow myfriend";
    for (auto &c : s)
        c = 'x';
    cout << s << endl;
};

void exercise37()
{
    string s = "hellow myfriend";
    decltype(s.size()) index = 0;
    while (index < s.size())
    {
        s[index] = 'X';
        ++index;
    }

    cout << s << endl;
}

void exercise38()
{
    string s = "hellow myfriend";
    for (decltype(s.size()) index = 0; index < s.size(); ++index)
        s[index] = 'X';

    cout << s << endl;

    string v;
    cout << v[0] << endl;
}

void exercise310()
{
    string total;
    string s;
    getline(cin, s);
    for (decltype(s.size()) index = 0; index < s.size(); ++index)
        if (!ispunct(s[index]))
            total += s[index];
    cout << total << endl;
};

int main()
{
    exercise310();
    return 0;
}