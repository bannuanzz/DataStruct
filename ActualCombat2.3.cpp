// Memory Time
// 216K  16MS

#include <iostream>
#include <string>
using namespace std;

// 模拟竖式乘法
const int size = 1000; // 大数位数

void mult(char *A, char *B, char *ans)
{
    int a[size + 1] = {0};
    int b[size + 1] = {0};
    int pa = 0, pb = 0;
    int c[2 * size + 1] = {0};

    int lena = strlen(A);
    int lenb = strlen(B);

    for (int i = lena - 1; i >= 0; i--)
        a[pa++] = A[i] - '0';
    for (int j = lenb - 1; j >= 0; j--)
        b[pb++] = B[j] - '0';

    for (pb = 0; pb < lenb; pb++)
    {
        int w = 0; // 低位到高位的进位
        for (pa = 0; pa <= lena; pa++)
        {
            int temp = a[pa] * b[pb] + w;
            w = temp / 10;
            temp = (c[pa + pb] += temp % 10);
            c[pa + pb] = temp % 10;
            w += temp / 10;
        }
    }
    bool flag = false;
    bool sign = false; // 标记ans是否为全0
    for (pa = 0, pb = lena + lenb - 1; pb >= 0; pb--)
    {
        if (!flag && c[pb] == 0) // 删除ans开头的0
            continue;
        else
            flag = true;

        sign = true;
        ans[pa++] = c[pb] + '0';
    }
    if (sign)
        ans[pa] = '\0';
    else
    {
        ans[0] = '0';
        ans[1] = '\0';
    }

    return;
}

int main(void)
{
    char a[size + 1];
    char b[size + 1];
    char ans[2 * size + 1];
    while (cin >> a >> b)
    {
        mult(a, b, ans);
        cout << ans << endl;
    }
    return 0;
}