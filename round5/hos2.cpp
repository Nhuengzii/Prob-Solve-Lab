#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> graph;

void bfs(graph &data, vector<bool> &isVisit, int start, int limit){
	queue<int> q;
	vector<bool> seen( data.size());
	vector<int> layers(data.size());
	q.push(start);
	layers[start] = 0;	
	seen[start] = true;
	isVisit[start] = true;
	int c, t;
	while(!q.empty()){
		c = q.front();
		q.pop();
		for(auto u: data[c]){
			if(seen[u]){
				continue;
			}
			if(layers[c] == limit){
				continue;
			}
			else{
				layers[u] = layers[c] + 1;
				seen[u] = true;
				isVisit[u] = true;
				q.push(u);
			}
		}
	}

	
}

int N, M, K, H;
int main(void){
	cin >> N >> M >> K >> H;
	vector<int> hos1;
	vector<int> hos2;
	vector<bool> isVisit(N + 1, false);
	graph data(N + 1);
	int t1, t2, t3;
	for(int i = 0; i < K; i++){
		cin >> t1;
		hos1.push_back(t1);
	}
	for(int i = 0; i < K; i++){
		cin >> t1;
		hos2.push_back(t1);
	}

	for(int i = 0; i< M; i++){
		cin >> t1 >> t2;
		data[t1].push_back(t2);
		data[t2].push_back(t1);
	}

	for(int i = 0; i < K; i++){
		isVisit[hos1[i]] = true;
		if(hos2[i] == 1){
			bfs(data, isVisit, hos1[i], H * 2);
		}
		else{
			bfs(data, isVisit, hos1[i], H );
		}
	}

	queue<int> q;
	int res = 0;
	for(auto i: isVisit){
		if(i){
			res++;
		}
	}
	cout << res << endl;


	
}