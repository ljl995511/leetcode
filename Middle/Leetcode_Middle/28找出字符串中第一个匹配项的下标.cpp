#include<iostream>
#include<string>
using namespace std;

/*这一题通过KMP算法解题*/
/*首先构建next数组，得出前缀表*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty() || needle.empty())
            return -1;
        int* next = getnext(needle);
        int i = 0;
        int j = 0;
        /*得出前缀表后开始遍历原目标字符串*/
        /*如果目标字符串和模式串相等或者当j=-1(即当目标串中)*/
        while (i < haystack.size()) {

            if (j == -1 || needle[j] == haystack[i]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
            if (j == needle.size())
                return i - needle.size();
        }
        return -1;
    }
    int* getnext(string str)
    {
        int* next = new int[str.size()];
        int i = 0;
        int j = -1;
        next[0] = -1;
        while (i < str.size() - 1)
        {
            if (j == -1 || str[j] == str[i])
            {
                next[++i] = ++j;
            }
            else {
                j = next[j];
            }
        }
        return next;
    }
};

//
//int main()
//{
//    Solution* test = new Solution();
//    string A = "a";
//    string B = "a";
//    cout << test->strStr(A, B);
//    return 0;
//}