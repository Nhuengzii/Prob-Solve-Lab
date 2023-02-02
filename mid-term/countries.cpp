#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef vector<vector<int>> yay;

map<int, bool> dfs(yay &data, yay visit, int a, int b, int x, int y, map<int, bool> pass){
  if(visit[a][b]){
    return map<int, bool>();
  }
  if(a == x && b == y){
    return map<int, bool>();
  }
  if( a < 0 || a >= data.size()){
    return map<int, bool>();
  }
  if(b < 0 || b >= data[0].size()){
    return map<int, bool>();
  }
  int country;
  visit[a][b] = true;
  country = data[a][b];
  if(pass.find(country) == pass.end()){
    pass[country] = true;
  }
  map<int, bool> left, right, up, down;
  left = dfs(data, visit, a, b - 1, x, y, pass);
  right = dfs(data, visit, a, b + 1, x, y, pass);
  up = dfs(data, visit, a - 1, b, x, y, pass);
  down = dfs(data, visit, a + 1, b, x, y, pass);
  vector<map<int, bool>> res = {left, right, up, down};
  int r = 0;
  for(int i = 0; i < 4; i++){
    if(res[r].size() < res[i].size()){
      r = i;
    }
  }
  return res[r];

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
      visit[i].push_back(false);
    }
  }
  map<int, bool> res;
  res[data[A][B]] = true;
  res = dfs(data, visit, A, B, X, Y, res);
  cout << res.size() - 1 << endl;
}
