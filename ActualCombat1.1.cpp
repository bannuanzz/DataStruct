#include <iostream>
using namespace std;
const int Max = 100;
int Invert(int a)
{
    int n;
    int inv = 0;
    while (a != 0)
    {
        n = a % 10;
        inv = inv * 10 + n;
        a = a / 10;
    }
    return inv;
}
int main()
{
    int n;
    cin >> n;
    int a[Max];
    int b[Max];
    int c[Max];
    // n = Invert(n);
    // cout << n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        int c1, c2;
        c1 = Invert(a[i]);
        c2 = Invert(b[i]);
        int sum;
        sum = c1 + c2;
        c[i] = Invert(sum);
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }
}