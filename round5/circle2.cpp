#include <iostream>
#include <vector>
#include <list>

using namespace std;
typedef list<int> li;

void shift(list<li> &data){
	li last;
	last = data.back();
	data.erase(--data.end());
	data.push_front(last);
}
void merge(list<li> &data){
	li start = *data.begin();
	li next = *(++data.begin());
	for(auto i: start){
		next.push_back(i);
	}
	data.erase(data.begin());
	data.erase(data.begin());
	data.push_front(next);
}

int main(void){
	int N;
	cin >> N;
	int t1, t2, t3;
	int last = -1;
	li temp;
	list<li> data;
	for(int i = 0; i < N; i++){
		cin >> t1;
		if(temp.size() == 0){
			temp.push_back(t1);
		}
		else if(t1 > last){
			temp.push_back(t1);
		}
		else{
			data.push_back(temp);
			temp.clear();
			temp.push_back(t1);
		}
		last = t1;
	}
	data.push_back(temp);
	temp.clear();
	for(int i = 0; i < data.size(); i++){
		if(data.size() == 1){
			cout << data.begin()->size() << endl;
			return 0;
		}
		for(int i = 0; i < data.size() - 1; i++){
			auto left = data.begin();
			advance(left, i);
			int lr, rl;
			lr = left->back();
			left++;
			rl = left->front();
			if(rl - lr == 1){
				merge(data);
			}
		}
		if(data.size() == 1){
			cout << data.begin()->size() << endl;
			return 0;
		}
		shift(data);
	}
	int res = -1;
	int s;
	for(auto i: data){
		s = (int)i.size();
		if(s > res){
			res = i.size();
		}
	}
	cout << res << endl;
	return 0;
	
}