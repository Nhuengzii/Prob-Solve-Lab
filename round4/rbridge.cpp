#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> nc;
typedef vector<vector<nc>> yay;

int bfs(yay &data, int s, int t, int color){
	queue<int> q;
	vector<bool> seen(data.size());
	vector<int> layers(data.size());
	seen[s] = true;
	q.push(s);
	layers[s] = 0;
	int u, v;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(auto i: data[u]){
			if(seen[i.first]){
				continue;
			}
			if(i.second + color == 3){
				continue;
			}
			if(i.first == t){
				return layers[u] + 1;
			}
			q.push(i.first);
			seen[i.first] = true;
			layers[i.first] = layers[u] + 1;
		}
	}
	return -1;
}

int main(void){
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	yay data(N + 1);
	int a1, a2, a3;
	for(int i = 1; i <= M; i++){
		cin >> a1 >> a2 >> a3;
		data[a1].push_back(make_pair(a2, a3));
		data[a2].push_back(make_pair(a1, a3));
	}
	int red = bfs(data, S, T, 1);
	int blue = bfs(data, S, T, 2);
	if(red > blue){
		cout << blue << endl;
		return 0;
	}
	else{
		cout << blue << endl;
		return 0;
	}
}
