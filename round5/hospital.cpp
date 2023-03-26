#include <iostream>
#include <vector>
#include <queue>
using namespace std;



typedef pair<int, int> yay;
typedef vector<vector<int>> graph;
int getCount(graph &data, int start, int h){
  vector<bool> seen(data.size());
  vector<int> layers(seen.size());
  queue<int> q;
  q.push(start);
  layers[start] = 0;    
  seen[start] = true;
  int c;
  while(! q.empty()){
    c = q.front();
    q.pop();

    for(auto t: data[c]){
      if (seen[t]){
        continue;
      }
      int lay = layers[c] + 1;
      if(lay > h){
        continue;
      }
      else{
        layers[t] = lay;
        seen[t] = true;
        q.push(t);
      }
    }
 }    
  int res = 0;
  for(int i = 1 ;i <= seen.size(); i++){
    if(seen[i]) res++;
  }
  return res;
 
}
int main(void){
  int N, M, H;
  cin >> N >> M >> H;
  graph data(N + 1);
  int a1, a2;
  for(int i = 1; i <= M; i++){
    cin >> a1 >> a2;
    data[a1].push_back(a2);
    data[a2].push_back(a1);
  }
  int max = -1;
  int temp;
  for(int i = 1; i < data.size(); i++){
    temp = getCount(data, i, H);
    if(temp > max){
      max = temp;
    }
  }
  cout << max << endl;
  

  

  return 0;
}