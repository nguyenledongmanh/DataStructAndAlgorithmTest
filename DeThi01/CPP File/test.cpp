#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "Enter your name: ";
    getline(std::cin, name);

    cout << name << endl;

    return 0;
}