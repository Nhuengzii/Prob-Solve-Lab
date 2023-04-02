#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void show_result(vector<int> &v) {
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

int main() {
    int n=0, a=0, max=0, root=0;
    cin >> n;
    vector<int> num, answer;
    int A[n], anc[n];

    int i = 0;
    while(i < n) {
        cin >> a;
        num.push_back(a);
        anc[i++] = -1;
    }

    A[0] = 0;
    i = 0;
    while(i < n) {
        max = 0;
        int j = 0;
        while(j < i){
            if (num[i] > num[j] && A[j] > max) {
                max = A[j];
                anc[i] = j;
            }
            j++;
        }
        A[i] = 1 + max;
        i++;
    }

    max = A[0];
    i = 0;
    while(i < n) {
        if (A[i] > max) {
            max = A[i];
            root = i;
        }
        i++;
    }

    while (true) {
        answer.push_back(num[root]);
        root = anc[root];
        if (anc[root] == -1) {
            answer.push_back(num[root]);
            break;
        }
    }
    reverse(answer.begin(), answer.end());

    cout << max << '\n';
    show_result(answer);

    return 0;
}
