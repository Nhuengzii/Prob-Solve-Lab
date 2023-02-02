#include <iostream>
#include <list>

using namespace std;
typedef list<int> vv;
void shift(vv &data){
  int first, last;
  first = data.front();
  last = data.back();
  data.erase(--data.end());
  data.push_front(last);
}
int main(void){
  int N;
  cin >> N;

  vv dishes;
  int t1;
  for(int i = 0; i < N; i++){
    cin >> t1;
    dishes.push_back(--t1);
  }
  // process;
  int maxSmile = -1;
  int cur = 0;
  int x = 0;
  for(int i = 0; i <= N;i++){
    cur = 0;
    x = 0;
    for(auto j: dishes){
      if (j == x){
        cur++;
      }
      x++;
    }
    shift(dishes);
    
    if(cur > maxSmile){
      maxSmile = cur;
    }
  }
  cout << maxSmile << endl;


  
}
