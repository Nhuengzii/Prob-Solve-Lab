#include <iostream>
#include <list>
#include <map>

using namespace std;
typedef list<int> *yee;
int main(void) {
  int L, N;
  cin >> L >> N;
  map<int, yee> data;
  yee temp_v;
  int m, last = 1;
  list<int> *temp;
  for (int i = 0; i < L; i++) {
    cin >> m;
    temp_v = new list<int>;
    data.insert(pair<int, yee>(last, temp_v));
    for (int j = 0; j < m; j++) {
      data[m]->push_back(++last);
    }
  }
  return 0;
}
