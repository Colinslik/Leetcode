/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* Ptr_right = head;
    struct ListNode* Ptr_left = head;
    struct ListNode* Ptr_temp;
    int count = 0,half,i;
    bool isOdd;
    if(Ptr_right)
    {
      count++;
      for(;Ptr_right->next!=NULL;Ptr_right=Ptr_right->next)
      {
        count++;
      }
    }
    else return 1;
    
    if(count == 1) return 1;
    else
    {
      isOdd = count%2;
      half = (isOdd)?(count/2)+1:count/2;
      
      Ptr_right = Ptr_left->next;
      Ptr_left->next = NULL;
      for(i = 1;i<half;i++) 
      {
          Ptr_temp = Ptr_left;
          Ptr_left = Ptr_right;
          Ptr_right=Ptr_right->next;
          Ptr_left->next = Ptr_temp;
      }
      if(isOdd) Ptr_left=Ptr_left->next;
      
      for(;Ptr_right!=NULL;Ptr_right=Ptr_right->next)
      {
          if(Ptr_left->val != Ptr_right->val) return 0;
          else Ptr_left = Ptr_left->next;
      }
    }
    return 1;
}
