#include <iostream>
#include <map>
using namespace std;

typedef pair<int, int> yay;

void generate_data(int start, int m, yay *data) {
  for (auto i = start; i < start + m; i++) {
    if (i == start) {
      data[i] = make_pair(-1, i + 1);
    } else if (i == start + m - 1) {
      data[i] = make_pair(i - 1, -1);
    } else {
      data[i] = make_pair(i - 1, i + 1);
    }
  }
}

void reverse_line(int at, yay *data) {
  int temp;
  while (true) {
    temp = data[at].first;
    data[at].first = data[at].second;
    data[at].second = temp;
    if (temp == -1)
      break;
    at = temp;
  }
}

int main(void) {
  int L, N;
  cin >> L >> N;
  yay *data = new yay[100001];
  int current = 1;
  // Get data;
  int m;
  for (auto i = 0; i < L; i++) {
    cin >> m;
    generate_data(current, m, data);
    current += m;
  }

  char command;
  int arg, temp;
  current = 1;
  for (auto i = 0; i < N; i++) {
    cin >> command;
    if (command == 'B') {
      if (!(data[current].first == -1)) {
        current = data[current].first;
      }
    } else if (command == 'F') {
      if (!(data[current].second == -1)) {
        current = data[current].second;
      }

    } else if (command == 'C') {
      cin >> arg;
      // cut if not at end
      if (data[current].second != -1) {
        data[data[current].second].first = -1;
        data[current].second = -1;
      }

      // check if should reverse
      if (data[arg].second == -1 && data[arg].first == -1) {
        reverse_line(arg, data);
      }

      // join;
      data[current].second = arg;
      data[arg].first = current;
      current = arg;
    }
    cout << current << endl;
  }
}
