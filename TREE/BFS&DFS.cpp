BFS
{
vector<int> result;
        if (root == NULL) {
            return result; // return empty vector if tree is empty
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            result.push_back(current->data);
            
            if (current->left != NULL) {
                q.push(current->left);
            }
            
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        
        return result;
}


BFS2 VARIATION
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void levelOrderTraversalWithNewLines(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        while (levelSize > 0) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);

            levelSize--;
        }
        cout << endl;  // New line after each level
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Level Order Traversal with New Lines: \n";
    levelOrderTraversalWithNewLines(root);
    cout << endl;

    return 0;
}


BFS3VARIATION ZIGZAG
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void zigzagLevelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;
    currentLevel.push(root);

    while (!currentLevel.empty()) {
        Node* current = currentLevel.top();
        currentLevel.pop();

        // Visit current node
        cout << current->data << " ";

        // Push children to next level stack in the correct order
        if (leftToRight) {
            if (current->left) nextLevel.push(current->left);
            if (current->right) nextLevel.push(current->right);
        } else {
            if (current->right) nextLevel.push(current->right);
            if (current->left) nextLevel.push(current->left);
        }

        // If current level is finished, swap stacks and change direction
        if (currentLevel.empty()) {
            swap(currentLevel, nextLevel);
            leftToRight = !leftToRight;
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Zigzag Level Order Traversal: ";
    zigzagLevelOrderTraversal(root);
    cout << endl;

    return 0;
}



DFS
can be performed in inorder pre and post ordere both recursively and iteratively so we have iterative app over here
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void iterativePreorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " "; // Process the root

        // Push right child first so that left child is processed first
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder (Iterative): ";
    iterativePreorder(root);

    return 0;
}


2

        #include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void iterativeInorder(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the leftmost Node of the current Node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = s.top();
        s.pop();
        cout << current->data << " "; // Process the root

        // We have visited the node and its left subtree, now it's right subtree's turn
        current = current->right;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder (Iterative): ";
    iterativeInorder(root);

    return 0;
}

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void iterativePostorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }

    // s2 contains the postorder traversal in reverse order
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Postorder (Iterative): ";
    iterativePostorder(root);

    return 0;
}

