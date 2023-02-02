#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pos;

bool can_i_stay_here(vector<string> &maze, pos ul) {
  int x, y;
  x = ul.first;
  y = ul.second;
  int r = maze.size();
  int c = maze[0].length();
  if (x <= 0 || x >= r || y <= 0 || y >= c) {
    return false;
  }
  if (maze[x][y] == '.' && maze[x][y + 1] == '.' && maze[x - 1][y] == '.' &&
      maze[x - 1][y + 1] == '.') {
    return true;
  } else {
    return false;
  }
}

bool is_i_at_goal(vector<string> &maze, pos ul) {
  int x, y;
  x = ul.first;
  y = ul.second;
  int r = maze.size();
  int c = maze[0].length();
  if (y - 1 == r - 1) {
    return true;
  } else {
    return false;
  }
}

bool solve(vector<string> &maze, pos ul) {
  if (!can_i_stay_here(maze, ul))
    return false;
  if (is_i_at_goal(maze, ul)) {
    return true;
  }
  pos a, b, c, d;
  a = make_pair(ul.first, ul.second + 2);
  b = make_pair(ul.first + 2, ul.second);
  c = make_pair(ul.first + 2, ul.second + 2);
  d = make_pair(ul.first - 2, ul.second);
  maze[ul.first][ul.second] = 'X';
  maze[ul.first][ul.second + 2] = 'X';
  maze[ul.first - 2][ul.second] = 'X';
  maze[ul.first - 2][ul.second + 2] = 'X';
  if (solve(maze, a) || solve(maze, b) || solve(maze, c) || solve(maze, d)) {
    return true;
  } else {
    maze[ul.first][ul.second] = '.';
    maze[ul.first][ul.second + 2] = '.';
    maze[ul.first - 2][ul.second] = '.';
    maze[ul.first - 2][ul.second + 2] = '.';
    return false;
  }
}

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<string> maze;
  string temp;
  for (int i = 0; i < N + 1; i++) {
    getline(cin, temp);
    if (i == 0) {
      continue;
    }
    maze.push_back(temp);
  }
  for (int i = 0; i < N; i++) {
    cout << maze[i] << endl;
  }
  pos ul = make_pair(0, 0);
  for (int i = 0; i < M; i++) {
    if (solve(maze, ul)) {
      cout << "true" << endl;
      return 0;
    }

    ul.second++;
  }
  cout << "false" << endl;
}
