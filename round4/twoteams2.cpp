#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> graph;
int a;
bool bfs(graph &data){
	vector<int> teams(data.size());
	queue<int> q;
	q.push(a);
	teams[a] = -1;
	int c;
	while(!q.empty()){
		c = q.front();
		q.pop();
		for(auto i: data[c]){
			if(teams[i] == 0){
				teams[i] = -teams[c];
			}
			else if(teams[i] == teams[c]){
				return false;
			}
			if(teams[i] == 0){
				q.push(i);
			}
		}
	}
	return true;
}

int main(void){
	int N, M;
	cin >> N >> M;
	graph data(N + 1);
	int a1, a2;
	int i;
	a = -1;
	for(i = 0; i < M; i++){
		cin >> a1 >> a2;
		if(a == -1){
			a = a1;
		}
		data[a1].push_back(a2);
		data[a2].push_back(a1);
		if( i < 2){
			continue;
		}
		if(!bfs(data)){break;}
	}
	cout << --i << endl;

	
}

