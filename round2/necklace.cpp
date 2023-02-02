#include <iostream>
using namespace std;
int main() {
  int N;
  cin >> N;
  int t1, t2;
  int *data = new int[N + 1];
  int *visit = new int[N + 1];
  int target = 678;
  int temp = 222;
  for (int i = 0; i < N - 1; i++) {
    cin >> t1 >> t2;
    if (data[t2] == 0) {
      data[t2] = t1;
    } else {
      temp = data[t2];
      data[t2] = t1;
      target = t1;
      while (true) {
        if (data[target] == 0) {
          data[target] = temp;
          break;
        } else {
          target = data[target];
        }
      }
    }
    visit[t1] = 1;
  }

  // find head
  int j = 0;
  for (j = 1; j <= N; j++) {
    if (visit[j] == 0) {
      break;
    }
  }
  cout << j;
  while (true) {
    j = data[j];
    if (j == 0) {
      break;
    }
    cout << " " << j;
  }

  return 0;
}
