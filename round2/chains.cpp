#include "iostream"

using namespace std;

int main(void) {
  // Input;
  int L, N;
  cin >> L >> N;
  int *M = new int[L];
  int *result = new int[N];
  for (int i = 0; i < L; i++) {
    cin >> M[i];
  }

  // Process;
  char c;
  int temp = -77;
  int current_line = 1;
  int current_num = 1;
  for (int r = 0; r < N; r++) {
    cin >> c;
    if (c == 'F') {
      if (current_num < M[current_line]) {
        current_num++;
      }

    } else if (c == 'B') {
      if (current_num > 1 or current_num > (M[current_line - 1] + 1)) {
        current_num--;
      }

    } else if (c == 'C') {
      cin >> temp;
    }
    result[r] = current_num;
  }
  for (int i = 0; i < N; i++) {
    cout << result[i] << endl;
  }

  return 0;
}
