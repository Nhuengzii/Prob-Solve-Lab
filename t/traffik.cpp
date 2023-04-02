#include "traffic.h"
#include <iostream>
#include <vector>

using namespace std;


int binary_search(int ind,int left, int right, int isHorizontal) {
    int mid;
    int tmp;
    while (right > left) {
        mid = (left+right)/2;
        if (right - left == 1) return left;
        if (!isHorizontal) { //check vertical
            tmp = traffic_query(ind,left,ind,mid);
            if ( tmp != mid-left)  //target is there
                right = mid;
            
            else 
                left = mid;
            
        }
        else {//check horizontal
            tmp = traffic_query(left,ind,mid,ind);
            if (tmp != mid-left) //target is there
                right = mid;
            
            else 
                left = mid;
            
        }
    }
    return left;
}
int main() {
    vector<int> result(8, 0);
    vector<int> eiei(7, 0);
    traffic_init(&eiei[1], &eiei[2]);
    int i = 1;
    while(i <= eiei[1]){        
        eiei[3] = traffic_query(i,1,i,eiei[1]);
        if (eiei[3] != eiei[1]-1) {
            eiei[4] = 0;
            eiei[6] = i;
            eiei[0] = binary_search(eiei[6],1,eiei[1], eiei[4]);
            if (result[0] != 0) eiei[5]=4;
            result[eiei[5]]= eiei[6]; result[eiei[5]+1] = eiei[0]; result[eiei[5]+2] = eiei[6]; result[eiei[5]+3] = eiei[0]+1;
        }

        eiei[3] = traffic_query(1,i,eiei[1],i); 
        if (eiei[3] != eiei[1]-1) {
            eiei[4] = 1;
            eiei[6] = i;
            eiei[0] = binary_search(eiei[6],1,eiei[1], eiei[4]);
            if (result[0] != 0) eiei[5]=4;
            result[eiei[5]]=eiei[0]; result[eiei[5]+1]=eiei[6]; result[eiei[5]+2]=eiei[0]+1; result[eiei[5]+3]=eiei[6];
        }
        i++;
    }

    
    traffic_report(result[0],result[1],result[2],result[3],
                    result[4],result[5],result[6],result[7]);
}
