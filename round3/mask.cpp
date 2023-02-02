#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> yay;
int main(void) {
  int N;
  cin >> N;
  yay *winner = new yay[4];
  int temp;
  int j = 0;
  for (auto i = 0; i < 4; i++) {
    for (j = j; j < (i + 1) * N; j++) {
      cin >> temp;
      if (temp > winner[i].first) {
        winner[i].first = temp;
        winner[i].second = j + 1;
      }
    }
  }
  yay *winner2 = new yay[2];
  for (auto i = 0; i < 2; i++) {
    if (winner[2 * i + 0].first > winner[2 * i + 1].first) {
      winner2[0 + i] =
          make_pair(winner[2 * i + 0].first, winner[2 * i + 0].second);
    } else {

      winner2[i + 0] =
          make_pair(winner[2 * i + 1].first, winner[2 * i + 1].second);
    }
  }
  if (winner2[0].first > winner2[1].first) {
    cout << winner2[0].second << " " << winner2[1].second << " ";
  } else {
    cout << winner2[1].second << " " << winner2[0].second << " ";
  }
  if (winner[0].first > winner2[1].first) {
    cout << winner[1].second << " ";
  } else {
    cout << winner[0].second << " ";
  }
  if (winner[2].first > winner[3].first) {
    cout << winner[3].second << endl;
  } else {
    cout << winner[2].second << endl;
  }
}
