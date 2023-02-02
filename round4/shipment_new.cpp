#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;
typedef vector<vector<int>> graph;
map<int, int> factory;
map<int, bool> storage;

void factoryToStorage(graph &data, int start){
  queue<int> q;
  q.push(start);
  vector<bool> seens(data.size());
  vector<int> layers(data.size());
  layers[start] = 0;
  seens[start] = true;
  int c = 0;
  if(storage.find(start) != storage.end()){
    cout << 0 << endl;
    return;
  }
  while(!q.empty()){
    c = q.front();
    q.pop();
    for(auto i: data[c]){
      if(seens[i]){
        continue;
      }
      if(storage.find(i) != storage.end()){
        cout << layers[c] + 1 << endl;
        return;
      }
      else{
        layers[i] = layers[c] + 1;
        seens[i] = true;
        q.push(i);
      }
    }
  }
}

void storageToFactory(graph &data, int start){
  queue<int> q;
  vector<int> layers(data.size());
  vector<bool> seens(data.size());
  q.push(start);
  layers[start] = 0;
  seens[start] = true;
  if(factory.find(start) != factory.end()){
    factory[start] = 0;
  } 
  int c;
  while(!q.empty()){
    c = q.front();
    q.pop();
    for(auto i: data[c]){
      if(seens[i]){
        continue;
      }
      layers[i] = layers[c] + 1;
      if(factory.find(i) != factory.end()){
        if(layers[i] < factory[i]){
          factory[i] = layers[i];
        }
      }
      q.push(i);
      seens[i] = true;
    }
  }
  
}


int main(void){
  int N, M, S, T;
  cin >> N >> M >> S >> T;
  graph data(N + 1);
  int a1, a2;
  for(int i = 0;i < M; i++){
    cin >> a1 >> a2;
    data[a1].push_back(a2);
    data[a2].push_back(a1);
  }
  for(int i = 0; i < S; i++){
    cin >> a1;
    storage[a1] = true;
  }
  for(int i = 0; i< T; i++){
    cin >> a1;
    factory[a1] = 999;
  }
  if(T > S){
    for(auto i: storage){
      storageToFactory(data, i.first);
    }
    for(auto i: factory){
      cout << i.second << endl;
    }
  }
  else{
    for(auto i: factory){
      factoryToStorage(data, i.first);
    }
  }
}