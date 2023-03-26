#include <iostream>
#include <cmath>

using namespace std;

int main (int argc, char *argv[])
{
    string t;
    int num_t;
    cin >> num_t;
    char l = 'A', r = 'A';
    int total_cost = 0;
    for (int i = 0; i < num_t; i++){
        cin >> t;
        total_cost = 0;
        for (char c: t){
            if ((c == l) || (c == r)){
                continue;
            }

            int l_cost = min(abs(26 - (c - l)), abs(c - l));
            int r_cost = min(abs(26 - (c - r)), abs(c - r));
            if (l_cost < r_cost){
                l = c;
                total_cost += l_cost;
            }
            else{
                r = c;
                total_cost += r_cost;
            }
        }

        cout << total_cost << endl;
    }
    return 0;
}
