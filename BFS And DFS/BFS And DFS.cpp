#include <iostream>
using namespace std;

void BFS(int A[][10], int n) {
    cout << "Enter Starting Vertex:" << endl;
    int vtx;
    cin >> vtx;

    int q[20]{0};
    int visited[10]{0}; // Assuming the maximum size for the matrix is 10
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

void DFS(int A[][10], int n) {
    int u;
    cout << "Enter starting vertex: ";
    cin >> u;

    int stk[100]{0};
    int top = -1;
    int visited[10]{0}; // Assuming the maximum size for the matrix is 10
    top++;
    stk[top] = u;
 
    while (top != -1) {
        u = stk[top];
        top--;
        if (visited[u] != 1){
            cout << u << ", ";
            visited[u] = 1;
 
            for (int v = n - 1; v >= 0; v--){
                if (A[u][v] == 1 && visited[v] == 0){
                    top++;
                    stk[top] = v;
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int A[10][10]; // Assuming the maximum size for the matrix is 10

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Choose traversal method:" << endl;
    cout << "1. BFS (Breadth First Search)" << endl;
    cout << "2. DFS (Depth First Search)" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Performing BFS traversal:" << endl;
            BFS(A, n);
            break;
        case 2:
            cout << "Performing DFS traversal:" << endl;
            DFS(A, n);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
