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
    ListNode* middleNode(ListNode* head) {
        
        
        // TC = O(n)
        // SC = O(1)
        
          ListNode* slow = head;
          ListNode* fast = head;

         while(fast != NULL && fast->next != NULL)
         { 
            slow = slow->next;
            fast = fast->next->next;

         }
         return slow;

        
/*        
<--------------------------------------------2nd approach------------------------------------------------>

		 to calculate the length of the linked list
        int size = 0;
        
		// taking a copy of head
        ListNode* temp = head;
        
		// traversing it to get the length of the linked list
        while (temp) {
            size++;
            temp = temp -> next;
        }
        
		// storing the length in another variable
        int original_size = size;
        
		// taking the half of the original length
        int half = size / 2;
        
        while (head) {
            if ((original_size % 2 == 0 && size == half) || (original_size % 2 != 0 && size - 1 == half)) {
                break;
            }
            head = head -> next;
            size--;
        }
        
        return head;
*/
    }
};