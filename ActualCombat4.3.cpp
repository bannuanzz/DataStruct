#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        for (int i = 1; i * 2 <= n; ++i)
        {
            if (n % i == 0)
            {
                bool match = true;
                for (int j = i; j < n; ++j)
                {
                    if (s[j] != s[j - i])
                    {
                        match = false;
                        break;
                    }
                }
                if (match)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/repeated-substring-pattern/solutions/386481/zhong-fu-de-zi-zi-fu-chuan-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。