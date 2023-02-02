#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void add_node(vector<int> *data, pair<int, int> *co, int a, int r) {
  int temp;
  pair<int, int> me = co[a];
  pair<int, int> you;
  for (auto i = 0; i < a; i++) {
    you = co[i];
    temp = pow(me.first - you.first, 2) + pow(me.second - you.second, 2);
    if (temp <= pow(r, 2)) {
      data[i].push_back(a);
      data[a].push_back(i);
    }
  }
}

int dfs(vector<int> *data, vector<int> visit, int a, int count) {
  if (a == data->size() - 1) {
    return count;
  }
  visit[a] = 1;
  int min = 99999;
  int x = count;
  for (int i = 0; i < data[a].size(); i++) {
    if (visit[data[a][i]] == 0) {
      x = count + dfs(data, visit, data[a][i], count + 1);
      if (x < min) {
        min = x;
      }
    }
  }
  return min;
}

int main(void) {
  int N, R;
  cin >> N >> R;

  pair<int, int> *co = new pair<int, int>[N + 2];
  vector<int> *data = new vector<int>[N + 2];
  co[0] = make_pair(0, 0);
  int a1, a2;
  for (auto i = 1; i <= N; i++) {
    cin >> a1 >> a2;
    co[i] = make_pair(a1, a2);
    add_node(data, co, i, R);
  }
  co[N + 1] = make_pair(100, 100);
  add_node(data, co, N + 1, R);
  vector<int> visit = {0, 0, 0, 0, 0, 0, 0};
  int res = dfs(data, visit, 0, 0);
  cout << res << endl;
}
