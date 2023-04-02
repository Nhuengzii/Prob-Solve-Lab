#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX_N = 1010;
const int MAX_M = 20010;
int n,m;
vector<pair<int,int>> adj[MAX_N];
vector<int> special[MAX_M];
int shortest[MAX_N];
int shortest_s[MAX_N];

int main()
{
    vector<int> ABCS(4, 0);
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> ABCS[0] >> ABCS[1] >> ABCS[2] >> ABCS[3];
        ABCS[0]--; ABCS[1]--;

        int a = ABCS[0], b = ABCS[1], c = ABCS[2], s = ABCS[3];

        adj[a].push_back({c,b});  
        adj[b].push_back({c,a});
        special[a].push_back(s);
        special[b].push_back(s);
    }
    for (int i=0; i<n; i++)
    {
        shortest[i] = -1;
        shortest_s[i] = -1;
    }
    
  vector<int> UVS(3, 0);
  queue<pair<int,int>> Q; 
  Q.push({0,0});
  shortest[0] = 0;
  shortest_s[0] = 0;
  while (!Q.empty())
  {
    UVS[0] = Q.front().second;
    UVS[2] = Q.front().first;
    Q.pop();
    if (UVS[0] == n-1)
    {
      if(shortest[UVS[0]] == -1) {
          cout << shortest_s[UVS[0]] << endl;
          return 0;
      }
      else if(shortest_s[UVS[0]] == -1) {
          cout << shortest[UVS[0]] << endl;
          return 0;
      }
      else if (shortest[UVS[0]] <= shortest_s[UVS[0]] ) {
          cout << shortest[UVS[0]] << endl;
          return 0;
      }
      else {
          cout << shortest_s[UVS[0]] << endl;
          return 0;
      }
    }
    for (int i=0; i<(int)adj[UVS[0]].size(); i++)
    {
      UVS[1] = adj[UVS[0]][i].second;
      if (UVS[2] == 1)
      {
        if (special[UVS[0]][i]) continue;
        else if (shortest_s[UVS[1]] == -1 || shortest_s[UVS[1]] > shortest_s[UVS[0]] + adj[UVS[0]][i].first)
        {
          Q.push({1,UVS[1]});
          shortest_s[UVS[1]] = shortest_s[UVS[0]] + adj[UVS[0]][i].first;
        }           
      }
      else
      {
        if (!special[UVS[0]][i] && (shortest[UVS[1]] == -1 || shortest[UVS[1]] > shortest[UVS[0]] + adj[UVS[0]][i].first)) 
        {
          Q.push({0 , UVS[1]});
          shortest[UVS[1]] = shortest[UVS[0]] +adj[UVS[0]][i].first;
        }
        else if (shortest_s[UVS[1]] == -1 || shortest_s[UVS[1]] > shortest[UVS[0]] + adj[UVS[0]][i].first)
        {
          Q.push({1 , UVS[1]});
          shortest_s[UVS[1]] = shortest[UVS[0]] + adj[UVS[0]][i].first;
        }
      }
    }
  }
  cout << -1 << endl;
}
