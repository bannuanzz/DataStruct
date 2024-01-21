#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floydWarshall(vector<vector<int>> &dist, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int findBestVillage(const vector<vector<int>> &dist, int n)
{
    int bestVillage = -1;
    int minMaxDistance = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int maxDistance = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                maxDistance = max(maxDistance, dist[i][j]);
            }
        }
        if (maxDistance < minMaxDistance)
        {
            minMaxDistance = maxDistance;
            bestVillage = i;
        }
    }

    return bestVillage + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if (i != j && matrix[i][j] == 0)
            {
                matrix[i][j] = INT_MAX;
            }
        }
    }
    floydWarshall(matrix, n);
    cout << findBestVillage(matrix, n) << endl;
}
