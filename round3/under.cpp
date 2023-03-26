#include <iostream>

using namespace std;
int main(void) {

  int L, N;
  cin >> L >> N;
  int *data = new int[L];
  int a1, a2;
  int res = -9999;
  for (int i = 0; i < N; i++) {
    cin >> a1 >> a2;
    for (int j = a1 + 1; j < a2; j++) {
      data[j]++;
      if (data[j] > res) {
        res = data[j];
      }
    }
  }
  cout << res << endl;
}
