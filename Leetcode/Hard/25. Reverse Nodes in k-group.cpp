#include "precompiled/ListNode.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        
        int count = 0;
        // Count total nodes
        while(curr) {
            count++;
            curr = curr->next;
        }
        
        curr = head;
        while(count >= k) {
            curr = prev->next; // First node of current k group
            ListNode* next = curr->next; // Second node of current k group
            
            // Reverse k nodes
            for(int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            
            prev = curr;
            count -= k;
        }
        
        return dummy->next;
    }
};
