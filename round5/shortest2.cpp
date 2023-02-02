#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> yay; // (dis, node)
typedef vector<vector<yay>> graph;
int main(void){

  int N, M;
  cin >> N >> M;
  graph data(N + 1);
  int a1, a2, a3;
  for(int i = 0; i < M; i++){
    cin >> a1 >> a2 >> a3;
    data[a1].push_back(make_pair(a3, a2));
    data[a2].push_back(make_pair(a3, a1));
  }
  vector<int> dis(N + 1, 1e5);
  priority_queue<yay, vector<yay>, greater<yay>> pq;
  
  // start
  dis[1] = 0;
  pq.push(make_pair(0, 1));

  while(!pq.empty()){
    yay u = pq.top();
    pq.pop();

    for(auto v: data[u.second]){
      if(dis[v.second] > dis[u.second] + v.first){
        dis[v.second] = dis[u.second] + v.first;
        pq.push(make_pair(dis[v.second], v.second));
      } 
    }
  }

  cout << dis[N] << endl;



}
