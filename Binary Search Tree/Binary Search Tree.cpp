#include <iostream>
using namespace std;

// Class representing a node in a Binary Search Tree
class node {
public:
    int data; // Data contained in the node
    node *left, *right, *root; // Left and right children, and root node

    node() {
        root = nullptr; // Initialize root to null
    }

    // Functions for BST
    node* create(node* root); // Create a BST
    void insert(node*& root, node* temp); // Insert into BST
    void recdispvlr(node* root); // Recursive pre-order
    void recdisplrv(node* root); // Recursive post-order
    node* minElement(node* root); // Find minimum element
    node* maxElement(node* root); // Find maximum element
    void mirror(node* root); // Mirror the BST
    int height(node* root); // Calculate height of BST
        void deleteNode(node*& root, int data); // Delete a node in the BST
    node* search(node* root, int data); // Search for a node in the BST

};

// Function to create a BST by inserting nodes one by one
node* node::create(node* root) {
    node* temp;
    char c;
    do {
        temp = new node; // Create a new node
        temp->left = nullptr; // Initialize left and right children
        temp->right = nullptr;

        cout << "\nEnter the data: "; // Prompt for data
        cin >> temp->data;

        if (root == nullptr) { // If root is null, set temp as root
            root = temp;
        } else { // Otherwise, insert into the BST
            insert(root, temp);
        }

        cout << "\n\nWant to enter more nodes? (y/n): "; // Ask if user wants to continue
        cin >> c;
    } while (c == 'y' || c == 'Y'); // Continue if the answer is 'y' or 'Y'
    return root;
}

// Function to insert a node into the BST
void node::insert(node*& root, node* temp) {
    if (temp->data < root->data) { // If data is smaller, insert to the left
        if (root->left == nullptr) {
            root->left = temp;
        } else {
            insert(root->left, temp);
        }
    } else { // If data is larger or equal, insert to the right
        if (root->right == nullptr) {
            root->right = temp;
        } else {
            insert(root->right, temp);
        }
    }
}

// Recursive pre-order traversal (Node-Left-Right)
void node::recdispvlr(node* root) {
    if (root) {
        cout << root->data << "\t"; // Visit the current node
        recdispvlr(root->left); // Recurse to the left
        recdispvlr(root->right); // Recurse to the right
    }
}

// Recursive post-order traversal (Left-Right-Node)
void node::recdisplrv(node* root) {
    if (root) {
        recdisplrv(root->left); // Recurse to the left
        recdisplrv(root->right); // Recurse to the right
        cout << root->data << "\t"; // Visit the current node
    }
}

// Function to find the minimum element in a BST
node* node::minElement(node* root) {
    while (root->left != nullptr) { // Keep going left to find the minimum
        root = root->left;
    }
    return root; // Return the minimum node
}

// Function to find the maximum element in a BST
node* node::maxElement(node* root) {
    while (root->right != nullptr) { // Keep going right to find the maximum
        root = root->right;
    }
    return root; // Return the maximum node
}

// Function to create a mirror image of the BST
void node::mirror(node* root) {
    if (root == nullptr) {
        return;
    }

    // Swap left and right children recursively
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left); // Mirror the left subtree
    mirror(root->right); // Mirror the right subtree
}

