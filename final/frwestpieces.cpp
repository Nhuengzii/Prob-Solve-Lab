#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main (int argc, char *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<vector<int> > v(m, vector<int>(n));
    vector<vector<int> > dp(m, vector<int>(n, -1));
    // input 2d map
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1){
                dp[i][j] = v[i][j];
            }
        }
    }

    for (int i = 1; i < m - 1; i++){
        for (int j = 1; j < n - 1; j++){
            int left = dp[i][j - 1];
            int right = 0;
            for(int x = j + 1; x < n; x++){
                right += v[i][x];
            }
            int up = dp[i - 1][j];
            int down = 0;
            for(int x = i + 1; x < m; x++){
                down += v[x][j];
            }
            int m = min(min(left, down), min(up, right));
            dp[i][j] = m + v[i][j];
        }
    }




    // printf dp
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
