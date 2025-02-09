#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the nodes by value
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // Push the head node of each list into the heap
        for (auto node : lists) {
            if (node) {
                minHeap.push(node);
            }
        }
        
        // Dummy node to help with building the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // Process the heap
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            current->next = smallest;
            current = current->next;
            
            // If there is a next node, add it to the heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy->next;
    }
};
