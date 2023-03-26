#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int>> yay;
typedef pair<int, int> pos;
int N, K;

bool dfs(yay &data, pos from, pos me, yay visit){ 
  if(me.first < 0 || me.first >= N) {return false;}
  if(me.second < 0 || me.second >= N) {return false;}
  if(visit[me.first][me.second] == 1){
    return false;
  }
  if(me.first == (N - 1)  && me.second == (N - 1)){ return true;}
  int f, m, diff;
  f = data[from.first][from.second];
  m = data[me.first][me.second];
  if((m - f) > K){
    return false;
  }
  visit[me.first][me.second] = 1;
  pos a1, a2, a3, a4;
  a1 = me;
  a1.first += 1;
  a2 = me;
  a2.first -= 1;
  a3 = me;
  a2.second += 1;
  a4 = me;
  a4.second -= 1;
  if( dfs(data, me, a1, visit) || \
      dfs(data, me, a2, visit) || \
      dfs(data, me, a3, visit) || \
      dfs(data, me, a4, visit)){
    return true;
  }
  return false;
}

int main(void){
  cin >> N >> K;
  yay data(N);
  int a;
  for(int i =0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> a;
      data[i].push_back(a);
    }
  }
  pos start = make_pair(0, 0);
  pos n2 = make_pair(0, 1), n1 = make_pair(1, 0);
  yay visit;
  for(int i = 0; i < N; i++){
    visit.push_back(vector<int> (N));
  }
  visit[0][0] = 1;
  if(dfs(data, start, n2, visit) || \
      dfs(data, start, n1, visit)){
      cout << "yes" << endl;
      }
  else{
    cout << "no" << endl;
  }
  
}
