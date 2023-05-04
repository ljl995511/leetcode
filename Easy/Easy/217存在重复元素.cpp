//给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false
/*该题首先使用了sort排序对数组进行一次排序
* 然后直接一次for循环遍历，如果相邻相等，则说明一定是存在，返回true
* 如果遍历完了还没返回，说明不存在相同的元素，即循环结束后返回flase
* 下面自己写的代码时间复杂度为O(N*logN),其中N为数组长度，需要对数组排序
* 空间复杂度为O(logN)
*/


#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};