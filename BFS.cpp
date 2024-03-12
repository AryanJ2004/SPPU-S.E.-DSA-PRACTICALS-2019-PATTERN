#include <iostream>
using namespace std;
void BFS(int vtx, int A[][6], int n){
    int q[20];
    int f = 0, r = 0;
    int visited[6] {0};
    cout << vtx << "->";
    visited[vtx] = 1;
    q[r] = vtx;
    while (f<=r){
        int u = q[f];
        q[f]++;
        for (int v=0; v<n; v++){  
            if (A[u][v] == 1 && visited[v] == 0){ 
                cout << v << "->";
                visited[v] = 1;
                q[r]=v;
                r++;
            }
        }
    }
    //cout << endl;
}
 
int main (){
 
    int A[6][6] = {{0,1,1,0,0,0},{1,0,0,1,0,0},{1,0,0,0,1,0},{0,1,0,0,0,1},{0,0,1,0,0,1},{0,0,0,1,1,0}};
 
    // cout << "Vertex: 1 -> " << flush;
     BFS(1, A, 6);
 
    //cout << "Vertex: 4 -> " << flush;
   // BFS(4, A, 8);
 
 
    return 0;
}
