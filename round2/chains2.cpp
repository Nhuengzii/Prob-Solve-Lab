#include <iostream>
#include <list>

using namespace std;
int main(void) {
  int L, N;
  int num = 0;
  cin >> L >> N;
  int *M = new int[L];
  for (int i = 0; i < L; i++) {
    cin >> M[i];
    num += M[i];
  }

  // initailize
  int *data = new int[num + 1];
  int last = 1;
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < M[i]; j++) {
      data[last] = last + 1;
      last++;
    }
  }

  return 0;
}
