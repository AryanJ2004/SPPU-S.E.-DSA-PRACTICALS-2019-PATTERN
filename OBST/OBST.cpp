#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;

    node(int val = 0) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node* construct(int r[10][10], int i, int j) {
    if (i > j) {
        return nullptr;
    }

    int rootIndex = r[i][j];
    node* root = new node(rootIndex); // Create root with data as rootIndex
    root->left = construct(r, i, rootIndex - 1); // Construct left subtree
    root->right = construct(r, rootIndex + 1, j); // Construct right subtree
    return root;
}

int findOptimalRoot(int c[10][10], int i, int j) {
    int minCost = INT16_MAX;
    int bestRoot = -1;

    for (int k = i; k <= j; k++) {
        int currentCost = c[i][k - 1] + c[k + 1][j];
        if (currentCost < minCost) {
            minCost = currentCost;
            bestRoot = k;
        }
    }

    return bestRoot;
}

void optimalBST(int p[], int q[], int n, int c[10][10], int r[10][10]) {
    int w[10][10];

    // Initialize weights, costs, and roots
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            c[i][j] = 0;
            r[i][j] = 0;
            w[i][j] = 0;
        }
    }

    // Initialize base cases
    for (int i = 1; i <= n; i++) {
        w[i][i] = q[i - 1] + q[i] + p[i];
        c[i][i] = w[i][i];
        r[i][i] = i;
    }

    // Calculate optimal costs and roots for larger subtrees
    for (int step = 2; step <= n; step++) {
        for (int i = 1; i <= n - step + 1; i++) {
            int j = i + step - 1;

            w[i][j] = w[i][j - 1] + p[j] + q[j]; // Update weight

            int optimalRoot = findOptimalRoot(c, i, j); // Find optimal root
            c[i][j] = w[i][j] + c[i][optimalRoot - 1] + c[optimalRoot + 1][j]; // Update cost
            r[i][j] = optimalRoot; // Store root
        }
    }
}

// Display the optimal BST using in-order traversal
void display(node* root) {
    if (root != nullptr) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main() {
    int p[10], q[10];
    int n;
    char wrd[10][10];

    cout << "Enter the number of keys: ";
    cin >> n;

    cout << "Enter the keys: ";
    for (int i = 1; i <= n; i++) {
        cin >> wrd[i];
    }

    cout << "Enter the probabilities p[] for keys: ";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Enter the probabilities q[] for dummy keys: ";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    int c[10][10], r[10][10];

    optimalBST(p, q, n, c, r); // Compute optimal cost and root structure

    cout << "Optimal cost of BST: " << c[1][n] << endl; // Display optimal cost
    cout << "Root of OBST: " << r[1][n] << endl; // Display root of the BST

    node* root = construct(r, 1, n); // Construct BST from optimal structure

    cout << "In-order traversal of the constructed BST: ";
    display(root); // Display the constructed BST
    cout << endl;

    return 0;
}