// Function to calculate the height of a BST
int node::height(node* root) {
    if (root == nullptr) {
        return 0; // Base case: empty tree has height 0
    }

    // Height is 1 + the maximum of left and right subtree heights
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void node::deleteNode(node*& root, int value) {
    if (root == nullptr) { // If root is null, nothing to delete
        return;
    }

    if (value < root->data) { // If value is smaller, go left
        deleteNode(root->left, value); // Recursive deletion
    } else if (value > root->data) { // If value is larger, go right
        deleteNode(root->right, value); // Recursive deletion
    } else { // Found the node to be deleted
        if (root->left == nullptr) { // If there's no left child
            node* temp = root->right; // Get the right child
            delete root; // Delete the current node
            root = temp; // Replace with the right child
        } else if (root->right == nullptr) { // If there's no right child
            node* temp = root->left; // Get the left child
            delete root; // Delete the current node
            root = temp; // Replace with the left child
        } else { // If the node has two children
            node* successor = minElement(root->right); // Find the in-order successor
            root->data = successor->data; // Replace with the successor's data
            deleteNode(root->right, successor->data); // Delete the successor
        }
    }
}

node* node::search(node* root, int value) {
    if (root == nullptr || root->data == value) { // If found or null
        return root; // Return the found node or nullptr
    }

    if (value < root->data) { // If value is smaller, go left
        return search(root->left, value); // Recursive search
    } else { // If value is larger, go right
        return search(root->right, value); // Recursive search
    }
}

int main() {
    int ch;
    char ans;
    node p1;

    do {
        cout << "1: Create binary search tree\n2: Display (Pre-order or Post-order)\n3: Find Minimum\n4: Find Maximum\n5: Mirror BST\n6: Get Height of BST\n7: Delete a Node\n8: Search for a Node\n9: Exit\n";
        cin >> ch; // Read user input for operation

        switch (ch) {
        case 1:
            p1.root = p1.create(p1.root); // Create a new BST
            break;
        case 2:
            cout << "1: Pre-order\n2: Post-order\n"; // Ask for choice of traversal
            cin >> ch;
            if (ch == 1) {
                cout << "Pre-order traversal:\n";
                p1.recdispvlr(p1.root); // Display pre-order traversal
            } else if (ch == 2) {
                cout << "Post-order traversal:\n";
                p1.recdisplrv(p1.root); // Display post-order traversal
            } else {
                cout << "Invalid choice.\n";
            }
            cout << "\n";
            break;
        case 3:
            if (p1.root != nullptr) { // Find the minimum element
                cout << "Minimum element is: " << p1.minElement(p1.root)->data << "\n";
            } else {
                cout << "Tree is empty.\n";
            }
            break;
        case 4:
            if (p1.root != nullptr) { // Find the maximum element
                cout << "Maximum element is: " << p1.maxElement(p1.root)->data << "\n";
            } else {
                cout << "Tree is empty.\n";
            }
            break;
        case 5:
            if (p1.root != nullptr) {
                p1.mirror(p1.root); // Mirror the BST
                cout << "BST mirrored successfully.\n";
            } else {
                cout << "Tree is empty.\n";
            }
            break;
        case 6:
            if (p1.root != nullptr) { // Get the height of the BST
                cout << "Height of the BST is: " << p1.height(p1.root) << "\n";
            } else {
                cout << "Tree is empty.\n";
            }
            break;
       case 7:
    if (p1.root != nullptr) { // Check if the BST is not empty
        cout << "Enter the value to delete: "; // Ask for value to delete
        int delValue;
        cin >> delValue;

        node* foundNode = p1.search(p1.root, delValue); // Search for the node

        if (foundNode != nullptr) { // If the node is found
            p1.deleteNode(p1.root, delValue); // Delete the specified node
            cout << "Node deleted successfully.\n"; // Confirm deletion
        } else {
            cout << "Node with value " << delValue << " not found.\n"; // Inform user
        }
    } else {
        cout << "Tree is empty.\n"; // Inform user if the tree is empty
    }
    break;

        case 8:
            if (p1.root != nullptr) { // Search for a node in the BST
                cout << "Enter the value to search: ";
                int searchValue;
                cin >> searchValue; 
                node* found = p1.search(p1.root, searchValue); 
                if (found) {
                    cout << "Node found: " << found->data << "\n";
                } else {
                    cout << "Node not found.\n"; 
                }
            } else {
                cout << "Tree is empty.\n"; 
            }
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break; // Ensure each case ends with a break
        }

        cout << "\nWant to continue operations? (y/n): "; // Prompt for continuation
        cin >> ans;
    } while (ans == 'y' || ans == 'Y'); // Continue if the answer is 'y' or 'Y'

    return 0; // Return from main
}
