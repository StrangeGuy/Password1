

#include <iostream>
#include <string>

bool validate(std::string s)
{
    int counter = 0;
    bool check[]{ 0,0,0,0 };
    if (s.length() < 8 || s.length() > 14) return false;
    for (char c : s)
    {
        if (c < 33 || c > 126) return false;
        if ((c > 32 && c < 48) || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122) check[0] = 1;
        if (c > 47 && c < 58) check[1] = 1;
        if (c > 64 && c < 91) check[2] = 1;
        if (c > 96 && c < 123) check[3] = 1;
    }
    for (bool b : check)
    {
        if (b == true) counter++;
    }
    return counter >= 3 ? true : false;
}


int main()
{
    std::cout << "Hello my friend! Select your new password, but please, try to make it conform to some standards.\n And don't forget it afterwords..." << std::endl;
    std::string password{ "" };
    std::cin >> password;
    if (validate(password))
    {
        std::cout << "Password confirmed" << std::endl;
    }
    else
    {
        std::cout << "Password rejected" << std::endl;
    }
}

