#include <iostream>
#include <vector>

using namespace std;



int main(void){
	int K, N;
	cin >> K >> N;
	vector<int> history(N);
	vector<vector<int>> data( K );
	int a1, a2, a3;
	for(int i = 0;i < K ;i++){
		cin >> a1 >> a2 >> a3;
		data[i] = vector<int> {a1, a2, a3};
	}
	int maxW = -1;
	for(int i = 0; i < N; i++){
		cin >> a1;
		if(a1 > maxW){
			maxW = a1;
		}
		history[i] = a1;
	}
	int minCost = 99999;
	for(auto i: data){
		if(maxW > i[2]){
			continue;
		}
		int cars = 1;
		int currentW = 0;
		for(auto j: history){
			if(currentW + j <= i[2]){
				currentW += j;
			}
			else{
				cars++;
				currentW = j;
			}
		}
		int cost = cars * i[1] + i[0];
		if(cost < minCost){
			minCost = cost;
		}

	}
	cout << minCost << endl;

	
}