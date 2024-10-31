/*BRUTE FORCE APPROACH*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Step 1: Extract values from the linked list into an array
        std::vector<int> values;
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }
        
        // Step 2: Sort the array
        std::sort(values.begin(), values.end());
        
        // Step 3: Rebuild the linked list from the sorted values
        current = head;
        for (int val : values) {
            current->val = val;
            current = current->next;
        }
        
        return head;
    }
};


/*OPTIMISED SAME O(N LOG N)BUT SPACE COMP IS O(1) USING MERGE SORT*/
class Solution {
public:
    ListNode* solve(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* d = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                d->next = l1;
                l1 = l1->next;
            } else {
                d->next = l2;
                l2 = l2->next;
            }
            d = d->next;
        }
        
        // Attach the remaining nodes
        d->next = (l1) ? l1 : l2;
        
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Step 1: Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Break the list into two halves
        prev->next = nullptr;
        
        // Step 2: Sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        // Step 3: Merge the sorted halves
        return solve(left, right);
    }
};
