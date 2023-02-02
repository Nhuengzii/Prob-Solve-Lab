#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
typedef vector<vector<int>> board;
typedef pair<int, int> pos;
int main(void){
	cin >> N >> K;
	board data(N);
	vector<vector<bool>> seen(N );
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int a;
			cin >> a;
			data[i].push_back(a);
			seen[i].push_back(false);
		}
	}
	queue<pos> q;
	q.push(make_pair(0, 0));
	int x, y, h, hh;
	pos c, t;
	seen[0][0] = true;
	while(!q.empty()){
		c = q.front();
		q.pop();
		x = c.first;
		y = c.second;
		h = data[x][y];

		if((x == (N - 1))&& (y == (N - 1))){
			cout << "yes" << endl;
			return 0;
		}
		if(x - 1 >= 0 && !seen[x-1][y]){
			hh = data[x - 1][y];
			if((hh - h) <= K){
				seen[x-1][y] = true;
				q.push(make_pair(x-1, y));
			}
		}
		if(x + 1 < N && !seen[x+1][y]){
			hh = data[x + 1][y];
			if((hh - h) <= K){
				seen[x + 1][y] = true;
				q.push(make_pair(x+1, y));
			}
		}
		if(y - 1 >= 0 && !seen[x][y - 1]){
			hh = data[x][y - 1];
			if((hh - h) <= K){
				seen[x][y - 1] = true;
				q.push(make_pair(x, y - 1));
			}
		}
		if(y + 1 < N && !seen[x][y + 1]){
			hh = data[x][y + 1];
			if((hh - h) <= K){
				seen[x][y + 1] = true;
				q.push(make_pair(x, y + 1));
			}
		}
	}
	cout << "no" << endl;


	
}
