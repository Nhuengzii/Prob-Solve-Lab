#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> job;

int get_latest_compat_index(vector<job> jobs, int index)
{
    // return -1 if not found
    int latest = -1;
    for(int i = index - 1; i >= 0; i--) {
        if (get<1>(jobs[i]) <= get<0>(jobs[index])) {
            latest = i;
            break;
        }
    }
    return latest;
}

int get_maximal_profit(vector<job> jobs, int index)
{
    int latest = get_latest_compat_index(jobs, index);
    if (latest == -1) {
        return get<2>(jobs[index]);
    } else {
        return get<2>(jobs[index]) + get_maximal_profit(jobs, latest);
    }
}

int main (int argc, char *argv[])
{
    int N;
    cin >> N;
    vector<job> jobs;
    for (int i = 0; i < N; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        jobs.push_back(make_tuple(s, t, w));
    }
    int max_profit = 0;
    for (int i = 0; i < N; i++) {
        int profit = get_maximal_profit(jobs, i);
        if (profit > max_profit) {
            max_profit = profit;
        }
    }
    cout << max_profit << endl;


    return 0;
}
