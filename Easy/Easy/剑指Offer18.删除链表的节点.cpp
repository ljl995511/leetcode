//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//
//返回删除后的链表的头节点。
//
//注意：此题对比原题有改动


/*下面是代码部分，我这一题采用的双指针法删除单链表的节点
* 因为要删除单链表的某个节点，必须知道其前一个节点，这样才能对其进行删除
* 所有一个pre指针指前面，一个nex指针指后面的数
* 下面是自己写的代码，时间复杂度为O(n)
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