#include <iostream>
using namespace std;

const int MAX_SIZE = 10; // Maximum size for the matrix

void BFS(int A[][MAX_SIZE], int n) {
    cout << "Enter Starting Vertex:" << endl;
    int vtx;
    cin >> vtx;
    int q[20]{0};
    int visited[MAX_SIZE]{0}; 
    int f = 0, r = -1; 
    q[++r] = vtx;
    visited[vtx] = 1; 
    while (f <= r) {
        int u = q[f++]; 

        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (A[u][v] == 1 && visited[v] == 0) {
                q[++r] = v;
                visited[v] = 1;
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Matrix size exceeds maximum limit." << endl;
        return 1; // Exit with error
    }

    int A[MAX_SIZE][MAX_SIZE];

    // Input adjacency matrix from the user
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    BFS(A, n);

    return 0;
}
