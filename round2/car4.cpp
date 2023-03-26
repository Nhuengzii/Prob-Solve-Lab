#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  long int price, value;
  long int *data = new long int[N];
  for (auto i = 0; i < N; i++) {
    cin >> price >> value;
    data[N - 1 - i] = value;
  }
  long int last = -1;
  int res = 0;
  for (auto i = 0; i < N; i++) {
    if (data[i] > last) {
      last = data[i];
      continue;
    } else {
      res++;
    }
  }
  cout << res << endl;
}
