#include <iostream>
#include <vector>
using namespace std;



int main(void){
  int N, M;
  cin >> N >> M;
  int a1, a2;
  vector<int> teams(N + 1);
  int a;
  for(a = 0; a < M; a++){
    cin >> a1 >> a2;
    if(teams[a1] == teams[a2] && teams[a2] != 0){
      break;
    }
    if(teams[a1] == 0 && teams[a2] == 0){
      teams[a1] = 1;
      teams[a2] = -1;
    }
    else{
      if(teams[a1] == 0){
        teams[a1] = -teams[a2];
      }
      else if(teams[a2] == 0){
        teams[a2] = -teams[a1];
      }
    }
  }
  cout << a << endl;
  


  
}
