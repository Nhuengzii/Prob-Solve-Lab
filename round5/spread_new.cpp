#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef pair<int, int> yay; // current, threshold
typedef pair<yay, yay> yee;
#define mkk(a1, a2, a3, a4) make_pair(make_pair(a1, a2), make_pair(a2, a3))

void join(vector<int> &s, int a, int b){
  int root = b;
  while(true){
    if(root == s[root]){
      break;
    }
    else{
      root = s[root];
    }
  }
  s[b] = a;
}

bool isJoin(vector<int> &s, int a, int b){
  int ra = a, rb = b;
  while(!((ra == s[ra]) && (rb == s[rb]))){
    ra = s[ra];
    rb = s[rb];
  }
  return ra == rb;
}

int main(void){
  int N, M;
  cin >> N >> M;
  vector<int> data(N + 1);
  vector<yee> edges;
  vector<int> disjoint(N + 1);
  int a1, a2, a3;
  for(int i = 1; i<= N; i++){
    cin >> a1;
    disjoint[i] = i;
    data[i] = a1;
  }
  for(int i = 0; i< M; i++){
    cin >> a1 >> a2 >> a3;
    edges.push_back(mkk(a1, a2, 0, a3));
  }

  int res = 0;
  int ra, rb;
  int joinOnce = false;
  vector<vector<yee>::iterator> d;
  while(true){
    res++;
    joinOnce = false;
    for(auto i = edges.begin(); i != edges.end(); i++){
      auto e = *i;
      ra = e.first.first;
      rb = e.first.second;
      e.second.first += data[ra] + data[rb];
      if(e.second.first >= e.second.second){
        if(!isJoin(disjoint, ra, rb)){
          joinOnce = true;
          join(disjoint, ra, rb);
        }
        d.push_back(i);
      }
    }
    if(!joinOnce){
      break;
    }
    for(auto i: d){
      edges.erase(i);
    }
    
  }
  cout << res << endl;
  

  
}
