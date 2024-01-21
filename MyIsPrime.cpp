#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool isPrime(int n)
{
    for (int i = 2; i < int(sqrt(n)); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    cout << isPrime(n);
}