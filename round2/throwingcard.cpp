#include <iostream>
#include <list>

using namespace std;

void get_data(list<int> &d, int n) {
  for (int i = 0; i < n; i++) {
    d.push_front(i + 1);
  }
}

int main() {
  int N;
  list<int> yee;

  while (true) {
    cin >> N;
    if (N == 0) {
      break;
    }
    get_data(yee, N);
    // eiei
    if (yee.size() == 1) {
      cout << "Discarded cards:" << endl;
      cout << "Remaining card: " << *yee.begin() << endl;
      continue;
    }
    cout << "Discarded cards:";
    while (true) {
      if (yee.size() == 2) {
        cout << " " << *(--yee.end()) << endl;
        yee.pop_back();
        break;
      }
      cout << " " << *(--yee.end()) << ",";
      yee.pop_back();
      yee.push_front(*(--yee.end()));
      yee.pop_back();
    }
    cout << "Remaining card: " << *yee.begin() << endl;
    yee.clear();
  }
  return 0;
}
