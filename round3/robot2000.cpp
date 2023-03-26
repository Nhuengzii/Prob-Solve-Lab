#include <iostream>
#include <map>
using namespace std;

// look, command
typedef pair<string, string> yay;
int main(void) {
  string raw;
  cin >> raw;
  string look = "N";
  yay m[16] = {
      make_pair("N", "N"), make_pair("N", "E"), make_pair("N", "S"),
      make_pair("N", "W"), make_pair("E", "N"), make_pair("E", "E"),
      make_pair("E", "S"), make_pair("E", "W"), make_pair("S", "N"),
      make_pair("S", "E"), make_pair("S", "S"), make_pair("S", "W"),
      make_pair("W", "N"), make_pair("W", "E"), make_pair("W", "S"),
      make_pair("W", "W"),
  };
  string t[16] = {"F",   "RF",   "RRF", "RRRF", "RRRF", "F",   "RF",   "RRF",
                  "RRF", "RRRF", "F",   "RF",   "RF",   "RRF", "RRRF", "F"};
  map<yay, string> conv;
  for (int i = 0; i < 16; i++) {
    conv[m[i]] = t[i];
  }
  string command;
  for (int i = 0; i < raw.length(); i++) {
    command = raw[i];
    if (command == "Z") {
      cout << command;
      look = "N";
    } else {
      cout << conv[make_pair(look, command)];
      look = command;
    }
  }
  cout << endl;
}
