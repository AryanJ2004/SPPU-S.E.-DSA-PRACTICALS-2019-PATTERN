#include <iostream>
using namespace std;

void BFS(int A[][6], int n) {
    cout << "Enter Starting Vertex:"<<endl;
    int vtx;
    cin>>vtx;
    int q[20]{0};
    int visited[7]{0}; 
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
    int A[6][6] = {{0,1,1,1,1,0},
                   {1,0,0,1,0,0},
                   {1,0,0,1,1,1},
                   {1,1,1,0,0,1},
                   {1,0,1,0,0,0},
                   {0,0,1,1,0,0}};
    BFS(A, 6);

    return 0;
}
