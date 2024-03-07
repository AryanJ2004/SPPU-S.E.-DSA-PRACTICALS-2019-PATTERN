#include <iostream>
#include <climits>

using namespace std;

struct sparsemat {
    int row, col, value;
};

int main() {
    int n, min, s, row, col, total = 0, ne = 1;

    cout << "Enter the number of nodes: ";
    cin >> n;

    sparsemat *mat = nullptr;
    int count = 0;
    int visit[n] = {0};

    cout << "\nEnter the cost matrix: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            cin >> cost;
            if (cost != 0) {
                sparsemat *temp = new sparsemat[count + 1];
                for (int k = 0; k < count; k++) {
                    temp[k] = mat[k];
                }
                temp[count++] = {i, j, cost};
                delete[] mat;
                mat = temp;
            }
        }
    }

    cout << "\nGraph Edges Are:" << endl;
    for (int i = 0; i < count; i++) {
        cout << mat[i].row + 1 << " to " << mat[i].col + 1 << ": " << mat[i].value << endl;
    }

    cout << "Enter Starting Vertex: ";
    cin >> s;

    if (s > 0 && s <= n) {
        visit[s - 1] = 1;
    } else {
        visit[0] = 1;
    }

    while (ne < n) {
        min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (visit[i] == 1) {
                for (int k = 0; k < count; k++) {
                    if (mat[k].row == i && visit[mat[k].col] == 0 && mat[k].value < min) {
                        min = mat[k].value;
                        row = i;
                        col = mat[k].col;
                    }
                }
            }
        }

        if (row != col) {
            ne++;
            cout << "\nEdge=" << row + 1 << " to " << col + 1 << "=" << min;
            visit[col] = 1;
            total += min;
        }
    }

    delete[] mat;

    cout << "\nMinimum Cost=" << total << "\n";
    return 0;
}
