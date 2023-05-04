//����һ���������� nums �������һֵ�������г��� �������� ������ true �����������ÿ��Ԫ�ػ�����ͬ������ false
/*��������ʹ����sort������������һ������
* Ȼ��ֱ��һ��forѭ�����������������ȣ���˵��һ���Ǵ��ڣ�����true
* ����������˻�û���أ�˵����������ͬ��Ԫ�أ���ѭ�������󷵻�flase
* �����Լ�д�Ĵ���ʱ�临�Ӷ�ΪO(N*logN),����NΪ���鳤�ȣ���Ҫ����������
* �ռ临�Ӷ�ΪO(logN)
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