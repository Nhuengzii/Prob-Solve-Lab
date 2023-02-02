#include <iostream>
#include <iterator>
#include <list>

using namespace std;
int main(void) {

  int M;
  cin >> M;
  list<int> data;
  int arg = -777;
  char command;
  list<int>::iterator temp_it;
  for (int i = 0; i < M; i++) {
    cin >> command >> arg;
    if (command == 'A') {
      data.push_back(arg);

    } else if (command == 'I') {
      data.push_front(arg);

    } else if (command == 'D') {
      if (arg > data.size()) {
        continue;
      }
      temp_it = data.begin();
      advance(temp_it, --arg);
      data.erase(temp_it);
    }
  }
  temp_it = data.begin();
  for (int i = 0; i < data.size(); i++) {
    cout << *temp_it << endl;
    temp_it++;
  }

  return 0;
}
