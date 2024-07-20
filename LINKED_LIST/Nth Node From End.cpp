/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        
        Node*h=head;
        int c=0;
        while(h!=nullptr)
        {
            c++;
            h=h->next;
            
        }//c=9
        if(k>c)
        {
            return -1;
        }
        h=head;
        int i=0;
        while(i<(c-k))
        {
            h=h->next;
            i++;
        }
        return h->data;
        // Your code here
    }
};
/**********optimised*******/

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    int getKthFromLast(Node* head, int k) {
        Node* first = head;
        Node* second = head;

        // Move the first pointer k steps ahead
        for (int i = 0; i < k; i++) {
            if (first == nullptr) {
                // k is larger than the number of nodes
                return -1;
            }
            first = first->next;
        }

        // Move both pointers until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // second is now at the k-th node from the end
        if (second != nullptr) {
            return second->data;
        } else {
            return -1;
        }
    }
};
