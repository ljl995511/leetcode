/*题目：
* 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*下面是代码部分
* 代码采用的归并排序的思想，双指针法
* 时间复杂度O(m+n)
*/
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> temp;
        while (i < m && j < n)
        {
            temp.push_back(nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++]);
        }
        while (i < m)
            temp.push_back(nums1[i++]);
        while (j < n)
            temp.push_back(nums2[j++]);
        nums1 = temp;

    }
};