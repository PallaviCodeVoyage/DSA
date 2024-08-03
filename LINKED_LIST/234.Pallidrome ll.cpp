/*class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;  // Edge case: Empty list

        // Step 1: Push all nodes onto the stack
        stack<ListNode*> st;
        ListNode* h = head;
        while (h != nullptr) {
            st.push(h);
            h = h->next;
        }

        // Step 2: Create the reversed linked list
        ListNode* head2 = new ListNode();  // Dummy node for reversed list
        ListNode* current = head2;  // Pointer to construct the reversed list
        while (!st.empty()) {
            current->next = st.top();
            st.pop();
            current = current->next;
        }
        current->next = nullptr;  // Ensure the last node's next is nullptr

        // Step 3: Compare the original linked list with the reversed linked list
        ListNode* h2 = head2->next;  // Skip the dummy node
        while (head != nullptr && h2 != nullptr) {
            if (head->val != h2->val) {
                delete head2;  // Free the dummy node
                return false;
            }
            head = head->next;
            h2 = h2->next;
        }

        delete head2;  // Free the dummy node
        return true;
    }
};
*/
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;

        // Create a stack to store the nodes
        stack<int> st;
        ListNode* h = head;

        // Push all elements of the list to the stack
        while (h != nullptr) {
            st.push(h->val);
            h = h->next;
        }

        // Compare elements of the stack with the list
        h = head;
        while (h != nullptr) {
            if (h->val != st.top()) {
                return false;
            }
            st.pop();
            h = h->next;
        }

        return true;
    }
};
*/

class Solution {
public:
   ListNode* find(ListNode* node) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = find(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }


    bool isPalindrome(ListNode* head)
    {
        
        ListNode*n;
        ListNode*a;
            ListNode*s=head,*f=head;
            while(f->next!=nullptr&&f->next->next!=nullptr)
            {
                f=f->next->next;
                s=s->next;
            }
            if(f->next!=nullptr)
            {
                n=s->next;
                s->next=nullptr;
                s=head;
                a=find(n);
                while(s!=nullptr&&a!=nullptr)
                {
                    if(s->val!=a->val)
                    {
                        return false;
                    }
                    s=s->next;
                    a=a->next;
                }
                return true;

            }
            else
            {
                n=s->next;
                s->next=nullptr;
                s=head;
                a=find(n);
                while(a!=nullptr)
                {
                    if(s->val!=a->val)
                    {
                        return false;
                    }
                    a=a->next;
                    s=s->next;
                }
                return true;
            }
            return true;

    }
};/*better way to use 2 pointer*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;
        
        // Find the middle of the linked list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        // Compare the first half with the reversed second half
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};
