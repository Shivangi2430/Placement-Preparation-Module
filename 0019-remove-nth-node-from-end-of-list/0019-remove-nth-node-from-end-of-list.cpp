/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        //TC = O(n)  SC = O(1)
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        for(int i = 1; i <= n; ++i)
            fast = fast->next;
        
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return dummy->next;
                  
   }
};       
        
        
        /* TC = O(2n)  SC = O(1)
        
         if(head==NULL){
            return head;
        }
        ListNode* ptr=head;
        int count = 0;
        while(ptr){
            count++;
            ptr=ptr->next;
        }
        if(count==n)
        {
            head=head->next;
            return head;
        }
        ptr=head;
        n=count-n-1;
        count=0;
        
        while(ptr){
            if(count==n){
                ptr->next=ptr->next->next;
            }
            count++;
            ptr=ptr->next;
        }
        return head;
        */
  