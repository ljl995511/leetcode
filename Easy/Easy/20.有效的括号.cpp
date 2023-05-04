#include<iostream>;
using namespace std;
//class Solution {
//public:
//    bool isValid(string s) {
//        Stack* sta = new Stack();
//        int i = 0;
//        while (s[i] == '(' || s[i] == '{' || s[i] == '[') push(sta, s[i++]);
//        if (is_Empty(sta))
//            return false;
//        else {
//            while (i < s.length())
//            {
//                switch (s[i])
//                {
//                case')': {
//                    if (pop(sta) != '(')
//                        return false;
//                }; break;
//                case']': {
//                    if (pop(sta) != '[')
//                        return false;
//                }; break;
//                case'}': {
//                    if (pop(sta) != '{')
//                        return false;
//                }; break;
//                 default : {
//                    push(sta, s[i]);
//                }; break;
//
//                }
//                i++;
//            }
//            if (is_Empty(sta))
//                return true;
//            else return false;
//        }
//    };
//    struct Stack {
//        char ch;
//        Stack* next;
//        Stack() { ch = '\0'; next = nullptr; }
//    };
//
//    bool push(Stack* sta, char ch)
//    {
//        Stack* temp = new Stack();
//        temp->ch = ch;
//        temp->next = sta->next;
//        sta->next = temp;
//        return true;
//    };
//    char pop(Stack* sta)
//    {
//        if (sta->next == nullptr)
//            return '\0';
//        else {
//            Stack* temp = sta->next;
//            char ch = temp->ch;
//            sta->next = temp->next;
//            delete temp;
//            return ch;
//        }
//    }
//
//    bool is_Empty(Stack* sta)
//    {
//        return sta->next == nullptr;
//    }
//};
//
//

/*下面是力扣的题解*/
/*判断括号的有效性可以使用「栈」这一数据结构来解决。

我们遍历给定的字符串 
�
s。当我们遇到一个左括号时，我们会期望在后续的遍历中，有一个相同类型的右括号将其闭合。由于后遇到的左括号要先闭合，因此我们可以将这个左括号放入栈顶。

当我们遇到一个右括号时，我们需要将一个相同类型的左括号闭合。此时，我们可以取出栈顶的左括号并判断它们是否是相同类型的括号。如果不是相同的类型，或者栈中并没有左括号，那么字符串 
�
s 无效，返回 
False
False。为了快速判断括号的类型，我们可以使用哈希表存储每一种括号。哈希表的键为右括号，值为相同类型的左括号。

在遍历结束后，如果栈中没有左括号，说明我们将字符串 
�
s 中的所有左括号闭合，返回 
True
True，否则返回 
False
False。

注意到有效字符串的长度一定为偶数，因此如果字符串的长度为奇数，我们可以直接返回 
False
False，省去后续的遍历判断过程*/

//class Solution {
//public:
//    bool isValid(string s) {
//        int n = s.size();
//        if (n % 2 == 1) {
//            return false;
//        }
//
//        unordered_map<char, char> pairs = {
//            {')', '('},
//            {']', '['},
//            {'}', '{'}
//        };
//        stack<char> stk;
//        for (char ch : s) {
//            if (pairs.count(ch)) {
//                if (stk.empty() || stk.top() != pairs[ch]) {
//                    return false;
//                }
//                stk.pop();
//            }
//            else {
//                stk.push(ch);
//            }
//        }
//        return stk.empty();
//    }
//};
//
//作者：LeetCode - Solution
//链接：https ://leetcode.cn/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

/*力扣官方的题解
* 时间复杂度O(n)
* 空间复杂度为O(n+求和符号)
*/