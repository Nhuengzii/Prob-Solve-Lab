#include <iostream>
#include <vector>
using namespace std;


typedef pair<int, int> yay; // current, threshold
typedef pair<int, yay> yee;
typedef vector<vector<yee>> graph;
#define mkk(a1, a2, a3) make_pair(a1, make_pair(a2, a3))


int main(void){
	int N, M;
	cin >> N >> M;
	graph data(N + 1);
	vector<int> sheet(N + 1);
	int a1, a2, a3;
	for(int i = 0; i < N; i++){
		cin >> a1;
		sheet[i + 1] = a1;
	}
	for(int i = 0; i < M; i++){
		cin >> a1 >> a2 >> a3;
		data[a1].push_back(mkk(a2, 0, a3));
		data[a2].push_back(mkk(a1, 0, a3));
	}
}

