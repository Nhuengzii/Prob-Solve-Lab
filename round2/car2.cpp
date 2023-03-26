#include <iostream>
#include <set>

typedef unsigned long int yay;
using namespace std;
int main(void) {
  int N;
  cin >> N;
  set<pair<yay, yay>, greater<pair<yay, yay>>> price;
  yay t1, t2;
  for (int i = 0; i < N; i++) {
    cin >> t1 >> t2;
    price.insert(make_pair(t1, t2));
  }
  int x = 0, res = 0;
  set<pair<yay, yay>, greater<yay>>::iterator l;
  for (set<pair<yay, yay>, greater<yay>>::iterator it = price.begin();
       it != price.end(); it++) {
    t1 = it->first;
    t2 = it->second;

    l = price.begin();
    advance(l, x);
    for (l = l; l != price.end(); l++) {
      if (t2 < l->second) {
        res++;
        break;
      }
    }
    x++;
  }
  cout << res << endl;
}
