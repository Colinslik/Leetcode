/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* NEXT = node->next;
    node->val = NEXT->val;
    node->next = NEXT->next;
    free(NEXT);
}
