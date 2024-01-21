#include <iostream>
using namespace std;
const int MaxSize = 100;
class SqString
{
public:
    char *data;
    int length;
    SqString &SubStr(int i, int j)
    {
        static SqString s;
        if (i < 0 || i > length || j < 0 || j + i > length)
            return s;
        for (int k = i; k < i + j; k++)
        {
            s.data[k - 1] = data[k];
        }
        s.length = j;
        return s;
    }
    int Strcmp(SqString &s, SqString &t)
    {
        int minl = min(s.getlength(), t.getlength());
        for (int i = 0; i < minl; i++)
        {
            if (s.data[i] > t.data[i])
                return 1;
            else if (s.data[i] < t.data[i])
                return -1;
        }
        if (s.getlength() == t.getlength())
            return 0;
        else if (s.getlength() > t.getlength())
            return 1;
        else
            return -1;
    }
}