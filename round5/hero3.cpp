#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> yay;
typedef vector<vector<yay>> graph;
int N, M, K, H;
graph datas;
vector<bool> isVisit;
vector<bool> isSchool;
vector<int> layers;
int main(void){
	cin >> N >> M >> K >> H;
	datas = graph (N + 1);
	isVisit = vector<bool> ( N + 1);
	isSchool = vector<bool> (N + 1);
	layers = vector<int> (N + 1);
	int t1, t2, t3;
	if( K == 0){
		getchar();
	}
	else{
		for(int i = 0; i < K; i++){
			cin >> t1;
			isSchool[t1] = true;
		}
	}

	// get graph
	for(int i = 0; i < M; i++){
		cin >> t1 >> t2 >> t3;
		datas[t1].push_back(make_pair(t2, t3));
		datas[t2].push_back(make_pair(t1, t3));
	}
	queue<int> q;
	q.push(1);
	isVisit[1] = true;
	layers[1] = 0;

	// bootstraping
	int c, t;
	while(!q.empty()){
		c = q.front();
		q.pop();
		for(auto i: datas[c]){
			if(i.first == 0){break;}
			t = i.first;
			if(layers[c] == H){
				continue;
			}
			else{
				layers[t] = layers[c] + 1;
				isVisit[t] = true;
				q.push(t);
			}
		}
	}


	// answer
	int res = 0;
	for(int i = 1; i <= N; i++){
		if(isVisit[i]){
			res++;
		}
	}
	cout << res << endl;

}