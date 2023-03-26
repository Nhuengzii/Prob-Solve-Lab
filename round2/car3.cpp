#include <iostream>
using namespace std;

typedef long long int yay;

int main(void) {
  int N;
  cin >> N;
  yay p, v;
  int wow = 0;
  pair<yay, yay> data[200000];
  bool should_add = false;
  for (int i = 0; i < N; i++) {
    cin >> p >> v;
    should_add = true;
    for (int i = 0; i < wow; i++) {
      if ((data[i].first > p) && (data[i].second < v)) {
        data[i] = make_pair(p, v);
        should_add = false;
        break;
      }
    }
    if (should_add) {
      data[wow++] = make_pair(p, v);
    }
  }
  cout << N - wow << endl;
}
