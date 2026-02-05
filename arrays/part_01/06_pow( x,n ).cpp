#include <iostream>
using namespace std;

int pow(int x, int n)
{
    long N = n;
    if (x == 0)
        return 0;
    if (x == 1 || N == 0)
        return 1;
    if (x == -1 && N % 2 == 0)
        return 1;
    if (x == -1 && N % 2 != 0)
        return -1;

    if (N < 0)
    {
        x = 1 / x;
        N = abs(N);
    }

    long product = 1;

    while (N > 0)
    {
        if (N % 2 != 0)
            product *= x;
        x *= x;
        N /= 2;
    }

    return product;
}

int main()
{
    int x = 2;
    int n = 20;
    cout << pow(x, n);
}