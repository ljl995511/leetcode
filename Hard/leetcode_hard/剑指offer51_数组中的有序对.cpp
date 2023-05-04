#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
* 数组中的有序对，即逆序数
* 类似于左神之前说的归并排序求小和
* 即：在归并的同时求出逆序对的个数最后再返回
* 该题是求逆序对，即   左  >  右  时满足逆序对
* 所有归并排序时按照降序排序
* 每一次进入merge归并时，左部分跟右部分已经有序了，然后在左右两个数组归并之前进行判断，
* 如果左边的值大于右边的值，可以判断出右边边界R减去当前右边数的下标再加一（即因为右边已经有序了，而且是降序，所有当右边当前数小于左边当前数时，右边当前数的后面所有数都小于左边当前数）
* 所以res+=R-index+1
* 最后返回res
* 然后需要排序的原因是，如果每次比较完不进行一次排序的话，会导致后面的比较中res的值存在重复相加的原因
*/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2 || nums.empty())
            return 0;
        return process(nums, 0, nums.size() - 1);
    }

    int process(vector<int>& nums, int L, int R)
    {
        if (L == R)
            return 0;
        int M = L+((R-L)>>1);
        return process(nums, L, M) + process(nums, M + 1, R) + merge(nums, L, M, R);
    }

    int merge(vector<int>& nums, int L, int M, int R)
    {
        int* help = new int[R - L + 1];
        int p1 = L;
        int p2 = M+1;
        int res = 0;
        int i = 0;
        while (p1 <= M && p2 <= R)
        {
            if (nums[p1] > nums[p2]) {
                res += R - p2 + 1;
            }
            help[i++] = nums[p1] > nums[p2] ? nums[p1++] : nums[p2++];
        }
        while (p1 <= M)
            help[i++] = nums[p1++];
        while (p2 <= R)
            help[i++] = nums[p2++];
        for (i = 0; i < R - L + 1; i++)
            nums[L+i] = help[i];
        delete[] help;
        return res;
    }
};



//int main()
//{
//    vector<int> test = { 1,3,2,3,1 };
//    Solution* temp = new Solution();
//    //temp->reversePairs(test);
//    cout << temp->reversePairs(test) << endl;
//    for (auto it : test)
//    {
//        cout << it << endl;
//    }
//    delete temp;
//}