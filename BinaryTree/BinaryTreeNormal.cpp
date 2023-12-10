#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct Node {
    int n, count;
    Node *left, *right;
    Node() {}
    Node(int x) {
        n = x;
        count = 0;
        left = NULL;
        right = NULL;
    }
};
class BinaryTree {
private:
    Node *root;
    Node* insert (Node* &node, int x) {
        if (node == NULL) {
            Node* newNode = new Node(x);
            node = newNode;
            return newNode;
        }
        else {
            if (node->left == NULL or node->right == NULL) {
                node->count = node->count + 1;
                if (node->left == NULL and node->right == NULL) {
                    node->left = insert(node->left, x);
                }
                else node->right = insert(node->right, x);
            }
            else {
                int l = (node->left)->count;
                int r = (node->right)->count;
                node->count = node->count + 1;
                if (l <= r) {
                    insert(node->left, x);
                }
                else {
                    insert(node->right, x);
                }
            }
        }
        return node;
    }

    // inn cay nhi phan
    void preorderTraversal(Node* node) {
        if (node != NULL) {
            cout << node->n << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }
    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            cout << node->n << " ";
            inorderTraversal(node->right);
        }
    }
    void postorderTraversal(Node* node) {
        if (node != NULL) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->n << " ";
        }
    }
public:
    BinaryTree() {
        root = NULL;
    }
    void insert(int x) {
        insert(root, x);
    }
    // ------------------
    void preorderTraversal() {
        preorderTraversal(root);
    }
    void inorderTraversal() {
        inorderTraversal(root);
    }
    void postorderTraversal() {
        postorderTraversal(root);
    }
    // -----------------------------------------------------------------------------------------challening
    void inorder() {
        stack <Node*> arr;
        Node* curr = root;
        while (curr != NULL or !arr.empty()) {
            while (curr != NULL) {
                arr.push(curr);
                curr = curr->left;
            }
            curr = arr.top();
            cout << curr->n << " ";
            arr.pop();
            curr = curr->right;
        }
    }
    void postorder() {
        stack <Node*> arr;
        stack <int> dd;
        Node *currNode = root;
        while (currNode != NULL or !arr.empty()) {
            while (currNode != NULL) {
                arr.push(currNode);
                dd.push(0);
                currNode = currNode->left;
            }

            Node *temp = arr.top();
            cout << temp->n << " ";
            arr.pop(); dd.pop();
            if (dd.top() == 0) {
                dd.pop(); dd.push(1);
                currNode = arr.top()->right;
            }
            else {
                while (!dd.empty() and dd.top() == 1) {
                    cout << arr.top()->n << " ";
                    dd.pop(); arr.pop();
                    if (dd.empty()) {
                        currNode = NULL;
                        break;
                    };
                }
                if (!dd.empty()) {
                    currNode = arr.top()->right;
                    dd.pop(); dd.push(1);
                }    
            }
        }
    }
    void NewPostOrderTraversal () {
        stack <Node*> arr;
        stack <int> result;
        arr.push(root);
        while (!arr.empty()) {
            Node* curr = arr.top();
            result.push(curr->n);
            arr.pop();

            if (curr->left != NULL) {  
                arr.push(curr->left);
            }
            if (curr->right != NULL) {
                arr.push(curr->right);
            } 

        }
        while (!result.empty()) {
            cout << result.top() << " ";
            result.pop();
        }
    }
    void preorder() {
        stack <Node*> arr;
        Node* curr = root;
        while (curr != NULL or !arr.empty()) {
            while (curr != NULL) {
                cout << curr->n << " ";
                arr.push(curr);
                curr = curr->left;
            }
            curr = arr.top();
            arr.pop();
            curr = curr->right;
        }
    }
// -----------------------------------------------------------------------------------------challening
};
int main() {
    BinaryTree tree;
    return 0;
}