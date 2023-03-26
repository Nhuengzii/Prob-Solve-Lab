#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef vector<vector<int>> yay;
typedef pair<int, int> yee;
#define mk(a1, a2) make_pair(a1, a2)

int bfs(yay &data, yay &visit, int a, int b, int x, int y){
  vector<int> num_pass(data.size());
  queue<yee> q;
  yay layers(data.size(), vector<int>(data[0].size()));
  yay seens(data.size());
  q.push(mk(a, b));
  seens[a][b] = 1;
  yee c;
  int u, v;
  while(!q.empty()){
    c = q.front();
    q.pop();
    u = c.first;
    v = c.second;
    if(u - 1 >= 0 && seens[u -1][v] == 0){
      seens[u-1][v] = 1;
      q.push(mk(u, v));
    }
    if(u + 1 < data.size() && seens[u + 1][v] == 0){
      seens[u+1][v] = 1;
      q.push(mk(u+1,v));
    }
    if(v - 1 >= 0 && seens[u][v-1] == 0){
      seens[u][v -1] = 1;
      q.push(mk(u, v-1));
    }
    if(v + 1 < data[0].size() && seens[u][v+1] == 0){
      seens[u][v + 1] = 1;
      q.push(mk(u, v+1));
    }
  }
  return -1;
}


int main(void){
  int R, C, A, B, X, Y;
  cin >> R >> C >> A >> B >> X >> Y;
  --A;
  --B;
  --X;
  --Y;
  yay data(R);
  int temp;
  yay visit(R);
  for(int i = 0 ; i < R; i++){
    for(int k = 0; k < C; k++){
      cin >> temp;
      data[i].push_back(temp);
      visit[i].push_back(0);
    }
  }
  map<int, bool> pass;
  pass[data[A][B]] = true;
}
