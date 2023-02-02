#include <iostream>
using namespace std;

// name, ability
typedef pair<int, int> yay;

int main(void) {
  yay *data = new yay[4];
  int N;
  cin >> N;
  int a1;
  int me = 1;
  for (int k = 1; k <= 4; k++) {
    for (int i = 1 + (k - 1) * N; i <= k * N; i++) {
      cin >> a1;
      if (data[k - 1].second < a1) {
        data[k - 1].first = me++;
        data[k - 1].second = a1;
      }
    }
  }
  int *result = new int[4];
  // block A
  if (data[0].second > data[1].second) {
    result[2] = data[1].first;
    // block B
    if (data[2].second > data[3].second) {
      result[3] = data[3].first;
      if (data[0].second > data[2].second) {
        result[0] = data[0].first;
        result[1] = data[2].first;
      } else {
        result[0] = data[2].first;
        result[1] = data[0].first;
      }
    } else {
      result[3] = data[2].first;
      if (data[0].second > data[3].second) {
        result[0] = data[0].first;
        result[1] = data[3].first;
      } else {
        result[0] = data[3].first;
        result[1] = data[0].first;
      }
    }
  } else {
    result[2] = data[0].first;
    if (data[2].second > data[3].second) {
      result[3] = data[3].first;
      if (data[1].second > data[2].second) {
        result[0] = data[1].first;
        result[1] = data[2].first;
      } else {
        result[0] = data[2].first;
        result[1] = data[1].first;
      }
    } else {
      result[3] = data[2].first;
      if (data[1].second > data[2].second) {
        result[0] = data[1].first;
        result[1] = data[3].first;
      } else {
        result[0] = data[3].first;
        result[1] = data[1].first;
      }
    }
  }
  cout << result[0] << " " << result[1] << " ";
  cout << result[2] << " " << result[3] << endl;
}
