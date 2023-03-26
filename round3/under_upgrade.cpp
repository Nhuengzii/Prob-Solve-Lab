#include <iostream>

using namespace std;
int main(void) {

  int L, N;
  cin >> L >> N;
  int a1, a2;
  int max = -999999;
  int *data = new int[2 * L];
  for (int i = 0; i < N; i++) {
    cin >> a1 >> a2;
    for (int j = 2 * a1 + 1; j <= 2 * a2 - 1; j++) {
      data[j]++;
      if (data[j] > max) {
        max = data[j];
      }
    }
  }

  cout << max << endl;
}
