#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void quickSelect(vector<int> &nums, int left, int right, int k)
{
    if (left >= right)
        return;

    int pivot = nums[right];
    int l = left;
    for (int i = left; i < right; ++i)
    {
        if (nums[i] >= pivot)
        {
            swap(nums[i], nums[l++]);
        }
    }
    swap(nums[l], nums[right]);

    if (l == k)
        return;
    else if (l < k)
        quickSelect(nums, l + 1, right, k);
    else
        quickSelect(nums, left, l - 1, k);
}

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    string line;
    getline(fin, line);
    stringstream ss(line);

    vector<int> nums;
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }

    quickSelect(nums, 0, nums.size() - 1, 9);

    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 0; i < 10; ++i)
    {
        fout << nums[i] << (i < 9 ? " " : "");
    }

    fin.close();
    fout.close();
    return 0;
}
