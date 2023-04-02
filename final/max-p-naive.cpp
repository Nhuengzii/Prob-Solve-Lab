#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// find minimum index that a[index] >= x
int l_close(vector<int> &a, int x){
    int l = 0, r = a.size();
    while (l < r){
        int m = (l + r) / 2;
        if (a[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return l;
}


int main (int argc, char *argv[])
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int Q = 0; Q < q; Q++){
        int x, y;
        cin >> x >> y;
        int m = 0;
        for (int l = l_close(a, y); l < n; l++){
            if (a[l] <= x){
                x -= a[l];
                m++;
            }  
            else{
                break;
            }
        }
        cout << m << endl;
    }

    return 0;
}
