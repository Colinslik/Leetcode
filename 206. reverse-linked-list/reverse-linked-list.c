/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* left;
    struct ListNode* mid;
    struct ListNode* right;
    left = head;
    if(!head) return head;
    if(left->next)
    {
        mid = left->next;
        left->next = '\0';
        if(mid->next)
        {
            right = mid->next;
            while(right)
            {
                mid->next = left;
                left = mid;
                mid = right;
                right = right->next;
            }
        }
        mid->next = left;
        head = mid;
    }
    return head;
}
