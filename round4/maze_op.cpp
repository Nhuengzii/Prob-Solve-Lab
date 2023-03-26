#include <iostream>
#include <vector>

using namespace std;
typedef vector<string> board;
typedef vector<vector<bool>> bool_board;

bool solve(board &data, bool_board visit, int r, int c, int a, int b, bool key){
	if(r == a && c == b){
		return true;
	}
	if(r < 0 || r >= data.size()){
		return false;
	}
	if(c < 0 || c >= data[0].size()){
		return false;
	}
	if(visit[r][c]){
		return false;
	}
	
	if(data[r][c] == '#'){
		return false;
	}
	if(data[r][c] == 'O'){
		if(key){
			key = false;
		}
		else{
			return false;
		}
	}
	visit[r][c] = true;
	return solve(data, visit, r - 1, c, a, b, key) || solve(data, visit, r + 1, c, a, b, key) || \
					solve(data, visit, r , c - 1, a, b, key) || solve(data, visit, r, c + 1, a, b, key);
}


int main(void){
	int N, Q;
	cin >> N >> Q;
	board data(N);
	bool_board visit;
	for(int i = 0; i < N; i++){
		cin >> data[i];
		visit.push_back(vector<bool> (N));
	}
	int r, c, a, b;
	for(auto i = 0; i < Q; i++){
		cin >> r >> c >> a >> b;
		r--;
		c--;
		a--;
		b--;
		if(solve(data, visit, r, c, a, b, true)){
			cout << "yes" <<endl;
		}
		else{
			cout << "no" <<endl;
		}
	}


	
}