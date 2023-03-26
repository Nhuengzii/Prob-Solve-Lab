#include <iostream>
#include <vector>




using namespace std;
vector<char> text;
int main(void){
  string name;
  cin >> name;
  char c;
  int res = 0, cur = 0;
  while(true){
    c = getchar();
    if (c == EOF){
      break;
    }
    if(c == name[cur] ){
      cur++; 
    }
    if(cur >= name.length()){
      cur = 0;
      res++;
    }
    
  }
  cout << res << endl;
  

  return 0;
}
