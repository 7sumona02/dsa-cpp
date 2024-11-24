#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl; // New level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->val << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// root, left, right
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// left, root, right
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// left, right, root
void postorder(Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void buildFromLevelOrder(Node*& root) {
    queue<Node*> q;

    int data;
    cout << "Enter data for root: ";
    cin >> data;
    root = new Node(data);

    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter left node data: ";
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter right node data: ";
        cin >> rightData;

        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

// Function to count total number of nodes
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count number of leaf nodes
int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    Node* root = NULL;
    buildFromLevelOrder(root);

    cout << "Level order traversal:" << endl;
    levelOrderTraversal(root);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    // Count total nodes and leaf nodes
    cout << "Total number of nodes: " << countNodes(root) << endl;
    cout << "Total number of leaf nodes: " << countLeafNodes(root) << endl;

    return 0;
}