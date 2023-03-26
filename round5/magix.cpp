#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, bool> edg;
typedef vector<vector<edg>> graph;

vector<bool> gobal_visit;
map<int, bool> school;

void dfs(graph &data, vector<bool> visit, int s, bool magik, int h){
	bool isSchool = true;
	gobal_visit[s] = true;
	if(school.find(s) != school.end()){
		magik = true;
	}
	if(h == 0){
		return;
	}
	for(auto i: data[s]){
		if(visit[i.first]){
			continue;
		}
		isSchool = true;
		if(school.find(i.first) == school.end()){
			isSchool = false;
		}
		if(!i.second){
			if(!isSchool){
				visit[s] = true;
			}
			dfs(data, visit, i.first, magik, h - 1);
			visit[s] = false;
		}
		else{
			if(magik){
				visit[s] = true;
				dfs(data, visit, i.first, magik, h - 1);
				visit[s] = false;
			}
		}
	}
}
int main(void){
	int N , M, K, H;
	cin >> N >> M >> K >>H;
	gobal_visit = vector<bool> (N + 1);
	vector<bool> visit(N + 1);
	int a1, a2, a3;
	for(int i = 0; i < K; i++){
		cin >> a1;
		school[a1] = true;
	}
	graph data(N + 1);
	for(int i = 0; i < M ;i++){
		cin >> a1 >> a2 >> a3;
		data[a1].push_back(make_pair(a2, a3));
		data[a2].push_back(make_pair(a1, a3));
	}
	bool magik = true;
	if(school.find(1) == school.end()){
		magik = false;
	}
	dfs(data, visit, 1, magik, H);
	int res = 0;
	int x = 0;
	for(auto i: gobal_visit){
		if(i){
			res++;
		}
	}
	cout << res << endl;
}
