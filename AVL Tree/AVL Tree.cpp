#include <iostream>
using namespace std;

class node {
public:
    int data; // Node's value
    int bf; // Balance factor
    node* left; // Pointer to left child
    node* right; // Pointer to right child
    node* root; // Root node

    node() {
        root = NULL; // Initialize root to NULL
    }

    node* insert(int data, int* c_flag); // Insert function
    node* create(node* root, int data, int* c_flag); // Create node function
    void display(node* root); // Display function
};

node* node::insert(int data, int* c_flag) {
    root = create(root, data, c_flag); 
    return root;
}

node* node::create(node* root, int data, int* c_flag) {
    node* t1, *t2;
    if (root == NULL) {
        root = new node; // Create new node
        root->data = data;
        root->left = NULL; 
        root->right = NULL;
        root->bf = 0; 
        *c_flag = 1; // Tree grew
        return root;
    }

    if (data < root->data) {
        root->left = create(root->left, data, c_flag); // Insert into left 
        if (*c_flag == 1) { // If height increased
            switch (root->bf) {
                case -1:
                    root->bf = 0; // Now balanced
                    break;
                case 0:
                    root->bf = 1; // Left-heavy
                    break;
                case 1: // Requires LL/LR Rotation
                    t1 = root->left;
                    if (t1->bf == 1) { // LL Rotation
                        std::cout << "\nLL rotation";
                        root->left = t1->right;
                        t1->right = root;
                        root->bf = 0;
                        root = t1; // Update root
                    } else { // LR Rotation
                        std::cout << "\nLR Rotation";
                        t2 = t1->right;
                        t1->right = t2->left;
                        t2->left = t1;
                        root->left = t2->right;
                        t2->right = root;
                        t1->bf = (t2->bf == -1) ? 1 : 0;
                        root->bf = (t2->bf == 1) ? -1 : 0;
                        root = t2; // Update root
                    }
                    *c_flag = 0; // Now balanced
                    break;
            }
        }
    } else { // data > root->data
        root->right = create(root->right, data, c_flag); // Insert into right 
        if (*c_flag == 1) { // If height increased
            switch (root->bf) {
                case 1:
                    root->bf = 0; // Now balanced
                    break;
                case 0:
                    root->bf = -1; // Right-heavy
                    break;
                case -1: // Requires RR/RL Rotation
                    t1 = root->right;
                    if (t1->bf == -1) { // RR Rotation
                        std::cout << "\nRR rotation";
                        root->right = t1->left;
                        t1->left = root;
                        root->bf = 0;
                        root = t1; // Update root
                    } else { // RL Rotation
                        std::cout << "\nRL Rotation";
                        t2 = t1->left;
                        t1->left = t2->right;
                        t2->right = t1;
                        root->right = t2->left;
                        t2->left = root;
                        t1->bf = (t2->bf == 1) ? -1 : 0;
                        root->bf = (t2->bf == -1) ? 1 : 0;
                        root = t2; // Update root
                    }
                    *c_flag = 0; // Now balanced
                    break;
            }
        }
    }
    return root; 
}

void node::display(node* root) {
    if (root != NULL) { // In-order traversal
        display(root->left);
        std::cout << root->data << "\t"; 
        display(root->right);
    }
}

int main() {
    node t; 
    node* root = nullptr; // Initialize root
    int data; 
    char ch;
    int c_flag = 0; // Initialize c_flag

    do {
        std::cout << "\nEnter data: ";
        std::cin >> data;
 
        root = t.insert(data, &c_flag); // Insert into tree
 
        std::cout << "\n\nAVL TREE:";
        t.display(root); // Display the AVL tree
 
        std::cout << "\n\nDo you want to continue? ";
        std::cin >> ch;
    } while (ch == 'y' || ch == 'Y'); 

    return 0; // Correct return for `main`
}
