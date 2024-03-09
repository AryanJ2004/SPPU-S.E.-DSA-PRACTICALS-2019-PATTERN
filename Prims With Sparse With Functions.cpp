#include <iostream>
#include <climits>

using namespace std;

struct matrix {
    int row, col, value;
};

class primsalgo {
private:
    int n, min, s, row, col, total = 0, ne = 1;
    matrix *mat = nullptr;
    int *visit = nullptr;
    int count = 0;
public:
    void insert() {
        cout << "Enter the number of nodes: ";
        cin >> n;

        visit = new int[n];
        fill(visit, visit + n, 0);

        cout << "\nEnter the cost matrix: ";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cost;
                cin >> cost;
                if (cost != 0) {
                    matrix *temp = new matrix[count + 1];
                    for (int k = 0; k < count; k++) {
                        temp[k] = mat[k];
                    }
                    temp[count++] = {i, j, cost};
                    delete[] mat;
                    mat = temp;
                }
            }
        }
    }

    void Display() {
        cout << "\nGraph Edges Are:" << endl;
        for (int i = 0; i < count; i++) {
            cout << mat[i].row + 1 << " to " << mat[i].col + 1 << ": " << mat[i].value << endl;
        }
    }

    void Minpath() {
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
        delete[] visit;

        cout << "\nMinimum Cost=" << total << "\n";
    }
};

int main() {
    primsalgo obj;
    int n;
    do
    {
        cout<<"\n\n==============MENU================="<<endl;
        cout<<"1.Enter The Values Of Adjacency Matrix Of Graph"<<endl;
        cout<<"2.Display The Edges Of Graphs"<<endl;
        cout<<"3.Find The Minimum Spanning Tree"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"\nEnter Choice:";
        cin>>n;
        switch(n)
        {
            case 1:
            obj.insert();
            break;
            case 2:
            obj.Display();
            break;
            case 3:
            obj.Minpath();
            break;
            case 4:
            break;
        }
    } while (n!=4);
    
    return 0;
}
