#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> nc;
typedef vector<vector<nc>> graph;

int bfs(graph &data, int start, int target, int color){
  queue<int> q;
  vector<int> layers(data.size());
  vector<bool> seens(data.size());
  q.push(start);
  seens[start] = true;
  layers[start] = 0;
  int c;
  while(!q.empty()){
    c = q.front();
    q.pop();
    for(auto i: data[c]){
      if(seens[i.first]){
        continue;
      }
      if(color == -1 * i.second){
        seens[i.first] = true;
        continue;
      }
      if(i.first == target){
        return layers[c] + 1;
      }
      else{
        q.push(i.first);
        seens[i.first] = true;
        layers[i.first] = layers[c] + 1;
      }
    }
  }
  return -1;
}

int main(void){
  int N, M, S, T;
  cin >> N >> M >> S >> T;
  int a1, a2 ,a3;
  graph data(N + 1);
  for(int i = 0; i < M ;i++){
    cin >> a1 >> a2 >> a3;
    if(a3 == 2){
      a3 = -1;
    }
    data[a1].push_back(make_pair(a2, a3));
    data[a2].push_back(make_pair(a1, a3));
  }
  int red, black;
  red = bfs(data, S, T, 1);
  black = bfs(data, S, T, -1);
  if(red  > black){
    cout << red << endl;
  }
  else{
    cout << black << endl;
  }
  

}
