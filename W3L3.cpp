#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int countInversions(const string &sequence)
{
    int invCount = 0;
    for (size_t i = 0; i < sequence.length(); ++i)
    {
        for (size_t j = i + 1; j < sequence.length(); ++j)
        {
            if (sequence[i] > sequence[j])
            {
                invCount++;
            }
        }
    }
    return invCount;
}

void sortSequencesByInversions(vector<string> &sequences)
{
    sort(sequences.begin(), sequences.end(),
         [](const string &a, const string &b)
         {
             return countInversions(a) < countInversions(b);
         });
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> sequences(m);

    for (int i = 0; i < m; ++i)
    {
        cin >> sequences[i];
    }

    sortSequencesByInversions(sequences);

    for (const auto &seq : sequences)
    {
        cout << seq << endl;
    }

    return 0;
}
