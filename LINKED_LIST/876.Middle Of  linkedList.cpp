/*This is the optimal solution for this problem using two pointers */
/*slow and fast variation*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Fast pointer moves 2 steps and slow pointer moves 1 step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow; // Slow pointer is at the middle
    }
};
