#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> memo = vector<vector<int>>(1000, vector<int>(1000, -1));


int main (int argc, char *argv[])
{
    int l;
    vector<int> v;
    while(true){
        cin >> l;
        if (l == 0) return 0;
        int s;
        cin >> s;
        v.clear();
        v = vector<int>(s);
        for (int i = 0; i < s; i++){
            cin >> v[i];
        }

        // Solve



    }
    return 0;
}
