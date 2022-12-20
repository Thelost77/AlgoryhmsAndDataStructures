#include <iostream>
#include <fstream>
#include "list.h"
#include "list.cpp"

int main()
{
    List<int> list{};
    std::ifstream input{"liczby.txt"};
    if (not input)
    {
        std::cerr << "Error occured during opening the file liczby.txt" << std::endl;
        exit(-1);
    }
    int number;
    while (input >> number)
    {
        list.push_back(number);
    }
    list.bubbleSort();
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}