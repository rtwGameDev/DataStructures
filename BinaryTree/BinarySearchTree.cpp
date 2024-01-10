#include <iostream>
using namespace std;
class node {
public:
    int value;
    node *left, *right;
    node() {
        value = int();
        left = nullptr;
        right = nullptr;
    }
    node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};
class app {
private:
    node *head = nullptr;
    void insert(int value, node *&root, node *newItem) {
        if (root == nullptr) {
            root = newItem;
            return;
        }
        if (root->value <= value) insert(value, root->right, newItem);
        else insert(value, root->left, newItem);
    }
    void show(node *root) {
        if (root != nullptr) {
            cout << root->value << " ";
            show(root->left);
            show(root->right);
        }
    }

    void search(int value, node *root, bool &finded) {
        if (root != nullptr) {
            if (root->value == value) {
                finded = true;
                return;
            }
            if (value < root->value) search(value, root->left, finded);
            else search(value, root->right, finded);
        }
    }
    void delet1(int value, node *&root) {
        if (root != nullptr) {
            if (root->value == value) {
                maxLeft(root, root->left);
                return;
            }
            if (value < root->value) delet1(value, root->left);
            else delet1(value, root->right);
        }
    }
    void maxLeft(node *elementDeleted, node *&brainDelete) {
        if (brainDelete->right != nullptr) {
            maxLeft(elementDeleted, brainDelete->right);
        }
        else {
            elementDeleted->value = brainDelete->value;
            brainDelete = nullptr;
        }
    }
public:
    bool isEmpty() {
        if (head == nullptr) return true;
        return false;
    }
    void insert(int value) {
        node *newItem = new node(value);
        insert(value, head, newItem);
    }
    void show() {
        show(head);
    }
    void search(int value) {
        bool finded = false;
        search(value, head, finded);
        if (finded) cout << "Da tim thay gia tri can tim" << endl;
        else cout << "Khong tim thay gia tri nao" << endl;
    }
    void delet1(int value) {
        delet1(value, head);
    }
};
int main() {
    app myapp;
    // cout << myapp.isEmpty() << endl;
    // myapp.insert(5);
    // myapp.insert(2);
    // myapp.insert(7);
    // myapp.insert(1);
    // myapp.insert(9);
    // myapp.insert(3);
    // myapp.insert(8);
    // myapp.insert(4);
    // myapp.insert(6);
    // myapp.show();
    // cout << endl;
    // myapp.delet1(5);
    // myapp.show();
    return 0;
}
