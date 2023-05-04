
//题目：
//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//
//由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
//
//注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x** 0.5 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/sqrtx

/*代码实现部分
* 这一题我采用的是二分的思想
* 给我一个数，然后如果这个数等于0或者等于1则直接返回他本身
* 如果不是等于0或者等于他本身，则进行二分，二分的中止条件是当L<=R，即当L=R时的那个值也有可能时给定数的平方根
* 循环中采用  X/M 的值与M 做比较，因为若M为X的平方根，则必然X=M*M(不用M*M作为判断条件是因为相乘可能溢出)，
* 若X/M小于了M则左边二分，如果大于了M则记录下M的值，然后继续右侧二分，记录下M时因为可能这时M已经为平方根了或者说最接近平方根的数
* 该题类似于求<=某数最右边的数
* 下面是我自己的题解，时间复杂度为O(logn)
*/
class Solution {
public:
    int mySqrt(int x) {
        return getSqrt(x, 0, x);
    }
    int getSqrt(int x, int L, int R) {
        if (L == R || x == 1) return R;
        int res = 0;
        while (L <= R) {
            int M = L + ((R - L) >> 1);
            if (x / M < M) R = M - 1;
            else {
                res = M;
                L = M + 1;
            }
        }
        return res;
    }
};