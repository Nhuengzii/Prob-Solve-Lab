#include <iostream>
#include <list>
#include <vector>

using namespace std;
typedef pair<int,int> yay;
typedef pair<yay, yay> yee;
#define mkk(a1, a2, a3, a4) make_pair(make_pair(a1, a2), make_pair(a3, a4))


int main(void){
  int N, M;
  cin >> N >> M;
  vector<int> dataSheet(N + 1);
  int t1, t2, t3;
  for(int i = 1; i <= N; i++){
    cin >> t1;
    dataSheet[i] = t1;
  }
  list<yee> edges;
  for(int i = 0 ; i < M; i++){
    cin >> t1 >> t2 >> t3;
    edges.push_back(mkk(t1, t2, t3, 0));
  }
  int t = 0;
  yee current;
  int r, l;
  vector<list<yee>::iterator> del;
  
  while(true){
    t++;
    for(auto i = edges.begin(); i != edges.end(); i++){
      r = dataSheet[i->first.first];
      l = dataSheet[i->first.second];
      i->second.second += r + l;
      if(i->second.first <= i->second.second){
        del.push_back(i);
      }
    }
    for(auto k: del){
      edges.erase(k);
    }
    del.clear();
    if(edges.size() == 0){
      cout << t << endl;
      return 0; 
    }
  }

  
}
