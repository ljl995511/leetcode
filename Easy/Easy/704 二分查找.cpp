/*给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 - 1

来源：力扣（LeetCode）
链接：https ://leetcode.cn/problems/binary-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*下面是题解
* 该题是一道很经典的一道二分题
* 时间复杂度O(logN)
* 空间复杂度O(1)
*/
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        int M = 0;
        // int result = -1;
        while (L <= R)
        {
            M = L + ((R - L) >> 1);
            if (nums[M] == target) return M;
            if (nums[M] >= target) R = M - 1;
            else
                L = M + 1;
        }
        return -1;
    }
};