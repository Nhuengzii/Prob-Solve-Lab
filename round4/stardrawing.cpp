#include <iostream>
#include <map>
#include <vector>
#include <numeric>
using namespace std;


int find(vector<int> &data, int s){
	if(data[s] == s){
		return s;
	}
	else{
		return find(data, data[s]);
	}
}

void join(vector<int> &data, int a, int b){
	
}


int main(void){
	int N, M;
	cin >> N >> M;
	vector<int> dis(N + 1);
	vector<bool> seens(N + 1);
	iota(++dis.begin(), dis.end(), 1);
	int a1, a2;
	for(int i = 0; i < M; i++){
		cin >> a1 >> a2;
		join(dis, a1, a2);
	}
	for(auto i: dis){
		cout << i << " " << endl;
	}
	int res = 0;
	for(int i = 1; i<= N; i++){
		if(!seens[dis[i]]){
			res++;
			seens[dis[i]] = true;
		}
	}
	cout << res << endl;

}
