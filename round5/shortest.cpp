#include <iostream>
#include <vector>
#include <set>
#define inf 99999999
using namespace std;

typedef pair<int, int> yay;
typedef vector<vector<yay>> graph;
int main(void){
  int N, M;
  cin >> N >> M;
  graph data(N + 1);
  int a1, a2, a3;
  vector<int> dis(N + 1);
  int x = 1;
  for(int i = 1; i <= N; i++){
   cin >> a1 >> a2 >> a3;
   data[a1].push_back(make_pair(a3, a2));
   data[a2].push_back(make_pair(a1, a2));
   if(x <= N){
     dis[x++] = inf;
   }
  }
  vector<bool> done(N + 1);
  dis[1] = 0;
  set<yay> pq;
  pq.insert(make_pair(0, 1));
  yay me, target;
  int temp_d;
  while(!pq.empty()){
   me = *pq.begin(); 
   pq.erase(pq.begin());
    if (done[me.second]) {
      continue;
    }
    for(int i = 0; i < data[me.second].size(); i++){
      target = data[me.second][i];
      temp_d = me.first + target.first;
      if(temp_d < dis[target.second]){
        dis[target.second] = temp_d;
      }
      pq.insert(make_pair(temp_d, target.second));
    }
    done[me.second] = true;
  }
  cout << dis[N] << endl;
}
