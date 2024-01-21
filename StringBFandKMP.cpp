#include <iostream>
#include <string>
using namespace std;
int BF(string s, string t)
{

    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; // 回退到s的下一个字符
            j = 0;
        }
    }
    if (j >= t.length())
        return i - t.length();
    else
        return -1;
}

void GetNext(string t, int *next)
{
    int j = 0,
        k = -1;
    next[0] = -1;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

int KMP(string s, string t)
{
    int n = s.size(), m = t.length();
    int *next = new int[m];
    GetNext(t, next);
    int i = 0,
        j = 0;
    while (i < n && j < m)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j >= m)
        return i - m;
    else
        return -1;
}
void GetNextval(string t, int *nextval)
{
    int j = 0;
    int k = -1;
    nextval[0] = -1;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[j] == t[k])
        {
            j++;
            k++;
            if (t[j] != t[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
        {
            k = nextval[k];
        }
    }
}
int KMPval(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int *nextval = new int[m];
    GetNextval(t, nextval);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (j == -1 || s[i] == t[i])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
    }
    if (j >= m)
        return i - m;
    else
        return -1;
}
int main()
{
}
