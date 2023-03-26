#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int *data = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> data[i];
  }

  set<int> res;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      sum += data[j];
      res.insert(sum);
    }
    sum = 0;
  }
  cout << res.size() << endl;
}
