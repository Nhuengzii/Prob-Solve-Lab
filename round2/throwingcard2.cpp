#include <iostream>
#include <queue>

using namespace std;
int main(void) {

  int n, temp;
  queue<int> data;
  while (true) {
    cin >> n;
    if (n == 0)
      break;

    // initialize
    for (int i = 1; i <= n; i++) {
      data.push(i);
    }

    cout << "Discarded cards:";
    while (data.size() > 1) {
      printf(" %d", data.front());
      data.pop();
      temp = data.front();
      data.pop();
      data.push(temp);
      if (data.size() > 1) {
        cout << ",";
      }
    }
    cout << "\nRemaining card: " << data.front() << endl;
    data.pop();
  }
}
