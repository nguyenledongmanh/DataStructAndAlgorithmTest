/*Cho ham so f(a) = if(a < 0, |a|, a = 0, f(a-5), a > 0, a + f(a-2)) */
// Requires: a) viet ham de quy tinh gia tri ham f
// b) tinh f(9) va giai thich cach tinh
#include <iostream>

using namespace std;

int Func(int a)
{
    if (a < 0)
    {
        return -a;
    }
    else if (a == 0)
    {
        return Func(a - 5);
    }
    return a + Func(a - 2);
}

int main()
{
    int result = Func(9);
    cout << "Result f(9): " << result << endl;
    return 0;
}

// Mo ta thuat toan tinh f(9)
// f(9) -> 9 + f(7) -> 9 + 7 + f(5) -> 9 + 7 + 5 + f(3) -> 9 + 7 + 5 + 3 + f(1) -> 9 + 7 + 5 + 3 + 1 + f(-1) -> 9 + 7 + 5 + 3 + 1 + 1 = 26