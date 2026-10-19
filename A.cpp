#include <iostream>
#include <string>
#include <vector>

int main() {
    int year;
    std::cin >> year;

    std::vector<std::string> competitions;

    if (year >= 2005) {
        competitions.push_back("ICPC Regional");
    }

    if (year >= 2019 && year != 2020 && year != 2021) {
        competitions.push_back("ICPC Qual");
    }

    if (year == 2026) {
        competitions.push_back("School Regional");
        competitions.push_back("School Qual");
    }

    std::cout << competitions.size() << '\n';
    for (const std::string& competition : competitions) {
        std::cout << competition << '\n';
    }

    return 0;
}