#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int lcs(string &a, string &b, int n, int m, vector<vector<int>> &memo){
    int result = -999;
    if(n == 0 or m == 0){
        memo[n][m] = 0;
        return 0;
    }
    else if (memo[n - 1][m - 1] != -1){
        return memo[n - 1][m - 1];
    }
    else if(a[n - 1] == b[m - 1]){
        result = 1 + lcs(a, b, n - 1, m - 1, memo);
    }
    else{
        int temp1 = lcs(a, b, n - 1, m, memo);
        int temp2 = lcs(a, b, n, m - 1, memo);
        result = max(temp1, temp2); 
    }
    
    memo[n - 1][m - 1] = result;
    return result;

}

int main (int argc, char *argv[])
{
    string a, b;
    cin >> a;
    cin >> b;
    int n = a.length(), m = b.length();
    int result = 0;
    vector<vector<int>> memo(n, vector<int> (m, -1)); 
    result = lcs(a, b, n, m, memo);
    cout << result << endl;
    return 0;
}
