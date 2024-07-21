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
    ListNode* removeElements(ListNode* head, int val) {
        // Remove leading nodes with the target value
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        
        // If the list becomes empty
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* current = head;
        
        // Traverse the list and remove elements with the target value
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        
        return head;
    }
};
