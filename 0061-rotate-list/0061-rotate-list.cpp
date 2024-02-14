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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // TC = O(n)  SC = O(1)
        
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        
        ListNode* curr = head;
        int len = 1;
        
        while(curr->next !=  NULL)
        {
            len++;           //count the length of the ll
            curr = curr->next;
        }
        
        curr->next = head; //last node points to the head
        
        k = k%len;   //when k is more than the length of the ll
        k = len - k;
        
        while(k--)
        {
            curr = curr->next;
        }
            head = curr->next;
            curr->next = NULL;
        
        return head;
    }
};