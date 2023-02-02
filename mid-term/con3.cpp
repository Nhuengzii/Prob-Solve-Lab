#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef vector<vector<int>> graph;


int bfs(map<int, map<int, bool>> &data, int s, int tar){
  queue<int> q;
  vector<bool> seens(data.size());
  vector<int> layers(data.size());
  q.push(s);
  layers[s] = 0;
  seens[s] = true;
  int c;
  int t;
  while(!q.empty()){
    c = q.front();
    q.pop();
    for(auto i: data[c]){
      t = i.first;
      if(seens[t]){
        continue;
      }
      if(t == tar){
        return layers[c] + 1;
      }
      else{
        seens[t] = true;
        q.push(t);
        layers[t] = layers[c] + 1;
      }
    }
  }
  return -1;
}


int main(void){
  int R, C, A, B, X, Y;
  cin >> R >> C >> A >> B >>X >>Y;
  graph board(R);
  int t1;
  map<int, map<int, bool>> all_con;
  for(int i = 0; i < R; i++){
    for(int k = 0; k < C; k++){
      cin >> t1;
      board[i].push_back(t1);
      if(all_con.find(t1) == all_con.end()){
        all_con[t1] = map<int, bool>();
      }
      if(i == 0 && k > 0){
        if(all_con.find(board[i][k-1]) == all_con.end()){
          all_con[board[i][k-1]] = map<int, bool>();
        }
        if(board[i][k-1] != t1){
          all_con[t1][board[i][k-1]] = true;
          all_con[board[i][k-1]][t1] = true;
        }
      }
      if(i > 0 && k == 0){
        if(all_con.find(board[i-1][k]) == all_con.end()){
          all_con[board[i-1][k]] = map<int, bool>();
        }
        if(board[i - 1][k] != t1){
          all_con[t1][board[i-1][k]] = true;
          all_con[board[i-1][k]][t1] = true;
        }
        
      }
      if(i > 0 && k > 0 ){
        if(all_con.find(board[i-1][k]) == all_con.end()){
          all_con[board[i-1][k]] = map<int, bool>();
        }
        if(all_con.find(board[i][k-1]) == all_con.end()){
          all_con[board[i][k-1]] = map<int, bool>();
        }
        if(board[i - 1][k] != t1){
          all_con[t1][board[i-1][k]] = true;
          all_con[board[i-1][k]][t1] = true;
        }
        if(board[i][k-1] != t1){
          all_con[t1][board[i][k-1]] = true;
          all_con[board[i][k-1]][t1] = true;
        }
      }
    }
  }
  --A;
  --B;
  --X;
  --Y;
  int start = board[A][B];
  int tartget = board[X][Y];
  int res = bfs(all_con, start, tartget);
  if(res == -1){
    cout << 0 << endl;
    return 0;
  }
  cout << res << endl;

}
