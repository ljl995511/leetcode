//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
//
//����ɾ����������ͷ�ڵ㡣
//
//ע�⣺����Ա�ԭ���иĶ�


/*�����Ǵ��벿�֣�����һ����õ�˫ָ�뷨ɾ��������Ľڵ�
* ��ΪҪɾ���������ĳ���ڵ㣬����֪����ǰһ���ڵ㣬�������ܶ������ɾ��
* ����һ��preָ��ָǰ�棬һ��nexָ��ָ�������
* �������Լ�д�Ĵ��룬ʱ�临�Ӷ�ΪO(n)
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        while (head != nullptr) {
            if (head->val == val) {
                ListNode* temp = head;
                head = head->next;
                // delete temp;
            }
            else break;
        }
        ListNode* pre = head;
        ListNode* nex = head->next;
        while (nex != nullptr)
        {
            if (nex->val == val)
            {
                ListNode* temp = nex;
                pre->next = nex->next;
                nex = nex->next;
                pre = nex;
                delete temp;
            }
            else {
                pre = nex;
                nex = nex->next;
            }

        }
        return head;
    }
};