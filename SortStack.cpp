#include <iostream>
#include <stack>
using namespace std;
void Sortst(stack<int> &st)
{
    stack<int> st1;
    int e;
    while (!st.empty())
    {
        e = st.top();
        st.pop();
        while (!st1.empty() && e < st1.top())
        {
            st.push(st1.top());
            st1.pop();
        }
        st1.push(e);
    }
    while (!st1.empty())
    {
        e = st1.top();
        st1.pop();
        st.push(e);
    }
}
int main()
{
}