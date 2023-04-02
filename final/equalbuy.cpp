#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    int N;
    cin >> N;
    vector<int> v(N);
    int max_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        max_sum += v[i];
    }



    return 0;
}
