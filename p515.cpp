#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string line{"First of all, I'd like to ask a few questions. And then, we will discuss."};
    std::cout << line << std::endl;

    auto comma = find(line.cbegin(), line.cend(), ',');
    std::cout << std::string(line.cbegin(), comma) << std::endl;

    auto rcomma = find(line.crbegin(), line.crend(), ',');
    std::cout << std::string(line.crbegin(), rcomma) << std::endl;
    std::cout << std::string(rcomma.base(), line.cend()) << std::endl;
    std::cout << std::endl;

    std::cout << std::string(rcomma--.base(), line.cend()) << std::endl;
    std::cout << std::string(rcomma--.base(), line.cend()) << std::endl;
    std::cout << std::string(rcomma--.base(), line.cend()) << std::endl;
    std::cout << std::endl;

    rcomma = find(line.crbegin(), line.crend(), ',');
    std::cout << std::string(--rcomma.base(), line.cend()) << std::endl;
    std::cout << std::string(--rcomma.base(), line.cend()) << std::endl;
    std::cout << std::string(--rcomma.base(), line.cend()) << std::endl;
}
