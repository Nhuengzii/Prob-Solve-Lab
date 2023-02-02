#include <iostream>
#include <list>
using namespace std;

typedef list<list<int>> ll;

 void show_lines(ll &data){
  for(auto i: data){
    for(auto j: i){
      cout << " " << j;
    }
    cout << endl;
  }
}

int main(void){
  int L, N;
  cin >> L >> N;
  ll datas(L);
  auto lit = datas.begin(); 
  int nr = 1, nc = 1,  temp;
  cin >> temp;
  nr += temp;
  int round_cin = 1;
  while(true){
    if(lit == datas.end()){break;}
    if(nc < nr){
      lit->push_back(nc++);
    }
    else{
      if(round_cin <= 3){
        cin >> temp;
        round_cin++;
      }
      nr += temp;
      lit++;
    }
  }
  list<int>::iterator l;
  lit = datas.begin();
  l = lit->begin();
  char command;
  for(int i = 0; i< N; i++){
    cin >> command;
    if(command == 'B'){
      if(*l != *lit->begin()){
        l--;
      }
    }
    else if(command == 'F'){
      if(*l != *(--lit->end())){
        l++;
      }
    }
    else if(command == 'C'){
      int args; 
      cin >> args;
      auto cp = lit;
      cp++;
      for(auto cpp = cp; cpp != datas.end(); cpp++){
        if(*cpp->begin() == args){
          cp = cpp;
          break;
        }
        else if(*(--cpp->end()) == args){
          cp = cpp;
          cp->reverse();
          break;
        }
      }
      list<int> n;
      if( *l != *(--lit->end())){
        auto tit = l;
        n.splice(n.begin(), *lit, ++tit, lit->end());
        datas.push_back(n);
      }
      lit->splice(lit->end(), *cp);
      datas.erase(cp);
      l++;
    }
    cout << *l << endl;
  }
  return 0;
}
