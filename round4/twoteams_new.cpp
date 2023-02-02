#include <iostream>
#include <map>


using namespace std;

int find(map<int, int> &dis, int s){
	if(dis[s] == s){
		return s;
	}
	else{
		return find(dis, dis[s]);
	}
}
void compress(map<int, int> &dis, int s, int t){
	int t1 = dis[s];
	if(t1 == t){
		return;
	}
	dis[s] = t;
	compress(dis, t1, t);
}

void join(map<int, int> &dis, int s, int t){
	int rs = find(dis, s);
	int rt = find(dis, t);
	dis[rs] = rt;
	compress(dis, s, rt);
	compress(dis, t, rt);
}




int main(void){
	int N , M;
	cin >> N >> M;
	map<int, int> dis;
	for(int i = 1; i <= N; i++){
		dis[i] = i;
	}
	int t1, t2;
	for(int i = 0; i < M; i++){
		cin >> t1 >> t2;
		join(dis, t1, t2);
	}
	map<int, int> r;
	for(auto i: dis){
		if(r.find(i.second) != r.end()){
			r[i.second]++;
		}
		else{
			r[i.second] = 1;
		}
	}
	map<int, int> res;
	for(auto i: r){
		if(res.find(i.second) == res.end()){
			res[i.second] = 1;
		}
	}
	cout << res.size() << endl;



	
}
