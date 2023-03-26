#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int test_possible(int n, int *out) {
  int l = 1, r = 0;
  list<int> temp;
  while (true) {
    if (l > n) {
      break;
    }
    if (temp.size() == 0) {
      temp.push_back(l++);
      if (*(--temp.end()) == out[r]) {
        temp.pop_back();
        r++;
      }
    } else {
      if (*(--temp.end()) == out[r]) {
        temp.pop_back();
        r++;
      } else {
        temp.push_back(l++);
      }
    }
  }
  if (temp.size() == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int N;
  int *out;
  while (true) {
    cin >> N;
    if (N == 0) {
      break;
    }
    out = new int[N];
    while (true) {
      for (int i = 0; i < N; i++) {
        cin >> out[i];
        if (out[i] == 0) {
          break;
        }
      }
      if (out[0] == 0) {
        delete out;
        cout << "\n";
        break;
      } else {
        if (test_possible(N, out) == 1) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      }
    }
  }
  return 0;
}
