#include <iostream>
#include <map>
#include <set>

using namespace std;
int main(void) {
  int N;
  cin >> N;
  set<long int> eff;
  map<long int, long int> m;
  long int p, v;
  for (int i = 0; i < N; i++) {
    cin >> p >> v;
    eff.insert(v);
    m.insert(pair<long int, long int>(v, p));
  }
  int res = 0;
  int current = 0;

  for (set<long int>::iterator i = eff.begin(); i != eff.end(); i++) {
    current = m[*i];
    for (set<long int>::iterator j = i; j != eff.end(); j++) {
      if (m[*j] < current) {
        res++;
      }
    }
  }

  cout << res << '\n';
  return 0;
}
