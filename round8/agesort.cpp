#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void merge_sort(vector<int> &ages, int l, int r){
    if (l == r){
        return;
    }

    int mid = (r + l) / 2; 
    merge_sort(ages, l, mid);
    merge_sort(ages, mid + 1, r);
    vector<int> temp((r - l) + 1);
    int i = 0, j = 0, x = 0;
    while(i < (mid - l + 1) && j < (r - mid)){
        if(ages[l + i] < ages[mid + 1 + j]){
            temp[x++] = ages[l + i];
            i++;
        }
        else{
            temp[x++] = ages[mid + 1 + j];
            j++;
        }
    }
    while(i < (mid - l + 1)){
        temp[x++] = ages[l + i++];
    }
    while(j < (r - mid)){
        temp[x++] = ages[mid + 1 + j++];
    }
    for(int i = 0; i < (r - l + 1); i++){
        ages[l + i] = temp[i];
    }
}

int main (int argc, char *argv[])
{
    int n;
    vector<int> ages;
    while(true){
        cin >> n;
        if (n == 0) return 0;
        ages = vector<int> (n);
        for (int i = 0; i < n; i++){
            cin >> ages[i];
        }
        merge_sort(ages, 0, n - 1);
        int i = 0;
        while(i < n - 1){
            printf("%d ", ages[i++]);
        }
        printf("%d\n", ages[i]);
    }
    return 0;
}
