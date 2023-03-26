#include <iostream>
#include <iterator>
#include <list>

using namespace std;
int main(void) {
  int M;
  cin >> M;
  char command;
  int t1, t2;
  list<int> *data = new list<int>[100001];
  for (int i = 0; i < M; i++) {
    cin >> command >> t1 >> t2;
    if (command == 'N') {
      data[t2].push_back(t1);
    } else if (command == 'M') {
      data[t2].splice(data[t2].end(), data[t1]);
    }
  }
  list<int>::iterator it;
  for (int i = 0; i < 100001; i++) {
    if (!data[i].empty()) {
      for (auto i : data[i]) {
        cout << i << '\n';
      }
    }
  }
  return 0;
}
