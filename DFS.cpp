#include <iostream>
using namespace std;

void dfs_nonrec() {
    int n, u;
    cout << "Enter the size of the adjacency matrix: ";
    cin >> n;

    int A[n + 1][n + 1];
    cout << "Enter the adjacency matrix values:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "Enter row " << i << ": ";
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
        }
    }
    cout << "Enter starting vertex: ";
    cin >> u;

    int stk[100]{0};
    int top = -1;
    int visited[n + 1] {0};
    top++;
    stk[top] = u;
 
    while (top!=-1) {
        u = stk[top];
        top--;
        if (visited[u] != 1){
            cout << u << ", ";
            visited[u] = 1;
 
            for (int v = n; v >= 1; v--){
                if (A[u][v] == 1 && visited[v] == 0){
                    top++;
                    stk[top] = v;
                }
            }
        }
    }
}

int main (){
    cout << "Performing DFS traversal:" << endl;
    dfs_nonrec();
   
    return 0;
}
