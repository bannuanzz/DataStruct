#include <iostream>
#include <queue>

using namespace std;

void processSoldiers(int n)
{
    queue<int> soldiers;
    for (int i = 1; i <= n; ++i)
    {
        soldiers.push(i);
    }

    int count = 2; // 开始时一至二报数

    while (soldiers.size() > 3)
    {
        int size = soldiers.size();
        for (int i = 1; i <= size; ++i)
        {
            int num = soldiers.front();
            soldiers.pop();

            if (i % count != 0)
            { // 如果没有报到指定的数，重新入队
                soldiers.push(num);
            }
        }
        count = count % 2 + 2; // 交替变换报数规则
    }

    while (!soldiers.empty())
    {
        cout << soldiers.front() << " ";
        soldiers.pop();
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int numSoldiers;
        cin >> numSoldiers;
        processSoldiers(numSoldiers);
    }

    return 0;
}
