#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<bool>> vit;
int solve(vector<string> data, vit visit, int a, int b, int x, int y, bool dig, char mode, int num){
  if(a == x && b == y){
    return num;
  }
  if(a < 0 || a >= data.size()){
    return -1;
  }
  if(b < 0 || b >= data[0].size()){
    return -1;
  }
  if(visit[a][b]){
    return -1;
  }
  if(data[a][b] == '#'){
    return -1;
  }
  if(data[a][b] == '|' && mode == 'H'){
    return -1;
  }
  if(data[a][b] == '-' && mode == 'V'){
    return -1;
  }
  if(data[a][b] == '*'){
    if(dig){
      if(mode == 'H'){
        data[a][b] = '-';
      }
      else if(mode == 'V'){
        data[a][b] = '|';
      }
      dig = false;
    }
    else{
      return -1;
    }
  }
  int left, right, up, down;
  visit[a][b] = true;
  left = solve(data, visit, a, b - 1, x, y, dig, 'H', num++);
  right = solve(data, visit, a, b + 1, x, y, dig, 'H', num++);
  up = solve(data, visit, a + 1, b, x, y, dig, 'V', num++);
  down = solve(data, visit, a - 1, b, x, y, dig, 'V', num++);
  vector<int> m = {left, right, up, down};
  int mm = -1;
  for(auto i: m){
    if(i > mm){
      mm = i;
    }
  }
  return mm;
}


int main(void){
  int R, C;
  cin >> R >> C;
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  a--;
  b--;
  x--;
  y--;
  vector<string> board(R);
  vector<vector<bool>> visit;
  for(int i = 0; i < R; i++){
    cin >> board[i];
    visit.push_back(vector<bool> (R));
  }

  int res = solve(board, visit, a, b, x, y, 'H', true, 0);
  cout << res << endl;
}
