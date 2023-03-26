#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++){
        cin >> d[i];
    }
    vector<int> rec(n, 1);
    int g_max = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if ( d[j] >= d[i]) continue;
            if (rec[j] + 1 > rec[i]){
                rec[i] = rec[j] + 1;
                if ( rec[i] > g_max){
                    g_max = rec[i];
                }
            }
        }
    }
    cout << g_max << endl;
    int l_d = -99999999; 
    for (int i = 1; i <= g_max; i++){
        for (int j = 0; j < n; j++){
            if (rec[j] == i && (l_d == -99999999 || l_d < d[j])){
                if( i == g_max){
                    printf("%d\n", d[j]);
                }
                else{
                    printf("%d ", d[j]);
                }
                l_d = d[j];
                break;
            }
        }
    }
    return 0;
}
