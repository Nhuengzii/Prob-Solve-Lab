#include <iostream>
#include <iterator>
#include <list>
using namespace std;
int main(void) {
  int M;
  cin >> M;
  char command;
  long long int arg = -777;
  list<long long int> data;
  for (int i = 0; i < M; i++) {
    cin >> command >> arg;
    if (command == 'I') {
      data.push_front(arg);
    } else if (command == 'D') {
      if (arg > data.size()) {
        continue;
      }
      list<long long int>::iterator a = data.begin();
      for (int i = 1; i < arg; i++) {
        a++;
      }
      data.erase(a);
    }
  }
  for (list<long long int>::iterator it = data.begin(); it != data.end();
       ++it) {
    cout << *it << endl;
  }

  return 0;
}
