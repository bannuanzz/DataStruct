#include <iostream>
#include <stack>
using namespace std;

const int MaxSize = 100;

class SqStack
{
    int *data;
    int top;
    SqStack()
    {
        data = new int[MaxSize];
        top = -1;
    }
    ~SqStack()
    {
        delete[] data;
    }
    bool empty()
    {
        return top == -1;
    }
    bool push(int e)
    {
        if (top == MaxSize - 1)
            return false;
        top++;
        data[top] = e;
        return top;
    }
    bool pop(int &e)
    {
        if (empty())
            return false;
        e = data[top];
        top--;
        return true;
    }
    bool gettop(int &e)
    {
        if (empty())
            return false;
        e = data[top];
        return true;
    }
};

// 括号是否配对
bool isMatch(string str)
{
    stack<char> st;
    int i = 0;
    char e;
    while (i < str.length())
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);
        else
        {
            if (str[i] == ')')
            {
                if (st.empty())
                    return false;
                e = st.top();
                st.pop();
                if (e != '(')
                    return false;
            }
            if (str[i] == ']')
            {
                if (st.empty())
                    return false;
                e = st.top();
                st.pop();
                if (e != '[')
                    return false;
            }
            if (str[i] == '}')
            {
                if (st.empty())
                    return false;
                e = st.top();
                st.pop();
                if (e != '{')
                    return false;
            }
        }
        i++;
    }
    return st.empty();
}

bool ifPalindrome(string str)
{
    stack<char> st;
    char e;
    int i = 0;
    while (i < str.length() / 2)
    {
        st.push(str[i]);
        i++;
    }
    if (str.length() % 2 == 1)
        i++;
    while (i < str.length())
    {
        if (st.empty())
            false;
        e = st.top();
        st.pop();
        if (e != str[i])
            return false;
        i++;
    }
    return true;
}
int main()
{
}