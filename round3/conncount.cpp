#include <iostream>
#include <vector>

using namespace std;

void dfs(int a, int *visit, vector<int> *data) {
  visit[a] = 1;
  int temp;
  for (auto i = 0; i < data[a].size(); i++) {
    temp = data[a][i];
    if (visit[temp] == 1)
      continue;
    dfs(temp, visit, data);
  }
}

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<int> *data = new vector<int>[N];
  int arg1, arg2;
  for (auto i = 0; i < M; i++) {
    cin >> arg1 >> arg2;
    arg2--;
    arg1--;
    data[arg1].push_back(arg2);
    data[arg2].push_back(arg1);
  }
  int *visit = new int[N];
  int res = 0;
  for (int i = 0; i < N; i++) {
    if (visit[i] == 0) {
      dfs(i, visit, data);
      res++;
    }
  }
  cout << res << endl;
}
