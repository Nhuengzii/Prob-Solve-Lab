#include <iostream>
#include <list>

using namespace std;
int main(void){

  list<int> a = { 1 , 3 ,4, 6};
  auto aa = a.begin();
  a.push_back(9);
  a.push_back(293);
  a.push_back(23939);
  for(int i = 0; i < 20; i++){
    cout << *aa << endl;
    aa++;
  }



  
}