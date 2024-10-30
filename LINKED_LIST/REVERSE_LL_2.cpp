class Solution {
public:
    // Helper function to reverse a portion of the linked list
    ListNode* rev(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* nxt = nullptr;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if (prev == end) break; // Stop reversal at the end node
        }
        return prev;
    }
  
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head; // No need to reverse if head is null or left == right
        
        ListNode* front = nullptr; // Node just before the 'left' position
        ListNode* start = head;    // Starting node of the section to be reversed
        ListNode* end = head;      // Ending node of the section to be reversed
        ListNode* rear = nullptr;  // Node just after the 'right' position

        // Move `start` and `front` to correct positions
        for (int i = 1; i < left; ++i) {
            front = start;
            start = start->next;
        }

        // Move `end` to the correct position
        end = start;
        for (int i = left; i < right; ++i) {
            end = end->next;
        }
        
        rear = end->next; // Save the node just after 'end' position
        end->next = nullptr; // Disconnect the end of the section to be reversed

        // Reverse the segment
        ListNode* reversedHead = rev(start, end);

        // Connect the reversed segment back to the list
        if (front) {
            front->next = reversedHead;
        } else {
            head = reversedHead; // If `left` is 1, update head to the new start
        }

        // Connect the end of the reversed segment to the rear part
        start->next = rear;

        return head;
    }
};
