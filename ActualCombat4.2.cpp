#include <iostream>
#include <string>

using namespace std;

int countOccurrences(const string &S1, const string &S2)
{
    int count = 0;
    int lenS1 = S1.length(), lenS2 = S2.length();

    // 遍历 S2，并将每个长度与 S1 相同的子串与 S1 比较
    for (int i = 0; i <= lenS2 - lenS1; ++i)
    {
        if (S2.substr(i, lenS1) == S1)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string S1, S2;
        cin >> S1 >> S2;

        cout << countOccurrences(S1, S2) << endl;
    }

    return 0;
}
