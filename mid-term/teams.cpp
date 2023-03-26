#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> graph;

bool bib(graph &data, vector<int> deg, int K){
	queue<int> q;
	vector<int> teams(data.size());
	int t= 1;
	for(int x = 1 ; x < deg.size() ;x++){
		if(deg[x] >= K){
			continue;
		}
		if(teams[x] != 0){
			continue;
		}
		teams[x] = 1;
		q.push(x);
		int c;
		while(!q.empty()){
			c = q.front();
			q.pop();
			for(auto i: data[c]){
				if(deg[i] >= K){
					continue;
				}
				if(teams[i] == 0){
					teams[i] = -1 * teams[c];
					q.push(i);
				}
				else{
					if(teams[i] == teams[c]){
						if(deg[i] < K && deg[c] < K){
							return false;
						}
					}
				}
			}
		}
	}
	return true;
	
}


int main(void){
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> degree(N + 1);
	graph data(N + 1);
	int a1, a2;
	for(int i = 0; i < M; i++){
		cin >> a1 >> a2;
		degree[a1]++;
		degree[a2]++;
		data[a1].push_back(a2);
		data[a2].push_back(a1);
	}
	if(bib(data, degree, K)){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
}
