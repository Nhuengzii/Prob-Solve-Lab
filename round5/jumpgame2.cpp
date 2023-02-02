#include <iostream>
#include <vector>


using namespace std;

typedef vector<vector<int>> board;

int N, K;
bool goTo(board &data, board visit, int x, int y, int u, int v){
  if(visit[x][y]){
    return false;
  }
  if(x < 0 || x >= N){
    return false;
  }
  if(y < 0 || y >= N){
    return false;
  }
  if(x == (N - 1) && y == (N-1)){
    return true;
  }
  int me = data[x][y];
  int you = data[u][v];
  if((me - you) > K){
    return false;
  }
  cout << "Im here " << x << " " << y << endl;
  visit[x][y] = true;
  return goTo(data, visit, x - 1, y, x, y) || goTo(data, visit, x + 1, y, x, y) \
      || goTo(data, visit, x, y - 1, x, y) || goTo(data, visit, x, y + 1, x, y);
  

}

int main(void){
  cin >> N >> K;
  board data(N);
  board visit(N);
  int temp;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> temp;
      data[i].push_back(temp);
      visit[i].push_back(0);
    }
  }

  if(goTo(data, visit, 0, 1, 0, 0) || goTo(data, visit, 1, 0, 0, 0)){
    cout << "yes" <<endl;
  }
  else{
    cout << "no" << endl;
  }
}