#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef pair<int, int> yay;
typedef pair<yay, vector<int>> yee;

void add_node(int x, int y, int r, int idx, yee **d) {
  int temp;
  yee *data = *d;
  data[idx].first = make_pair(x, y);
  for (int i = 0; i < idx; i++) {
    temp = pow(x - data[i].first.first, 2) + pow(y - data[i].first.second, 2);
    if (temp <= r * r) {
      data[i].second.push_back(idx);
      data[idx].second.push_back(i);
    }
  }
}

int dfs(int a, yee *data, vector<int> visit) {
  visit[a] = 1;
  int mini = 999999;
  int temp, temp2;
  for (int i = 0; i < data[a].second.size(); i++) {
    temp = data[a].second[i];
    if (visit[temp] == 0) {
      temp2 = dfs(temp, data, visit);
      if (temp2 < mini) {
        mini = temp2;
      }
    }
  }
  return mini;
}

int main(void) {
  int N, R;
  cin >> N >> R;
  yee *data = new yee[N + 2];
  data[0].first = make_pair(0, 0);
  int a1, a2;
  for (int i = 1; i <= N; i++) {
    cin >> a1 >> a2;
    add_node(a1, a2, R, i, &data);
  }
  add_node(100, 100, R, N + 1, &data);

  cout << "yee" << endl;
}
