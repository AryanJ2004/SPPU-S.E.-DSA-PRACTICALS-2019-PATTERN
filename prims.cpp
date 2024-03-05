#include <iostream>
#include <string>
using namespace std;
int
main ()
{
  int n, i, j, cost[10][10], min, visit[10], u, v, total = 0, ne = 1, pos;
  int s;
  cout << "Enter Number Of Nodes:" << endl;
  cin >> n;
  for (i = 0; i <= n; i++)
	{
	  visit[i] = 0;
	}
  cout << "Weighted Graph is==" << endl;
  for (i = 0; i <= n; i++)
	{
	  for (j = 0; j <= n; j++)
		{
		  cin >> cost[i][j];
		  if (cost[i][j] == 0)
			cost[i][j] = 999;
		}
	}

  cout << "Enter The Source:" << endl;
  cin >> s;
  visit[s] = 1;

  while (ne <= n)
	{
	  min = 999;
	  for (i = 1; i <= n; i++)
		{
		  if (visit[i] == 1)
			{
			  for (j = 1; j <= n; j++)
				{
				  if (cost[i][j] < min && visit[j] == 0)
					{
					  min = cost[i][j];
					  u = i;
					  v = j;
					}
				}
			}
		}
	  if (u != v)
		{
		  ne++;
		  cout << "\negde==" << u << "to" << v << "==" << min;
		  visit[u] = visit[v] = 1;
		  total += min;
		}
	  cout << "\nMinimum Cost=" << total;
	}
  return 0;
}

