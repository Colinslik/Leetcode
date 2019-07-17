/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        else {
            int l1num = ((l1 != NULL)? l1->val : 0);
            int l2num = ((l2 != NULL)? l2->val : 0);
            ListNode* sum = new ListNode((l1num + l2num) % 10);
            l1 = ((l1)? l1->next : l1);
            l2 = ((l2)? l2->next : l2);
            if ((l1num + l2num)/10 > 0) {
                if (l1 == NULL) {
                    l1 = new ListNode((l1num + l2num) / 10);
                }
                else {
                    l1->val += (l1num + l2num)/10;
                }
            }
            sum->next = addTwoNumbers(l1, l2);
            return sum;
        }
    }
};
