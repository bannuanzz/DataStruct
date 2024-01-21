#include <iostream>
using namespace std;

// 采用区间划分法
class Solution
{
public:
    int removeDuplicates(int *nums, int numsSize)
    {
        if (numsSize == 0)
            return 0;
        int i = 0;
        for (int j = 1; j < numsSize; j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j]; // 虽然采用区间划分法但是这里是直接将后面的舍弃掉
            }
        }
        return i + 1;
    }
};
int main()
{
}