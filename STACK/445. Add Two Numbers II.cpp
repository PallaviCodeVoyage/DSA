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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse the input lists
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* result = nullptr;
        int carry = 0;
        
        // Traverse both lists and add corresponding digits
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            sum %= 10;
            
            // Insert the sum as a new node in the result list
            ListNode* newNode = new ListNode(sum);
            newNode->next = result;
            result = newNode;
        }
        
        return result;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
/****without reversing**/
#include <stack>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> stack1;
        std::stack<int> stack2;
        
        // Push all digits of l1 onto stack1
        while (l1) {
            stack1.push(l1->val);
            l1 = l1->next;
        }
        
        // Push all digits of l2 onto stack2
        while (l2) {
            stack2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* result = nullptr;
        int carry = 0;
        
        // Process both stacks
        while (!stack1.empty() || !stack2.empty() || carry) {
            int sum = carry;
            
            if (!stack1.empty()) {
                sum += stack1.top();
                stack1.pop();
            }
            
            if (!stack2.empty()) {
                sum += stack2.top();
                stack2.pop();
            }
            
            carry = sum / 10;
            sum %= 10;
            
            // Create a new node for the current digit and add it to the result list
            ListNode* newNode = new ListNode(sum);
            newNode->next = result;
            result = newNode;
        }
        
        return result;
    }
};

