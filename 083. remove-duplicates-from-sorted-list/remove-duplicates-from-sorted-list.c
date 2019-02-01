/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* Ptr=head;
    if(!Ptr) return head;
    while(Ptr->next)
    {
        if(Ptr->val == Ptr->next->val) Ptr->next = Ptr->next->next;
        else Ptr = Ptr->next;
    }
    return head;
}
