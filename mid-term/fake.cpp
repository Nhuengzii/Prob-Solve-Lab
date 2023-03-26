#include <iostream>
#include <vector>
using namespace std;
int main(void){
  int N;
  cin >> N;
  long long int sum = 0, t1, t2;
  vector<int> line(N + 1);
  for(int x = 1; x <= N; x++){
    cin >> t1;
    line[x] = t1;
    sum += t1;
  }
  int a1, a2;
  for(int i = 2; i < N; i++){
    a1 = line[i - 1];
    a2 = line[i + 1];
    if(a2 > a1){
      t1 = a2 - a1; 
    }
    else{
      t1 = a2 - 1;
    }
  }
}
