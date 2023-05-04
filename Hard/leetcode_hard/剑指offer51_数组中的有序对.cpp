#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
* �����е�����ԣ���������
* ����������֮ǰ˵�Ĺ鲢������С��
* �����ڹ鲢��ͬʱ�������Եĸ�������ٷ���
* ������������ԣ���   ��  >  ��  ʱ���������
* ���й鲢����ʱ���ս�������
* ÿһ�ν���merge�鲢ʱ���󲿷ָ��Ҳ����Ѿ������ˣ�Ȼ����������������鲢֮ǰ�����жϣ�
* �����ߵ�ֵ�����ұߵ�ֵ�������жϳ��ұ߽߱�R��ȥ��ǰ�ұ������±��ټ�һ������Ϊ�ұ��Ѿ������ˣ������ǽ������е��ұߵ�ǰ��С����ߵ�ǰ��ʱ���ұߵ�ǰ���ĺ�����������С����ߵ�ǰ����
* ����res+=R-index+1
* ��󷵻�res
* Ȼ����Ҫ�����ԭ���ǣ����ÿ�αȽ��겻����һ������Ļ����ᵼ�º���ıȽ���res��ֵ�����ظ���ӵ�ԭ��
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