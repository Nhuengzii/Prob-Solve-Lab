#include <iostream>
#include <list>
#include <string>

using namespace std;
int main(void) {
  string temp, data;
  while (getline(cin, temp)) {
    // Process
    data = temp;
    list<string> res;
    temp = "";
    int mode = 1;
    for (int i = 0; i < data.size(); i++) {
      if (data[i] == '[') {
        if (mode == 1) {
          res.push_back(temp);
        } else {
          res.push_front(temp);
        }
        temp = "";
        mode = 0;

      } else if (data[i] == ']') {
        if (mode == 1) {
          res.push_back(temp);
        } else {
          res.push_front(temp);
        }
        temp = "";
        mode = 1;

      } else {
        temp += data[i];
      }
    }
    if (mode == 1) {
      res.push_back(temp);
    } else {
      res.push_front(temp);
    }
    for (auto i : res) {
      cout << i;
    }
    cout << endl;
  }
}
