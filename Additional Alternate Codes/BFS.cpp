#include <iostream>
using namespace std;

void BFS() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int A[n][n]; // Declare the adjacency matrix

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Enter Starting Vertex:" << endl;
    int vtx;
    cin >> vtx;

    int q[20]{0};
    int visited[n]{0}; 
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
    BFS();

    return 0;
}
