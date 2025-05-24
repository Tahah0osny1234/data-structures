#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* remove(Node* node, int val) {
        if (!node) return node;
        if (val < node->data) node->left = remove(node->left, val);
        else if (val > node->data) node->right = remove(node->right, val);
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void display(Node* node, int depth = 0) {
        if (!node) return;
        display(node->right, depth + 1);
        for (int i = 0; i < depth; i++) cout << "    ";
        cout << node->data << endl;
        display(node->left, depth + 1);
    }
};

int main() {
    BST tree;
    Node* root = nullptr;

    root = tree.insert(root, 40);
    root = tree.insert(root, 20);
    root = tree.insert(root, 66);
    root = tree.insert(root, 1);
    root = tree.insert(root, 32);
    root = tree.insert(root, 51);
    root = tree.insert(root, 78);

    cout << "In-order: ";
    tree.inorder(root);
    cout << endl;

    cout << "Pre-order: ";
    tree.preorder(root);
    cout << endl;

    cout << "Post-order: ";
    tree.postorder(root);
    cout << endl;

    root = tree.remove(root, 66);

    cout << "In-order after removing 66: ";
    tree.inorder(root);
    cout << endl;

    cout << "Tree structure:\n";
    tree.display(root);

    return 0;
}
