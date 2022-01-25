/*
Cho day so 1.5 8.5 -2.5 6.5 7.5 2.5 9.5 4.5
a) mo ta qua trinh sap xep day so tren bang insertion sort
b) viet function su dung insertion sort
c) xap sep theo thu tu giam dan, mo ta qua trinh tim kiem
nhi phan de tim kiem so 4.2, hay cho biet ket qua tim duoc
*/

#include <iostream>

using namespace std;

void InsertionSort(double a[], int n)
{
    int i, j;
    double x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

int main()
{
    double a[8] = {1.5, 8.5, -2.5, 6.5, 7.5, 2.5, 9.5, 4.5};
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
    InsertionSort(a, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;

    return 0;
}