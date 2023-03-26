#include <iostream>
#include <vector>


using namespace std;
typedef pair<int, bool> yay;
typedef vector<vector<yay>> graph;

void goTo(graph &data, vector<bool> &visit, vector<bool> school, int me, int h, bool magik){
  if(h < 0) return;
  visit[me] = true;
  if(h == 0){
    return;
  }
  if(school[me]){
    magik = true;
  }
  for(auto v: data[me]){
    if(v.second == 0){
      goTo(data, visit, school, v.first, --h, magik);
    } 
    if(v.second == 1 && magik){
      goTo(data, visit, school, v.first, --h, magik);
    }
  }
}

int main(void){
  int N, M, K, H;
  cin >> N >> M >> K >> H;
  vector<bool> school(N + 1);
  vector<bool> visit(N + 1);
  int temp;
  if( K == 0){
    getchar();
  }
  else{
    for(int i = 0; i < K; i++){
      cin >> temp;
      school[temp] = true;
    }
  }
  int a1, a2, a3;
  graph data( N + 1);
  for(auto i = 0; i < M; i++){
    cin >> a1 >> a2 >> a3; 
    data[a1].push_back(make_pair(a2, a3));
    data[a2].push_back(make_pair(a1, a3));
  }
  bool magik = school[1];
  visit[1] = true;
  goTo(data, visit, school, 1, H, magik);
  int res = 0;
  for(int i = 1; i<= N; i++){
    if(visit[i]){
      res++;
    }
  }
  cout << res << endl;
}
