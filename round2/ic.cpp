#include <iostream>
#include <iterator>
#include <list>
using namespace std;
int main(void) {
  int num;
  cin >> num;
  string command = "";
  int arg = -777;
  list<int> data;

  for (int i = 0; i < num; i++) {
    cin >> command;
    if (command == "li") {
      cin >> arg;
      data.push_front(arg);

    } else if (command == "ri") {
      cin >> arg;
      data.push_back(arg);

    } else if (command == "lr") {
      if (data.size() == 0) {
        continue;
      }
      arg = *data.begin();
      data.pop_front();
      data.push_back(arg);

    } else if (command == "rr") {
      if (data.size() == 0) {
        continue;
      }
      arg = *(--data.end());
      data.pop_back();
      data.push_front(arg);
    }
  }
  for (auto it : data) {
    cout << it << endl;
  }

  return 0;
}
