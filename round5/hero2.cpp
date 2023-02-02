#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<pair<int, bool>>> graph;
int N, M, K, H;

void goTo(graph &data, vector<bool> &isVisit, vector<bool> &isSchool, int me, int h, int magik){
  if( h < 0){
    return;
  }
  isVisit[me] = true;
  if(!magik){
    magik = isSchool[me];
  }
  if(h == 0){
    return;
  }
  int u;
  bool t;
  for(auto i: data[me]){
    u = i.first;
    t = i.second;
    if((t && magik) || !t){
      if(h == 1){
        isVisit[u] = true;
        continue;
      }
      goTo(data, isVisit, isSchool,u, h - 1, magik);
    }

    
  }
}

int main(void){

  cin >> N >> M >> K >> H;
  vector<bool> isSchool(N + 1);
  vector<bool> isVisit(N + 1);
  if(K == 0){
    getchar();
  }
  else{
    for(int i = 0; i < K; i++){
      int temp;
      cin >> temp;
      isSchool[temp] = true;
    }
  }
  int a1, a2, a3;
  graph data(N + 1);
  for(int i = 0; i < M;i++){
    cin >> a1 >> a2 >> a3;
    data[a1].push_back(make_pair(a2, a3));
    data[a2].push_back(make_pair(a1, a3));
  }
  bool magik = isSchool[1];
  goTo(data, isVisit, isSchool, 1, H, magik);
  int res = 0;
  for(auto i: isVisit){
    if(i){
      res++;
    }
  }
  cout << res << endl;

  
}

