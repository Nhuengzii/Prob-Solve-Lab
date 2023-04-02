#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;

int dfs(vector<bool> visited, graph &g, int start, int end) {
    if (start == end) {
        return 1;
    }
    visited[start] = true;
    for (int i = 0; i < g[start].size(); i++) {
        if (!visited[g[start][i]]) {
            int res = dfs(visited, g, g[start][i], end);
            if (res == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    graph g(n);
    // get m edges
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int q = 0; q < k; q++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        vector<bool> visited(n, false);
        cout << dfs(visited, g, a, b) << '\n';


    }

    
}
